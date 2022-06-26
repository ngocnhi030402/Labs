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
	li $a1, 10 # $a1: size of array
	jal while
	
	#print max ele
	li $v0, 1
	move $a0, $t0
	syscall
	
	#end main
	li $v0, 10
	syscall
while:
	sub $sp, $sp, 8
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	
	
	lw $t0, 0($a0) #load first element to $t0
	
	beq $a1, 1, end #if $a1 = 1 go to end
	
	move $s0, $a0 #save a0
	
	addi $a0, $a0, 4 #move to next ele
	subi $a1, $a1, 1 #size--
	
	jal while
	
	move $t1, $t0 #save t0 to t1
	
	lw $t2, ($s0) #load $s0 to $t2
	
	sge $t3, $t2, $t1 #if t2 >= t1 -> t3 = 1 
	beq $t3, 0, loop #if t3 = 0 then go to loop
	loop:
		move $t0, $t2
		
		j endd
	endd:
		move $t0, $t1

			
	
end:
	#clean stack
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	add $sp, $sp, 8
	jr $ra	




