.data
	array: .word 1,2,3,4,5,6,7,8,9,10
	msg1: .asciiz "Input a integer number which is greater than 0 and less than 10: "
	msg2: .asciiz "Value: "
.text
main:
	#print msg1
	li $v0, 4
	la $a0, msg1
	syscall
	#read integer
	li $v0, 5
	syscall
	move $t0, $v0 
	la $s0, array
	
while:
	beq $t0, 0, exit #index = 0 thi exit
	subi $t0, $t0, 1
	addi $s0, $s0, 4 #move to next ele
	j while
exit:
	lw $t1, 0($s0) #sau vo truoc
	#print msg2
	li $v0, 4
	la $a0, msg2
	syscall
	#print value
	li $v0, 1
	move $a0, $t1
	syscall
		
		
		
	
	
	
	
	
	
	
