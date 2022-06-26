.data
	msg1: .asciiz "Input a: \n"
	msg2: .asciiz "Input b: \n"
	msg3: .asciiz "Input c: \n"
	msg4: .asciiz "Input d: \n"
	msg5: .asciiz "f = "
	msg6: .asciiz "\ng = "
.text
main:
	#print msg1 and input a
	li $v0, 4
	la $a0, msg1
	syscall
	li $v0, 5
	syscall
	move $s1, $v0
	
	#print msg2 and input b
	li $v0, 4
	la $a0, msg2
	syscall
	li $v0, 5
	syscall
	move $s2, $v0
	
	#print msg3 and input c
	li $v0, 4
	la $a0, msg3
	syscall
	li $v0, 5
	syscall
	move $s3, $v0
	
	#print msg4 and input d
	li $v0, 4
	la $a0, msg4
	syscall
	li $v0, 5
	syscall
	move $s4, $v0
	
	#calculate f
	add $t0, $s1, $s2
	sub $t1, $s3, $s4
	subi $t2, $t1, 2
	sub $t3, $t0, $t2
	li $v0, 4
	la $a0, msg5
	syscall
	#print f
	li $v0, 1
	move $a0, $t3
	syscall
	
	#calculate g
	add $t0, $s1, $s2
	add $t1, $s3, $s4
	li $a0, 3
	mult $t0, $a0 # t0 x 3
	mflo $s0 # $s0 = $lo
	move $t2, $s0
	
	li $a1, 2
	mult $t1, $a1
	mflo $s0
	move $t3, $s0
	
	sub $t4, $t2, $t3
	
	li $v0, 4
	la $a0, msg6
	syscall
	#print g
	li $v0, 1
	move $a0, $t4
	syscall
	