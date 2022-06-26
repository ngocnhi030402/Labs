.data
	msg1: .asciiz "Input number1: \n"
	msg2: .asciiz "Input number2: \n"
	msg3: .asciiz "Input number3: \n"
	msg4: .asciiz "Input number4: \n"
	msg5: .asciiz "Input number5: \n"
	msg6: .asciiz "Reverse: \n "
.text
	#input1
	li $v0, 4
	la $a0, msg1
	syscall
	li $v0, 5
	syscall
	move $s1, $v0
	
	#input2
	li $v0, 4
	la $a0, msg2
	syscall
	li $v0, 5
	syscall
	move $s2, $v0
	
	#input3
	li $v0, 4
	la $a0, msg3
	syscall
	li $v0, 5
	syscall
	move $s3, $v0
	
	#input4
	li $v0, 4
	la $a0, msg4
	syscall
	li $v0, 5
	syscall
	move $s4, $v0
	
	#input5
	li $v0, 4
	la $a0, msg5
	syscall
	li $v0, 5
	syscall
	move $s5, $v0
	
	#print msg6
	li $v0, 4
	la $a0, msg6
	syscall
	#print the reverse
	li $v0, 1
	move $a0, $s5
	syscall

	li $v0, 1
	move $a0, $s4
	syscall
	
	li $v0, 1
	move $a0, $s3
	syscall
	
	li $v0, 1
	move $a0, $s2
	syscall
	
	li $v0, 1
	move $a0, $s1
	syscall	
	
	
	
	
	
	
	
