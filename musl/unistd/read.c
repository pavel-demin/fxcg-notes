#include <errno.h>
#include <fxcg/syscalls.h>
#include "libc.h"

ssize_t read(int fd, void *buf, size_t count)
{
	if (fd < 3) {
		errno = EBADF;
		return -1;
	}
	return Bfile_ReadFile_OS(fd - 3, buf, count, -1);
}
