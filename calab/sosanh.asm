.data
	msg: .asciiz "Result: "
	a: .float 1.2
	b: .float 1.4
.text
main:	
	lwc1 $f0, a
	lwc1 $f1, b

	c.lt.s $f0, $f1
	bc1t add
	bc1f sub
add:
	add.s $f0, $f0, $f1
	
sub:	
	sub.s $f0, $f0, $f1
	
	 
	#print msg
	li $v0, 4
	la $a0, msg
	syscall
	
	#print result
	mov.s $f12, $f0
	li $v0, 2

	syscall
	
	#exit
	li $v0, 10
	syscall

