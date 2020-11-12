.text
.globl	_exchange,_stop_routine
__save:
	movq    _head@GOTPCREL(%rip), %r11
        movq    (%r11),  	%r12
        movq    %rsp,   	(%r12)
        movq    %rbp, 		8(%r12)
        movq    %rdi, 		16(%r12)
        movq    %rsi,		24(%r12)
        movq    %rdx,		32(%r12)
        movq    %rcx,		40(%r12)
        movq    %r8,		48(%r12)
        movq    %r9,		56(%r12)
        movq    %r10,		64(%r12)
        movq    %rax,		72(%r12)
        movq    %rbx,		80(%r12)
	jmp	__n0

__release:
	movq    _head@GOTPCREL(%rip), %r11
        movq	(%r11),  	%r12
	movq	(%r12),		%rsp
	movq	8(%r12),	%rbp
	movq	16(%r12),	%rdi
	movq	24(%r12),	%rsi
	movq	32(%r12),	%rdx
	movq	40(%r12),	%rcx
	movq	48(%r12),	%r8
	movq	56(%r12),	%r9
        movq	64(%r12),	%r10
	movq	72(%r12),	%rax
	movq	80(%r12),	%rbx
	retq

_exchange:                              
	jmp	__save
__n0:
	movq    _head@GOTPCREL(%rip), %rdi
    movq    _tail@GOTPCREL(%rip), %rsi
	call	_exchange_c
	jmp 	__release

__save_:
        movq    _head@GOTPCREL(%rip), %r9
        movq    (%r9),          %r8
        movq    %rax,           72(%r8)
        movq    %rdx,           32(%r8)
        jmp     __n0_

_stop_routine:                              
        jmp     __save_
__n0_:
        movq    _head@GOTPCREL(%rip), %rdi
        movq    _coll@GOTPCREL(%rip), %rsi
        movq    _UROUTINE_NR@GOTPCREL(%rip), %rdx

        call    _remove
        jmp     __release

