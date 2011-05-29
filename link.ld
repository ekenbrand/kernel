OUTPUT_ARCH(i386)
ENTRY(start)
phys = 0x100000;
SECTIONS
{
  .text phys : AT(phys) {
    	code = .; _code = .; __code = .;
    	*(.text)
   	 . = ALIGN(4K);	/*Alinea la memoria a multiplos de 4kb*/
  }
  .data :
  {
    	data = .; _data = .; __data = .;
    	*(.data)
    	*(.rodata)
    .	 = ALIGN(4K);
  }
  .bss :
  {
	bss = .; _bss = .; __bss = .;
	*(.bss)
	. = ALIGN(4K);
  }
	end = .; _end = .; __end = .;
}