#ifndef fxcg_print_h
#define fxcg_print_h

#include <fxcg/defs.h>

#ifdef __cplusplus
extern "C" {
#endif

void print(int x, int y, color_t fg, color_t bg, const char *text);

#ifdef __cplusplus
}
#endif

#endif /* fxcg_print_h */
