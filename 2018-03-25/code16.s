	.file	"code16.c"
	.code16gcc
	.intel_syntax noprefix
	.text
/APP
	.code16gcc

/NO_APP
	.globl	c_func
	.type	c_func, @function
c_func:
.LFB0:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 8
	sub	esp, 8
	push	DWORD PTR [ebp+12]
	push	DWORD PTR [ebp+8]
	call	asm_func
	add	esp, 16
	mov	eax, 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	c_func, .-c_func
	.globl	c_start
	.type	c_start, @function
c_start:
.LFB1:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 8
	sub	esp, 8
	push	DWORD PTR [ebp+12]
	push	DWORD PTR [ebp+8]
	call	c_func
	add	esp, 16
	mov	eax, 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	c_start, .-c_start
	.ident	"GCC: (GNU) 7.3.0"
