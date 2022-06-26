.data
	msg1: .asciiz "Input 10 integers: "
	msg2: .asciiz "Sum: "
	array: .word 40
.text

main:
	#print msg1
	li $v0, 4
	la $a0, msg1
	syscall
	
	la $s0, array #set array address to s0
	li $t0, 0 #set t0 = count1 = 0
	li $t4, 0 #set t4 = sum = 0
	
while:
	beq $t0, 10, exit #t0=10 thi exit
		
	#input integer
	li $v0, 5
	syscall
		
	move $t1, $v0
	
	add $t4, $t4, $t1
	addi $t0, $t0, 1
	j while
exit:
	#print msg2
	li $v0, 4
	la $a0, msg2
	syscall
	#print sum
	li $v0, 1
	move $a0, $t4
	syscall
		
		
	
