.data
	msg1: .asciiz "Input an integer: "
	msg2: .asciiz "Input another integer: "
	msg3: .asciiz "The result: "
.text

main:
	#print msg1
	li $v0,4
	la $a0, msg1
	syscall
	#input an integer
	li $v0, 5
	syscall
	move $a1, $v0
	#print msg2
	li $v0,4
	la $a0, msg2
	syscall
	#input another integer
	li $v0, 5
	syscall
	move $a2, $v0
	#sum 2 integers
	add $a3, $a1, $a2
	#print msg3
	li $v0, 4
	la $a0, msg3
	syscall
	#print the result
	li $v0, 1
	move $a0, $a3
	syscall
	
	
	
	
	
	
	
	