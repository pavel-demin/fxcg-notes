version=11.2.0

prefix=/opt/sh3eb-elf

jobs=`nproc 2> /dev/null || echo 1`

tar=gcc-${version}.tar.gz
url=ftp://ftp.gnu.org/gnu/gcc/gcc-${version}/$tar
test -f $tar || curl -L $url -o $tar
tar -zxf $tar

cd gcc-${version}
./contrib/download_prerequisites
cd ..

mkdir gcc-${version}-build
cd gcc-${version}-build
../gcc-${version}/configure --target=sh3eb-elf --prefix=$prefix \
  --enable-languages=c,c++ \
  --with-newlib --without-headers --disable-hosted-libstdcxx \
  --disable-nls --disable-shared --disable-multilib
make -j $jobs all-gcc all-target-libgcc
make install-gcc install-target-libgcc
cd ..
