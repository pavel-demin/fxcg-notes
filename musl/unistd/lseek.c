#include <unistd.h>
#include <fxcg/syscalls.h>

off_t lseek(int fd, off_t offset, int whence)
{
	if (whence == SEEK_CUR) return Bfile_TellFile_OS(fd);
	if (whence == SEEK_SET) return Bfile_SeekFile_OS(fd, offset);
	return -1;
}
