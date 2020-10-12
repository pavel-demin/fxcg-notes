OUTPUT_FORMAT(binary)
OUTPUT_ARCH(sh3)

ENTRY(_initialize)

_rom_data_start = LOADADDR(.data);

MEMORY
{
  rom (rx) : o = 0x00300000, l = 2048k
  ram (wx) : o = 0x08100004, l = 256k
}

SECTIONS
{
  .text : {
    *(.pretext)
    *(.text*)
  } > rom

  .rodata : {
    *(.rodata*)
  } > rom

  .data : {
    _ram_data_start = . ;
    *(.data*)
    _ram_data_end = . ;
  } >ram AT>rom

  .bss : {
    _bss_start = . ;
    *(.bss*)
    *(COMMON)
    _bss_end = . ;
  } >ram
}
