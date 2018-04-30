.data
	strings:
		.ascii "Helloworld"
.bss
.text
.globl _start
_start:
	movl $4, %eax
	movl $1,%ebx
	movl $strings ,%ecx
	movl $10 ,%edx
	int  $ 0x80

	movl $1 ,%eax
 	movl $0,%ebx
	int $ 0x80

