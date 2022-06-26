.data
	num: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	msg: .asciiz "Result: "
.text
main:
	#print msg
	li $v0, 4
	la $a0, msg
	syscall
	
	la $a0, num
	addi $a1, $zero, 10 #set size of array = 10
	jal sum
	
	# print sum
	move $a0, $t3
	li $v0, 1
	syscall
		
	#end main
	li $v0, 10
	syscall	
	
sum:
	sub $sp, $sp, 8
	sw $ra, 0($sp)
	sw $t0, 4($sp)
	
	lw $t0, 0($a0)
	
	li $t3, 0 #set sum = 0
	beq $a1, 0, sumdone
	subi $a1, $a1, 1
	addi $a0, $a0, 4
	
	jal sum
	add $t3, $t3, $t0
	

sumdone:
	#clean stack
	lw $ra, 0($sp)
	lw $t0, 4($sp)
	add $sp, $sp, 8
	jr $ra