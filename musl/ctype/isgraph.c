#include <ctype.h>
#include "libc.h"
#undef isgraph

int isgraph(int c)
{
	return (unsigned)c-0x21 < 0x5e;
}
