ENTRY(_start)

MEMORY
{
  RAM (rwx) : ORIGIN = 0x12000, LENGTH = 128K
}

SECTIONS
{
  .text :
  {
    KEEP(*(.text.entry))
    *(.text .text.*)
    *(.rodata .rodata.*)
  } > RAM
  . = ALIGN(4);
  .sdata :
  {
    . = ALIGN(8);
    __global_pointer$ = . + 0x10000;
    *(.srodata.cst4)
    *(.srodata.cst8)
    *(.sdata .sdata.*)
    *(.sdata2 .sdata2.*)
  } > RAM
  .data :
  {
    . = ALIGN(4);
    *(.data .data.*)
  } > RAM
  .bss :
  {
    . = ALIGN(4);
    __bss_start__ = .;
    *(.sbss .sbss.*)
    *(.bss .bss.*)
    __bss_end__ = .;
  } > RAM
}
