#include <fxcg/syscalls.h>

_Noreturn void abort(void)
{
	int key;
	while(1) GetKey(&key);
}
