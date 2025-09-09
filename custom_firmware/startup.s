.section .text.entry
.global _start

_start:
  .option push
  .option norelax
  la gp, __global_pointer$
  .option pop
  li sp, 0x22000
  call main
halt:
  j halt
  
