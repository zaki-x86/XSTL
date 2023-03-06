sudo apt-get update
if [ -f requirements.txt ]; then pip install -r requirements.txt; fi
pip install sphinx sphinx-rtd-theme breathe myst_parser breathe sphinx_design pydata-sphinx-theme