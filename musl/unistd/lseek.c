#include <errno.h>
#include <unistd.h>
#include <fxcg/syscalls.h>

off_t lseek(int fd, off_t offset, int whence)
{
	if (fd < 3) {
		errno = EBADF;
		return -1;
	}
	if (whence == SEEK_CUR) {
		offset += Bfile_TellFile_OS(fd - 3);
		return Bfile_SeekFile_OS(fd - 3, offset);
	}
	if (whence == SEEK_SET) {
		return Bfile_SeekFile_OS(fd - 3, offset);
	}
	return -1;
}
