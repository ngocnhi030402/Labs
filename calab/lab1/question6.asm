.data
	array: .word 1,2,3,4,5,6,7,8,9,10
	msg1: .asciiz "Sum odd: "
	msg2: .asciiz "Sum even: "
	msg3: .asciiz "\n"
.text
main:
	la $s0, array
	la $s1, array
	li $t0, 0 # sum even = 0
	li $t1, 0 # sum odd = 0
	li $t2, 1 # count1 = 1
	li $t4, 1 #count2 = 1
	
while:
	beq $t2, 6, exit
	addi $t2, $t2, 1
	lw $t3, 0($s0)
	add $t1, $t1, $t3
	addi $s0, $s0, 8
	j while
exit:
	#print msg1
	li $v0, 4
	la $a0, msg1
	syscall
	#print sum odd
	li $v0, 1
	move $a0, $t1
	syscall
	#print endline
	li $v0, 4
	la $a0, msg3
	syscall
	
while2:
	beq $t4, 6, exit2
	addi $t4, $t4, 1
	lw $t5, 4($s1)
	add $t0, $t0, $t5
	addi $s1, $s1, 8
	j while2
exit2:	
	#print msg2
	li $v0, 4
	la $a0, msg2
	syscall
	#print sum even
	li $v0, 1
	move $a0, $t0
	syscall

		
	
