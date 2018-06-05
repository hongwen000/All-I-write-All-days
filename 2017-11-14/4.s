	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
                                        ## Start of file scope inline assembly
	.code16

                                        ## End of file scope inline assembly
	.globl	_test
	.p2align	4, 0x90
_test:                                  ## @test
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, -8(%ebp)
	addl	$8, %esp
	popl	%ebp
	retl


.subsections_via_symbols
