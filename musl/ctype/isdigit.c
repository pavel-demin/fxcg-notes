#include <ctype.h>
#include "libc.h"
#undef isdigit

int isdigit(int c)
{
	return (unsigned)c-'0' < 10;
}
