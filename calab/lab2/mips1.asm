.data
	msg: .asciiz "Input string: "
	msg2: .asciiz "\nReverse string: "
	msg3: .space 20
.text
main:
	#print msg
	li $v0, 4
	la $a0, msg
	syscall
	
	#read string
	li $v0, 8
	la $a0, msg3
	li $a1, 20 #maximum length
	syscall
	
	li $v0, 4
	la $a0, msg3
	syscall
	
	#end main
	li $v0, 10
	syscall
