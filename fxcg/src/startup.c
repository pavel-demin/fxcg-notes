#include <syscalls.h>

extern int rom_data_start;
extern int ram_data_start;
extern int ram_data_end;
extern int bss_start;
extern int bss_end;

extern int main();

void initialize()
{
  int *dst, *src;

  // copy .data section to RAM
  dst = &ram_data_start;
  src = &rom_data_start;
  while(dst < &ram_data_end) *dst++ = *src++;

  // fill .bss section with zeros
  dst = &bss_start;
  while(dst < &bss_end) *dst++ = 0;

  // call GlibAddinAplExecutionCheck
  GlibAddinAplExecutionCheck();

  // call main
  main();

  while(1);
}
