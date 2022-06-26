.data # khai bao du lieu
str: .asciiz "Xin chao"

.text #Chay chuong trinh 
	#li $t0, 10 #t0 = 10
	#add $s1, $zero, 15 # $s1 = 0 + 15 = 15

#Nhap gia tri tu ban phim
	# li $v0, 5 # $v0 = 5
	# syscall
	
	# move $s0, $v0 #s0 = $v0 (luu vao thanh ghi s0 de nhap gia tri moi)
	
# li $v0, 4 #$v0 = 4 print string
# la $a0, str #a0 = address(str)
# syscall

#Nhap chuoi tu ban phim
li $v0, 8
la $a0, str # a0 = address(str)
li $a1, 3 #chi nhap dc 2 (tru di 1)
syscall
	
	
	