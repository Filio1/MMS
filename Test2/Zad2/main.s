	.file	"main.c"
	.text
	.section	.rodata
.LC2:
	.string	"Choose compare method: "
.LC3:
	.string	"%d"
	.align 8
.LC4:
	.string	"Model: %21s MaxSpeed: %3d Price: %.2lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$352, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movl	$0, -344(%rbp)
	jmp	.L2
.L3:
	leaq	-336(%rbp), %rdx
	movl	-344(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rdx, %rax
	movq	%rax, %rdi
	call	randName@PLT
	movl	$300, %esi
	movl	$100, %edi
	call	randint@PLT
	movl	%eax, %edx
	movl	-344(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$315, %rax
	movb	%dl, (%rax)
	movsd	.LC0(%rip), %xmm0
	movq	.LC1(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	randReal@PLT
	movq	%xmm0, %rax
	movl	-344(%rbp), %edx
	movslq	%edx, %rdx
	salq	$5, %rdx
	addq	%rbp, %rdx
	subq	$312, %rdx
	movq	%rax, (%rdx)
	addl	$1, -344(%rbp)
.L2:
	cmpl	$9, -344(%rbp)
	jle	.L3
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-348(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-348(%rbp), %eax
	movl	%eax, %edi
	call	getComparator@PLT
	movq	%rax, %rdx
	leaq	-336(%rbp), %rax
	movq	%rdx, %rcx
	movl	$32, %edx
	movl	$10, %esi
	movq	%rax, %rdi
	call	qsort@PLT
	movl	$0, -340(%rbp)
	jmp	.L4
.L5:
	movl	-340(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$312, %rax
	movq	(%rax), %rdx
	movl	-340(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$315, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	leaq	-336(%rbp), %rsi
	movl	-340(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$5, %rcx
	addq	%rsi, %rcx
	movq	%rdx, %xmm0
	movl	%eax, %edx
	movq	%rcx, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -340(%rbp)
.L4:
	cmpl	$9, -340(%rbp)
	jle	.L5
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1090021888
	.align 8
.LC1:
	.long	0
	.long	1083129856
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
