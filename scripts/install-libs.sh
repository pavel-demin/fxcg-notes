prefix=/opt/casio

install -d $prefix/include
install -d $prefix/include/fxcg
install -d $prefix/include/bits
install -d $prefix/include/sys
install -d $prefix/include/ustl

install -d $prefix/lib

make -C fxcg clean
make -C fxcg
install -m 644 -t $prefix/include/fxcg fxcg/include/*
install -m 644 -t $prefix/lib fxcg/libfxcg.a
install -m 644 -t $prefix fxcg/fxcg.ld

make -C musl clean
make -C musl PREFIX=$prefix
install -m 644 -t $prefix/include musl/include/*
install -m 644 -t $prefix/include/bits musl/include/bits/*
install -m 644 -t $prefix/include/sys musl/include/sys/*
install -m 644 -t $prefix/lib musl/libmusl.a

make -C ustl clean
make -C ustl PREFIX=$prefix
install -m 644 -t $prefix/include/ustl ustl/include/*
install -m 644 -t $prefix/lib ustl/libustl.a

make -C tommath clean
make -C tommath PREFIX=$prefix
install -m 644 -t $prefix/include tommath/include/*
install -m 644 -t $prefix/lib tommath/libtommath.a

make -C dialogs clean
make -C dialogs PREFIX=$prefix
install -m 644 -t $prefix/include dialogs/include/*
install -m 644 -t $prefix/lib dialogs/libdialogs.a
