.data
	str: .asciiz "Hello Nhi"
.text
	la $s0, str
	lb $t0, 0($s0)
	
	#e thanh a
	li $t1, 97 # a = 97
	sb $t1, 1($s0)