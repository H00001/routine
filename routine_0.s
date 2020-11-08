.text
.globl	_exchange
__save:
	movq    _head@GOTPCREL(%rip), %r9
        movq    (%r9),  	%r8
        movq    %rsp,   	(%r8)
        movq    %rbp, 		8(%r8)
        movq    %rax, 		16(%r8)
        movq    %rbx,		24(%r8)
        movq    %rcx,		32(%r8)
        movq    %rdx,		40(%r8)
        movq    %rsi,		64(%r8)
        movq    %rdi,		72(%r8)
	jmp	__n0

__release:
	movq    _head@GOTPCREL(%rip), %r9
        movq	(%r9),  	%r8
	movq	(%r8),		%rsp
	movq	8(%r8),		%rbp
	movq	16(%r8),	%rax
	movq	24(%r8),	%rbx
	movq	32(%r8),	%rcx
	movq	40(%r8),	%rdx
	movq	64(%r8),	%rsi
	movq	72(%r8),	%rdi
	jmp	__n1

_exchange:                              ## @exchange
	jmp	__save
__n0:
	movq    _head@GOTPCREL(%rip), %rdi
        movq    _tail@GOTPCREL(%rip), %rsi
	call	_exchange_c
	jmp 	__release
__n1:
	retq
