MEMORY
{
  flash       (rx)  : org = 0x08000000, len = 64k
  sysmem      (rx)  : org = 0x1ffff000, len = 2k
  optionbytes (r)   : org = 0x1ffff800, len = 16
  ram         (rwx) : org = 0x20000000, len = 20k
}

SECTIONS
{

/* flash ------------------------------------------------------------------- */

  .vectors ORIGIN(flash) : AT(ORIGIN(flash)) { KEEP(*(.vectors)) }
  __vectors_start__ = LOADADDR(.vectors);
  __vectors_end__   = ALIGN(__vectors_start__ + SIZEOF(.vectors), 4);
  __vectors_size__  = __vectors_end__ - __vectors_start__;

  .text __text_start__ : AT(__vectors_end__) { *(.init*) *(.text*) }
  __text_start__ = LOADADDR(.text);
  __text_end__   = ALIGN(__text_start__ + SIZEOF(.text), 4);
  __text_size__  = __text_end__ - __text_start__;

  .rodata __rodata_start__ : AT(__text_end__) { *(.rodata*) }
  __rodata_start__ = LOADADDR(.rodata);
  __rodata_end__   = ALIGN(__rodata_start__ + SIZEOF(.rodata), 4);
  __rodata_size__  = __rodata_end__ - __rodata_start__;

  .data.load __data_start__ : AT(__rodata_end__) { *(.data*) }
  __data_load_start__ = LOADADDR(.data.load);
  __data_load_end__   = ALIGN(__data_load_start__ + SIZEOF(.data.load), 4);
  __data_load_size__  = __data_load_end__ - __data_load_start__;

  __img_start__       = __vectors_start__;
  __img_end__         = __data_load_end__;
  __img_size__        = __img_end__ - __img_start__;

/* sram -------------------------------------------------------------------- */

  .ram.vectors ORIGIN(ram) (NOLOAD) : AT(ORIGIN(ram)) { . += __vectors_size__; }
  __ram_vectors_start__ = LOADADDR(.ram.vectors);
  __ram_vectors_end__   = ALIGN(__ram_vectors_start__ + SIZEOF(.ram.vectors), 4);
  __ram_vectors_size__  = __ram_vectors_end__ - __ram_vectors_start__;

  .bss __ram_vectors_end__ (NOLOAD) : AT(__ram_vectors_end__) { *(.bss*) }
  __bss_start__ = LOADADDR(.bss);
  __bss_end__   = ALIGN(ADDR(.bss)+SIZEOF(.bss), 4);
  __bss_size__  = __bss_end__ - __bss_start__;

  .data __bss_end__ (NOLOAD) : AT(__bss_end__) { . += __data_load_size__; }
  __data_start__ = LOADADDR(.data);
  __data_end__   = ALIGN(__data_start__ + SIZEOF(.data), 4);
  __data_size__  = __data_end__ - __data_start__;

  .noinit __data_end__ (NOLOAD) : AT(__data_end__) { *(.noinit*) }
  __noinit_start__ = LOADADDR(.noinit);
  __noinit_end__   = ALIGN(__noinit_start__ + SIZEOF(.noinit), 4);
  __noinit_size__  = __noinit_end__ - __noinit_start__;

  .stack __noinit_end__ (NOLOAD) : AT(__noinit_end__) { }
  __stack_start__ = ORIGIN(ram)+LENGTH(ram);
  __stack_end__   = LOADADDR(.stack);
  __stack_size__  = __stack_start__ - __stack_end__;

}