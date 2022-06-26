.data
	array: .word 1,2,3,4,5,6,7,8,9,10
	msg: .asciiz "Sum: "
.text
main:
	la $s0, array
	li $t0, 0 #$t0 = sum = 0
	li $t1, 0 #$t1 = dem = 0

while:
	beq $t1, 10, exit #t1 = 10 thi exit
	lw $t2, 0($s0)
	add $t0, $t0, $t2
	add $s0, $s0, 4 #move 4 byte
	add $t1, $t1, 1 #dem++
	j while	
	
exit:
	#print msg
	li $v0, 4
	la $a0, msg
	syscall
		
	#print sum 
	li $v0, 1
	move $a0, $t0 
	syscall
		
	
	
