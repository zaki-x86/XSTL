wget https://www.doxygen.nl/files/doxygen-$DOXYGEN_VERSION.linux.bin.tar.gz -O doxygen.tar.gz

tar xzf doxygen.tar.gz

mv doxygen-$DOXYGEN_VERSION/bin doxygen

echo $GITHUB_WORKSPACE/doxygen >> $GITHUB_PATH