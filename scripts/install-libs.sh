prefix=/opt/casio

install -d $prefix/include
install -d $prefix/include/fxcg
install -d $prefix/include/bits
install -d $prefix/include/sys

install -d $prefix/lib

make -C fxcg clean
make -C fxcg
install -t $prefix/include/fxcg fxcg/include/*.h
install -t $prefix/lib fxcg/libfxcg.a

make -C musl clean
make -C musl
install -t $prefix/include musl/include/*.h
install -t $prefix/include/bits musl/include/bits/*.h
install -t $prefix/include/sys musl/include/sys/*.h
install -t $prefix/lib musl/libmusl.a

make -C ustl clean
make -C ustl
install -t $prefix/include ustl/include/*.h
install -t $prefix/lib ustl/libustl.a

make -C tommath clean
make -C tommath
install -t $prefix/include tommath/include/*.h
install -t $prefix/lib tommath/libtommath.a
