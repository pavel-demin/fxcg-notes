#include <errno.h>
#include <fxcg/syscalls.h>

int close(int fd)
{
	if (fd < 3) {
		errno = EBADF;
		return -1;
	}
	return Bfile_CloseFile_OS(fd - 3);
}
