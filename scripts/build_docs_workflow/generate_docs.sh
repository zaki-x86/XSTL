echo "Generate doxygen xml for breathe to understand the source code"
doxygen Doxyfile
echo "build the documentation"
cd docs
make html