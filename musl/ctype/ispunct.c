#include <ctype.h>
#include "libc.h"

int ispunct(int c)
{
	return isgraph(c) && !isalnum(c);
}
