# Install Corryvreckan:

# Go to home directory:
cd ~

# Clone git repo:
git clone https://gitlab.cern.ch/corryvreckan/corryvreckan.git

# Checkout the correct version:
cd corryvreckan/
git checkout fp_heidelberg

# Install:
mkdir build && cd build
cmake ..
make install -j4

# Add alias for corry to bashrc:
echo "alias corry='~/corryvreckan/bin/corry'" >> ~/.bashrc
exec bash
