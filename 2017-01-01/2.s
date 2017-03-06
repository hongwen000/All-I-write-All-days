	.file	"undefined.cpp"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d "
	.text
	.p2align 4,,15
	.globl	_Z3fooPPi
	.type	_Z3fooPPi, @function
_Z3fooPPi:
.LFB30:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	leal	12(%esp), %edx
	movl	$11, 12(%esp)
	subl	$4, %esp
	.cfi_def_cfa_offset 36
	movl	%edx, (%eax)
	pushl	$11
	.cfi_def_cfa_offset 40
	pushl	$.LC0
	.cfi_def_cfa_offset 44
	pushl	$1
	.cfi_def_cfa_offset 48
	call	__printf_chk
	addl	$44, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE30:
	.size	_Z3fooPPi, .-_Z3fooPPi
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB31:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	xorl	%ebx, %ebx
	subl	$4, %esp
	pushl	$11
	pushl	$.LC0
	pushl	$1
	call	__printf_chk
	addl	$12, %esp
	pushl	%ebx
	pushl	$.LC0
	pushl	$1
	call	__printf_chk
	addl	$12, %esp
	pushl	%ebx
	pushl	$.LC0
	pushl	$1
	call	__printf_chk
	addl	$16, %esp
	leal	-8(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE31:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 6.2.0-3ubuntu11~14.04) 6.2.0 20160901"
	.section	.note.GNU-stack,"",@progbits
