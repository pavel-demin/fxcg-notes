#include <ctype.h>
#include "libc.h"
#undef isspace

int isspace(int c)
{
	return c == ' ' || (unsigned)c-'\t' < 5;
}
