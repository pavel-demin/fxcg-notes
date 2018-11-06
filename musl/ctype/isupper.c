#include <ctype.h>
#include "libc.h"
#undef isupper

int isupper(int c)
{
	return (unsigned)c-'A' < 26;
}
