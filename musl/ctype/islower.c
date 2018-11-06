#include <ctype.h>
#include "libc.h"
#undef islower

int islower(int c)
{
	return (unsigned)c-'a' < 26;
}
