#ifndef	_FCNTL_H
#define	_FCNTL_H

#ifdef __cplusplus
extern "C" {
#endif

#define O_RDONLY 0
#define O_WRONLY 2
#define O_RDWR   3

int open(const char *, int, ...);

#ifdef __cplusplus
}
#endif

#endif
