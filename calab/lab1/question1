.data
	msg: .asciiz "Input an integer"
.text

main:
	#section1
	li $v0, 4
	la $a0, msg
	syscall
	
	#section2
	li $v0, 5
	syscall
	
	move $s0, $v0
	
	addi $s0, $s0, 1
	
	#section3
	li $v0, 1
	move $a0, $s0
	syscall