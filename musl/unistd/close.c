#include <fxcg/syscalls.h>

int close(int fd)
{
	return Bfile_CloseFile_OS(fd);
}
