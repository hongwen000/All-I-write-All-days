	.file	1 "sel.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.text
	.align	2
	.globl	selection_sort
	.set	nomips16
	.ent	selection_sort
	.type	selection_sort, @function
selection_sort:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	sw	$5,28($fp)
	sw	$0,0($fp)
	sw	$0,4($fp)
	j	$L2
	nop

$L6:
	lw	$2,4($fp)
	nop
	sw	$2,0($fp)
	lw	$2,4($fp)
	nop
	addiu	$2,$2,1
	sw	$2,8($fp)
	j	$L3
	nop

$L5:
	lw	$2,0($fp)
	nop
	sll	$2,$2,2
	lw	$3,24($fp)
	nop
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,8($fp)
	nop
	sll	$2,$2,2
	lw	$4,24($fp)
	nop
	addu	$2,$4,$2
	lw	$2,0($2)
	nop
	slt	$2,$2,$3
	beq	$2,$0,$L4
	nop

	lw	$2,8($fp)
	nop
	sw	$2,0($fp)
$L4:
	lw	$2,8($fp)
	nop
	addiu	$2,$2,1
	sw	$2,8($fp)
$L3:
	lw	$3,8($fp)
	lw	$2,28($fp)
	nop
	slt	$2,$3,$2
	bne	$2,$0,$L5
	nop

	lw	$2,0($fp)
	nop
	sll	$2,$2,2
	lw	$3,24($fp)
	nop
	addu	$2,$3,$2
	lw	$2,0($2)
	nop
	sw	$2,12($fp)
	lw	$2,0($fp)
	nop
	sll	$2,$2,2
	lw	$3,24($fp)
	nop
	addu	$2,$3,$2
	lw	$3,4($fp)
	nop
	sll	$3,$3,2
	lw	$4,24($fp)
	nop
	addu	$3,$4,$3
	lw	$3,0($3)
	nop
	sw	$3,0($2)
	lw	$2,4($fp)
	nop
	sll	$2,$2,2
	lw	$3,24($fp)
	nop
	addu	$2,$3,$2
	lw	$3,12($fp)
	nop
	sw	$3,0($2)
	lw	$2,4($fp)
	nop
	addiu	$2,$2,1
	sw	$2,4($fp)
$L2:
	lw	$2,28($fp)
	nop
	addiu	$3,$2,-1
	lw	$2,4($fp)
	nop
	slt	$2,$2,$3
	bne	$2,$0,$L6
	nop

	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	selection_sort
	.size	selection_sort, .-selection_sort
	.ident	"GCC: (GNU) 4.8.2"
