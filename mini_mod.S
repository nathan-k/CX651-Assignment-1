	.file	"mini.c"
	.intel_syntax noprefix
	.text
	.globl	sort
	.type	sort, @function
sort:
	cmp	rdi, 5
	mov	edx, 17
	mov	eax, 11
	cmovle	rax, rdx
	ret
	.size	sort, .-sort
	.globl	branch
	.type	branch, @function
branch:
	mov	eax, 1
	cmp	rdi, rsi
	jg	.L4
	cmp	rdi, 3
	jle	.L9
	mov	eax, 12
	cmp	rsi, 3
	jg	.L4
.L9:
	mov	eax, 33
.L4:
	ret
	.size	branch, .-branch
	.globl	loop
	.type	loop, @function
loop:
	xor	eax, eax
.L15:
	test	edi, edi
	jle	.L14
	test	esi, esi
	jle	.L14
	mov	edx, edi
	dec	edi
	imul	edx, esi
	dec	esi
	add	eax, edx
	jmp	.L15
.L14:
	ret
	.size	loop, .-loop
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
