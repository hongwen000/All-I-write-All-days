mac:
	nasm foo.asm  -f elf
	/opt/cross/gcc-jos/bin/i386-jos-elf-gcc -c bar.c -o bar.o
	/opt/cross/gcc-jos/bin/i386-jos-elf-ld -s bar.o foo.o -o foobar
linux:
	nasm foo.asm  -f elf
	gcc -c bar.c -o bar.o
	ld -s bar.o foo.o -o foobar
	
