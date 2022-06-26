.data
	msg: .asciiz "Ho Chi Minh City - University of Technology"
	msg1: .asciiz "Reverse string: "
	str: .space 42
.text
main:

	
	#print msg1
	li $v0, 4
	la $a0, msg1
	syscall
	
	la $t0, msg #load msg to $t0
	
	add $t1, $t1, $zero #set $t1 = count = 0
	addi $t0, $t0, 43 #set $t0 to the last element
	
while:
	beq $t1, 43, exit #if t1 = 42: exit
	subi $t0, $t0, 1 #move to next element
	addi $t1, $t1, 1 #count++
	
	#print character
	li $v0, 11
	lb $a0, ($t0)
	syscall
	
	j while
exit:
	
	#end main
	li $v0, 10
	syscall
