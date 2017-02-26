	.file	"undefined.cpp"
	.section	.rodata
.LC0:
	.string	"%d "
	.text
	.globl	_Z3fooPPi
	.type	_Z3fooPPi, @function
_Z3fooPPi:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$11, -12(%ebp)
	movl	8(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3fooPPi, .-_Z3fooPPi
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$20, %esp
	movl	$10, -16(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	subl	$12, %esp
	leal	-12(%ebp), %eax
	pushl	%eax
	call	_Z3fooPPi
	addl	$16, %esp
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 6.2.0-3ubuntu11~14.04) 6.2.0 20160901"
	.section	.note.GNU-stack,"",@progbits
