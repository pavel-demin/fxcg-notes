#include <fxcg/syscalls.h>

_Noreturn void exit(int code)
{
	int key;
	while(1) GetKey(&key);
}
