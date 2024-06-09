PYTHON = python

all: link_install

build_all:
	# in singularity shell scripts/singularity.sif
	python scripts/build_all.py

clean:
	rm -rf dist/ polycon.egg-info/ 

pip_upload:
	# ${PYTHON} -m pip install twine 
	${PYTHON} -m twine upload --repository pypi --verbose dist/*

link_install:
	${PYTHON} -m pip install -e .
	

.PHONY: all \
	build_all \
	clean \
	pip_upload \
	link_install