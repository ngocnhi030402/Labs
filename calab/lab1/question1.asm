.data
	msg1: .asciiz "Input an integer: "
	msg2: .asciiz "The result: "
.text

main:
	#section1
	li $v0, 4
	la $a0, msg1
	syscall
	
	#section2
	li $v0, 5
	syscall
	
	move $s0, $v0
	
	addi $s0, $s0, 1
	
	#section3
	li $v0, 4
	la $a0, msg2
	syscall 
	
	li $v0, 1
	move $a0, $s0
	syscall