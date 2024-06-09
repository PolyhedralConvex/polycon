PYTHON = python

all: link_install

build:
	# sudo apt install python3-venv
	# ${PYTHON} -m pip install hatch twine hatch-cython
	${PYTHON} -m cppimport build
	hatch build

clean:
	# rm -rf ~/.micromamba/envs/*/lib/python*/site-packages/polycon ~/.micromamba/envs/*/lib/python*/site-packages/polycon-*
	rm -rf dist/ polycon.egg-info/ 

pip_upload:
	${PYTHON} -m twine upload --repository pypi --verbose dist/*

link_install:
	${PYTHON} -m pip install -e .


.PHONY: all \
	build \
	clean \
	pip_upload \
	link_install