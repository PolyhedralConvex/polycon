PYTHON = python

all: link_install

# => make all the packages in dist/
# in singularity shell scripts/singularity.sif
build_all:
	python scripts/build_all.py

clean:
	rm -rf dist/ polycon.egg-info/ 

# ${PYTHON} -m pip install twine 
pip_upload:
	${PYTHON} -m twine upload --repository pypi --verbose dist/*

link_install:
	poetry install
	# ${PYTHON} -m pip install -e .
	

.PHONY: all \
	build_all \
	clean \
	pip_upload \
	link_install