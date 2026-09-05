	.file	"caller.c"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"hello STDOUT"
.LC1:
	.string	"ERROR: this is an error"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
	push	rax
	mov	edi, OFFSET FLAT:.LC0
	call	puts
	mov	rsi, QWORD PTR stderr[rip]
	mov	edi, OFFSET FLAT:.LC1
	call	fputs
	xor	eax, eax
	pop	rdx
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
