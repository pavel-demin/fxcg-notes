#include <ctype.h>
#include "libc.h"
#undef isprint

int isprint(int c)
{
	return (unsigned)c-0x20 < 0x5f;
}
