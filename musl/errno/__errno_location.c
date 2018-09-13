#include <errno.h>

int errno_val;

int *__errno_location(void)
{
	return &errno_val;
}
