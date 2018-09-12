#include <unistd.h>
#include <fxcg/syscalls.h>
#include "libc.h"

ssize_t read(int fd, void *buf, size_t count)
{
	return Bfile_ReadFile_OS(fd, buf, count, -1);
}
