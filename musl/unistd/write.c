#include <unistd.h>
#include <fxcg/syscalls.h>
#include "libc.h"

ssize_t write(int fd, const void *buf, size_t count)
{
	return Bfile_WriteFile_OS(fd, buf, count);
}
