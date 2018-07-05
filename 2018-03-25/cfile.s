	.file	"cfile.c"
	.code16gcc
	.intel_syntax noprefix
	.text
/APP
	.code16gcc

/NO_APP
	.globl	myMessage
	.data
	.align 4
	.type	myMessage, @object
	.size	myMessage, 11
myMessage:
	.string	"AaBbCcDdEe"
	.text
	.globl	myUpper
	.type	myUpper, @function
myUpper:
.LFB0:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 16
	mov	DWORD PTR [ebp-4], 0
	jmp	.L2
.L4:
	mov	eax, DWORD PTR [ebp-4]
	add	eax, OFFSET FLAT:myMessage
	mov	al, BYTE PTR [eax]
	cmp	al, 96
	jle	.L3
	mov	eax, DWORD PTR [ebp-4]
	add	eax, OFFSET FLAT:myMessage
	mov	al, BYTE PTR [eax]
	cmp	al, 122
	jg	.L3
	mov	eax, DWORD PTR [ebp-4]
	add	eax, OFFSET FLAT:myMessage
	mov	al, BYTE PTR [eax]
	sub	eax, 32
	mov	dl, al
	mov	eax, DWORD PTR [ebp-4]
	add	eax, OFFSET FLAT:myMessage
	mov	BYTE PTR [eax], dl
.L3:
	inc	DWORD PTR [ebp-4]
.L2:
	cmp	DWORD PTR [ebp-4], 10
	jle	.L4
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	myUpper, .-myUpper
	.ident	"GCC: (GNU) 7.3.0"
