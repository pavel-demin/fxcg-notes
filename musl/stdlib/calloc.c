#include <stdlib.h>
#include <string.h>

void *calloc(size_t num, size_t size)
{
	size_t s;
	void *p;
	if(__builtin_umul_overflow(num, size, &s)) return NULL;
	p = malloc(s);
	if(p) memset(p, 0, s);
	return p;
}
