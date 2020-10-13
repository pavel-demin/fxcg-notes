prefix=/opt/casio

mkdir -p mkg3a mkg3a-build

curl https://gitlab.com/taricorp/mkg3a/-/archive/master/mkg3a-master.tar.gz | tar -zx --strip-components=1 --directory=mkg3a

cd mkg3a-build
cmake -DCMAKE_INSTALL_PREFIX=$prefix ../mkg3a
make install
cd ..
