import subprocess
import glob
import os

class Ctx:
    def __init__( self, version: str ) -> None:
        self.version = version

    def env_name( self ):
        return "polycon_build_" + self.version.replace( '.', '' )
    
    def check_env( self ):
        lst = str( subprocess.check_output( 'micromamba env list', shell = True ), 'utf8' )
        for env in lst.split( "\n" ):
            if self.env_name() in env and os.environ[ 'MAMBA_ROOT_PREFIX' ] in env:
                print( "Env:", env )
                return

        subprocess.check_call( f'micromamba -y create --name { self.env_name() } python={ self.version } numpy twine eigen pybind11', shell = True )
        # self.run( f'test -e ../../ext/cppimport || git clone https://github.com/tbenthompson/cppimport.git ../../ext/cppimport' )
        # self.run( f'pip install -e ../../ext/cppimport' )
        self.run( f'pip install poetry cppimport' )
    
    def run( self, cmd, prep = '' ):
        self.check_env()

        print( cmd )
        subprocess.check_call( f'{ prep }micromamba run -n { self.env_name() } { cmd }', shell = True )

def clean( pattern ):
    for f in glob.glob( pattern, recursive=True ):
        os.remove( f )

# remove the old packages
clean( 'dist/*' )

# matrix
for version in [ '3.8', '3.9', '3.10', '3.11', '3.12' ]:
    # remove the old object files
    for suffix in [ 'so', 'dll', 'dylib' ]:
        clean( '**/*.' + suffix )

    # build
    ctx = Ctx( version )
    for cpp in glob.glob( 'polycon/lib/polycon_bindings_*.cpp' ):
        ctx.run( 'python -m cppimport build ' + cpp ) # , 'CPPIMPORT_RELEASE_MODE=1 '
    ctx.run( 'poetry build' )
