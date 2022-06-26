Register
Program structure
.data 
var: .word
...
...
.text 


main:
Data Declaration
var1:	.word	3
var2:	.byte	'a'
array:	.byte	'a', 'b'
array1:	.space	40 #load 3rd ele 8($t2)


lw, lb
la copy address
lw des_reg source
sw source des_RAM
li (load immediately) load 1 cai gtri vao thanh ghi
#a = a + b
add	$t1, $t1, $t2
addi	$t1, $t1, 100 #( a = a + 100) (add immediately)
sub	
subi	

Control Structure ->

System call - I/O]
Service		Code in $v0	Arguments			Result
print_int	1		$a0 = integer to be printed	
p_f		2		$f12
p_d		3		$12
p_s		4		$a0 = address of string
read_int	5						integer returned in $v0	
r_f		6						integer returned in $v0
r_d		7						integer returned in $v0	
r_s		8		$a0 = mem address
				$a1 = length
sbrk		9		$a0 = amount			address in $v0
exit		10	

print int val contained in $t2
li $v0, 1
li $t2, 100
move $a0, $t2
syscall

read int val and store
li $v0, 5
syscall
sw $v0, $t2
# sw $v0, var

.data
	string: .asciiz "Hello world. \n"
main:
	li	$v0, 4
	la	$a0, string
	syscall
	
	li 	$v0, 10
	syscall


$t0 = ($t1) - 4($t2) - 8($t2)

la $t0, array1
1: sw $t0, $v0 # = 0 - 3
2: move  


