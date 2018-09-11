version=2.30

jobs=`nproc 2> /dev/null || echo 1`

tar=binutils-${version}.tar.gz
url=ftp://ftp.gnu.org/gnu/binutils/$tar
test -f $tar || curl -L $url -o $tar
tar -zxf $tar

mkdir binutils-${version}-build
cd binutils-${version}-build
../binutils-${version}/configure --target=sh3eb-elf --prefix=/opt/sh3eb-elf \
  --disable-nls --disable-shared --disable-multilib
make -j $jobs
make install
cd ..
