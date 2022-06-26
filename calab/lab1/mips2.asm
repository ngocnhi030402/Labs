.data
	msg: .asciiz "Input an integer"
.text

#label:
	#123
	#456
	#j label

main:
# Re_a
	# print string
	li $v0, 4
	la $a0, msg
	syscall

# Re_b
	# Input an integer
	li $v0, 5
	syscall
	
	# Save variable
	move $t0, $v0
	
	#increase by 1
	addi $t0, $t0, 1
	
# Re_c
	# print an integer
	li $v0, 1
	move $a0, $t0
	syscall
	
	# End
	li $v0, 10
	syscall
	
	# arr
	# 8(arr)
	# 16(arr)
	
	
