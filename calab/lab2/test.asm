.data
	ar: .word 1, 5, 7, -10, 2, 9, 30, 100, 76, -5
.text
	main:
		# call max(ar, 10)
		la $a0, ar			# $a0 = ar
		addi $a1, $0, 10		# $a1 = 10
		jal max
		
		# print result
		move $a0, $v0
		li $v0, 1
		syscall
		
		# exit
		li $v0, 10
		syscall
		
	max:
		sub $sp, $sp, 12
		sw $ra, ($sp)
		sw $s0, 4($sp)
		sw $s1, 8($sp)
		
		lw $v0, ($a0)
		
		beq $a1, 1, maxDone
		move $s0, $a0
		move $s1, $a1
		addi $a0, $a0, 4	
		subi $a1, $a1, 1
		jal max	
		
		move $t0, $v0	
		lw $t1, ($s0)
		sge $t2, $t1, $t0 
		beq $t2, 0, else
			move $v0, $t1
			
			j endif
		else:
			move $v0, $t0
			
		endif:
		
	maxDone:
		
		lw $ra, ($sp)
		lw $s0, 4($sp)
		lw $s1, 8($sp)
		add $sp, $sp, 12
		jr $ra
