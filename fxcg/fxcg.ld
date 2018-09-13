OUTPUT_FORMAT(binary)
OUTPUT_ARCH(sh3)

ENTRY(initialize)

MEMORY
{
  rom (rx) : o = 0x00300000, l = 2048k
  ram (rwx) : o = 0x08100004, l = 256k
}

SECTIONS
{
  .text : {
    *(.pretext)
    *(.text)
    *(.text.*)
  } > rom

  .rodata : {
    *(.rodata)
    *(.rodata.*)
  } > rom

  .data : {
    _datald = LOADADDR(.data) ;
    _sdata = . ;
    *(.data)
    *(.data.*)
    _edata = . ;
  } >ram AT>rom

  .bss : {
    _bbss = . ;
    *(.bss)
    *(.bss*)
    *(COMMON)
    _ebss = . ;
  } >ram
}
