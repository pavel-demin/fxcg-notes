#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <fxcg/syscalls.h>
#include "libc.h"

int open(const char *filename, int mode, ...)
{
	int fd, rc, size;
	size_t len = strlen(filename);
	unsigned short *buffer = alloca(2 * len + 2);

	if (!buffer) {
		errno = ENOMEM;
		return -1;
	}

	Bfile_StrToName_ncpy(buffer, filename, len + 1);
	fd = Bfile_OpenFile_OS(buffer, mode);

	if (fd >= 0) return fd;

	if((mode == O_WRONLY) || (mode == O_RDWR))
	{
		size = 16;
		rc = Bfile_CreateEntry_OS(buffer, 1, &size);
		switch (rc) {
		case 0:
			return Bfile_OpenFile_OS(buffer, mode);
		case -13:
			errno = EEXIST;
			return -1;
		case -3:
			errno = ENOENT;
			return -1;
		default:
			errno = EIO;
			return -1;
		}
	}
	else
	{
		errno = ENOENT;
		return -1;
	}
}
