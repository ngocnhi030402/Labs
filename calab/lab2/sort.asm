.data
	array: .space 40
	msg: .asciiz "Input 10 numbers: "
	space: .asciiz " "
	msg2: .asciiz "Result: "
.text
main:
	#print msg
	li $v0, 4
	la $a0, msg
	syscall
	
	li $t0, 0
	la $s1, array
while:
	
	
	#read integer
	li $v0, 5
	syscall
	
	move $t2, $v0
	
	sw $t2, 0($s1) # t2 vao array
	addi $s1, $s1, 4 # move to next element
	addi $t0, $t0, 1 #count++
	
	bne $t0, 10, while
	
	la $s1, array
	li $t0, 10 #set t0 = 10
	li $t1, 10 #set t1 = 10
	li $t3, 10 #set t3 = 10
sort:
 	beq $t3, 1, end 
 	subi $t3, $t3, 1
 	
	lw $t5, 0($s1) #load first ele to $t5
	lw $t6, 4($s1) #load second ele to $t6
 	
 	addi $s1, $s1, 4 #move to next ele
 	ble $t5, $t6, sort #if $t5 <= $t6 then go to sort
 		#else
 		#swap two elements
 		sw $t5, 0($s1)   
 		sw $t6, -4($s1) 
 	   
 		bnez $t3, sort    #if $t2 != 0 then go to sort

end:
 	la $s1,array     
 	
 	addi $t0, $t0,-1   #count--
 	add $t3, $t3, $t0   #t2 = t2 + t1
 	
 	bnez $t0, sort    #if $t1 != 0 then go to sort
 	#print msg2
 	li $v0, 4 
 	la $a0, msg2
 	syscall
 	
 	la $s1, array
 	li $t1, 0 #set t1 = 0
	
	
print:
	beq $t1, 10, exit
	
	lw $t2, 0($s1) #sau vao truoc

	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	addi $s1, $s1, 4
	addi $t1, $t1, 1
	jal print
	
exit:
	li $v0, 10
	syscall


	
	
	
	
	
	
	
