#include <ctype.h>
#include "libc.h"

int isblank(int c)
{
	return (c == ' ' || c == '\t');
}
