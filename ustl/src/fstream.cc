// This file is part of the uSTL library, an STL implementation.
//
// Copyright (c) 2005 by Mike Sharov <msharov@users.sourceforge.net>
// This file is free software, distributed under the MIT License.

#include "fstream.h"
#include "uutility.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <fxcg/syscalls.h>

namespace ustl {

/// Default constructor.
fstream::fstream (void) noexcept
: ios_base (),
  m_fd (-1),
  m_Filename ()
{
    exceptions (goodbit);
}

/// Opens \p filename in \p mode.
fstream::fstream (const char* filename, openmode mode)
: ios_base (),
  m_fd (-1),
  m_Filename ()
{
    exceptions (goodbit);
    open (filename, mode);
}

/// Attaches to \p nfd of \p filename.
fstream::fstream (int nfd, const char* filename)
: ios_base (),
  m_fd (-1),
  m_Filename ()
{
    exceptions (goodbit);
    attach (nfd, filename);
}

/// Destructor. Closes if still open, but without throwing.
fstream::~fstream (void) noexcept
{
    clear (goodbit);
    exceptions (goodbit);
    close();
    assert (!(rdstate() & badbit) && "close failed in the destructor! This may lead to loss of user data. Please call close() manually and either enable exceptions or check the badbit.");
}

/// Sets state \p s and throws depending on the exception setting.
void fstream::set_and_throw (iostate s, const char* op)
{
    ios_base::set_and_throw (s);
}

/// Attaches to the given \p nfd.
void fstream::attach (int nfd, const char* filename)
{
    assert (filename && "Don't do that");
    m_Filename = filename;
    clear (goodbit);
    if (nfd < 0)
	set_and_throw (badbit, "open");
    close();
    m_fd = nfd;
}

/// Detaches from the current fd.
void fstream::detach (void) noexcept
{
    m_fd = -1;
    m_Filename.clear();
}

/// Converts openmode bits into libc open flags.
/*static*/ int fstream::om_to_flags (openmode m) noexcept
{
    int flags;
    flags = ((m&(in|out))==(in|out)) ? O_RDWR : ((m&out) ? O_WRONLY : O_RDONLY);
    return (flags);
}

/// \brief Opens \p filename in the given mode.
/// \warning The string at \p filename must exist until the object is closed.
void fstream::open (const char* filename, openmode mode, mode_t perms)
{
    int nfd = ::open (filename, om_to_flags(mode), perms);
    attach (nfd, filename);
}

/// Closes the file and throws on error.
void fstream::close (void)
{
    if (m_fd < 0)
	return;	// already closed
    while (::close(m_fd)) {
	if (errno != EINTR) {
	    set_and_throw (badbit | failbit, "close");
	    break;
	}
    }
    detach();
}

/// Moves the current file position to \p n.
off_t fstream::seek (off_t n, seekdir whence)
{
    off_t p = lseek (m_fd, n, whence);
    if (p < 0)
	set_and_throw (failbit, "seek");
    return (p);
}

/// Returns the current file position.
off_t fstream::pos (void) const noexcept
{
    return (lseek (m_fd, 0, SEEK_CUR));
}

/// Reads \p n bytes into \p p.
off_t fstream::read (void* p, off_t n)
{
    off_t br (0);
    while ((br < n) & good())
	br += readsome (advance (p, br), n - br);
    return (br);
}

/// Reads at most \p n bytes into \p p, stopping when it feels like it.
off_t fstream::readsome (void* p, off_t n)
{
    ssize_t brn;
    do { brn = ::read (m_fd, p, n); } while ((brn < 0) & (errno == EINTR));
    if (brn > 0)
	return (brn);
    else if ((brn < 0) & (errno != EAGAIN))
	set_and_throw (failbit, "read");
    else if (!brn)
 	ios_base::set_and_throw (eofbit | failbit);
    return (0);
}

/// Writes \p n bytes from \p p.
off_t fstream::write (const void* p, off_t n)
{
    off_t btw (n);
    while (btw) {
	const off_t bw (n - btw);
	ssize_t bwn = ::write (m_fd, advance(p,bw), btw);
	if (bwn > 0)
	    btw -= bwn;
	else if (!bwn) {
	    ios_base::set_and_throw (eofbit | failbit);
	    break;
	} else if (errno != EINTR) {
	    if (errno != EAGAIN)
		set_and_throw (failbit, "write");
	    break;
	}
    }
    return (n - btw);
}

/// Returns the file size.
off_t fstream::size (void) const
{
    return Bfile_GetFileSize_OS(m_fd);
}

/// Synchronizes the file's data and status with the disk.
void fstream::sync (void)
{
}

} // namespace ustl
