.data
	array: .word 1,2,3,4,5,6,7,8,9,10
	msg1: .asciiz "Result: "
	msg2: .asciiz " "
	
.text
main:
	la $s0, array
	li $t0, 0 #set t0 = count = 0
	
	addi $s1, $s0, 36 #set the last element to $s1
while:
	beq $t0, 5, exit #$t0 = 5 thi exit
	#swap 2 element	
	lw $t1, 0($s1)
	lw $t2, 0($s0)	
	sw $t1, 0($s0)
	sw $t2, 0($s1)
	
	#move to the next element
	addi $s0, $s0, 4
	subi $s1, $s1, 4
	addi $t0, $t0, 1 #count++
	j while
exit:
	#print msg1
	li $v0, 4
	la $a0, msg1
	syscall
	
	la $s2, array #load array to s2
	li $t3, 0 #set $t3 = count2 = 0
	
while2:
	beq $t3, 10, exit2 #$t3 = 10 thi exit
	lw $t4, 0($s2)
		
	#print array
	li $v0, 1
	move $a0, $t4
	syscall
		
	#print space
	li $v0, 4
	la $a0, msg2
	syscall
		
	addi $s2, $s2, 4
	addi $t3, $t3, 1
	j while2
exit2:
	
		
