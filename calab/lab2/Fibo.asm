.data
	msg: .asciiz "\nInput n: "
	msg1: .asciiz "\nPlease input positive number: "
	msg2: .asciiz "\nFibonacci sequence: "
	space: .asciiz " "
.text
main:
	#print msg
	li $v0, 4
	la $a0, msg
	syscall
		
	#read integer
	li $v0, 5
	syscall
	move $t0, $v0 
	
	
inputagain:
	bgt $t0, 0, continue #t0 >= 0 then go to end
	#print msg1
	li $v0, 4
	la $a0, msg1
	syscall
		
	#read integer
	li $v0, 5
	syscall
	move $t0, $v0
	jal inputagain


	
continue:
	beq $t0, 1, onefibo #t0 = 1 then go to onefibo
	beq $t0, 2, twofibo #t0 = 1 then go to twofibo
	
	addi $t1, $zero, 0 #first number
	addi $t2, $zero, 1  #second number
	
	#print msg2
	li $v0, 4
	la $a0, msg2
	syscall
	
	#print first number
	li $v0, 1
	move $a0, $t1
	syscall
	
	#print space
	li $v0, 4
	la $a0, space
	syscall
	
	#print second number
	li $v0, 1
	move $a0, $t2
	syscall
	
	
	jal fibo
	
fibo:	
	add $t3, $t1, $t2
	
	#print space
	li $v0, 4
	la $a0, space
	syscall
	
	#print next element
	li $v0, 1
	move $a0, $t3
	syscall
	
	move $t1, $t2
	move $t2, $t3
	
	
	beq $t0, 3, exit
	subi $t0, $t0, 1
	jal fibo
	
onefibo:
	li $t1, 0 #first number
	li $t2, 1  #second number
	
	#print msg2
	li $v0, 4
	la $a0, msg2
	syscall
	
	#print first number
	li $v0, 1
	move $a0, $t1
	syscall
	
	#print space
	li $v0, 4
	la $a0, space
	syscall
	
	jal exit


twofibo:
	li $t1, 0 #first number
	li $t2, 1  #second number
	
	#print msg2
	li $v0, 4
	la $a0, msg2
	syscall
	
	#print first number
	li $v0, 1
	move $a0, $t1
	syscall
	
	#print space
	li $v0, 4
	la $a0, space
	syscall
	
	#print second number
	li $v0, 1
	move $a0, $t2
	syscall
	
	jal exit

exit:
	#end
	li $v0, 10
	syscall
	
	
	
