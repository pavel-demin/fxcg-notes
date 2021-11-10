#include <stdlib.h>
#include <fxcg/print.h>
#include <fxcg/syscalls.h>

_Noreturn void __assert_fail(const char *expr, const char *file, int line, const char *func)
{
	Bdisp_AllClr_VRAM();
	print(0, 120, COLOR_BLACK, COLOR_WHITE, "assertion failed:");
	print(0, 136, COLOR_BLACK, COLOR_WHITE, file);
	print(0, 152, COLOR_BLACK, COLOR_WHITE, func);
	print(0, 168, COLOR_BLACK, COLOR_WHITE, expr);
	abort();
}
