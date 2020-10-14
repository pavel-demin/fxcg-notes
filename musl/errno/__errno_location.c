#include <errno.h>

static int errno_val;

int *__errno_location(void)
{
	return &errno_val;
}
