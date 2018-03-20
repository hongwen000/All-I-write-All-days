	.file	1 "sort.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.rdata
	.align	2
$LC0:
	.ascii	"%d\000"
	.align	2
$LC1:
	.ascii	"%d\012\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.ent	main
	.type	main, @function
main:
	.frame	$fp,88,$31		# vars= 64, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-88
	sw	$31,84($sp)
	sw	$fp,80($sp)
	move	$fp,$sp
	sw	$0,16($fp)
	j	$L2
	nop

$L3:
	lw	$2,16($fp)
	nop
	sll	$2,$2,2
	addiu	$3,$fp,36
	addu	$2,$3,$2
	lui	$3,%hi($LC0)
	addiu	$4,$3,%lo($LC0)
	move	$5,$2
	jal	scanf
	nop

	lw	$2,16($fp)
	nop
	addiu	$2,$2,1
	sw	$2,16($fp)
$L2:
	lw	$2,16($fp)
	nop
	slt	$2,$2,10
	bne	$2,$0,$L3
	nop

	sw	$0,20($fp)
	j	$L4
	nop

$L8:
	sw	$0,24($fp)
	j	$L5
	nop

$L7:
	lw	$2,24($fp)
	nop
	sll	$2,$2,2
	addiu	$3,$fp,16
	addu	$2,$3,$2
	lw	$3,20($2)
	lw	$2,24($fp)
	nop
	addiu	$2,$2,1
	sll	$2,$2,2
	addiu	$4,$fp,16
	addu	$2,$4,$2
	lw	$2,20($2)
	nop
	slt	$2,$2,$3
	beq	$2,$0,$L6
	nop

	lw	$2,20($fp)
	nop
	sll	$2,$2,2
	addiu	$3,$fp,16
	addu	$2,$3,$2
	lw	$2,20($2)
	nop
	sw	$2,32($fp)
	lw	$2,20($fp)
	nop
	addiu	$2,$2,1
	sll	$2,$2,2
	addiu	$3,$fp,16
	addu	$2,$3,$2
	lw	$3,20($2)
	lw	$2,20($fp)
	nop
	sll	$2,$2,2
	addiu	$4,$fp,16
	addu	$2,$4,$2
	sw	$3,20($2)
	lw	$2,20($fp)
	nop
	addiu	$2,$2,1
	sll	$2,$2,2
	addiu	$3,$fp,16
	addu	$2,$3,$2
	lw	$3,32($fp)
	nop
	sw	$3,20($2)
$L6:
	lw	$2,24($fp)
	nop
	addiu	$2,$2,1
	sw	$2,24($fp)
$L5:
	li	$3,10			# 0xa
	lw	$2,24($fp)
	nop
	subu	$3,$3,$2
	lw	$2,24($fp)
	nop
	slt	$2,$2,$3
	bne	$2,$0,$L7
	nop

	lw	$2,20($fp)
	nop
	addiu	$2,$2,1
	sw	$2,20($fp)
$L4:
	lw	$2,20($fp)
	nop
	slt	$2,$2,10
	bne	$2,$0,$L8
	nop

	sw	$0,28($fp)
	j	$L9
	nop

$L10:
	lw	$2,28($fp)
	nop
	sll	$2,$2,2
	addiu	$3,$fp,16
	addu	$2,$3,$2
	lw	$2,20($2)
	lui	$3,%hi($LC1)
	addiu	$4,$3,%lo($LC1)
	move	$5,$2
	jal	printf
	nop

	lw	$2,28($fp)
	nop
	addiu	$2,$2,1
	sw	$2,28($fp)
$L9:
	lw	$2,28($fp)
	nop
	slt	$2,$2,10
	bne	$2,$0,$L10
	nop

	move	$sp,$fp
	lw	$31,84($sp)
	lw	$fp,80($sp)
	addiu	$sp,$sp,88
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.2"
