# John Neis, j.neis@und.edu, ID 8003486 #
.data
grid: .ascii "\n | . . . . | . . . . | . . . . | . . . . | a b c d"
      .ascii "\n | . . . . | . . . . | . . . . | . . . . | e f g h"
      .ascii "\n | . . . . | . . . . | . . . . | . . . . | i j k l"
      .ascii "\n | . . . . | . . . . | . . . . | . . . . | m n o p"
     .asciiz "\n | (0)     | (1)     | (2)     | (3)     | (index)\n"

offset: .half 4, 6, 8, 10, 14, 16, 18, 20, 24, 26, 28, 30, 34, 36, 38, 40
        .half 55, 57, 59, 61, 65, 67, 69, 71, 75, 77, 79, 81, 85, 87, 89, 91
        .half 106, 108, 110, 112, 116, 118, 120, 122, 126, 128, 130, 132, 136, 138, 140, 142
        .half 157, 159, 161, 163, 167, 169, 171, 173, 177, 179, 181, 183, 187, 189, 191, 193

intro: .asciiz "Start a One-Player, 4x4x4, 3D Tic-Tac-Toe Game."

pieceSelect: .asciiz "Pick a piece: (X/O) "

movePromptX: .asciiz "Pick X's next move:\n"
movePromptO: .asciiz "Pick O's next move:\n"
continuePrompt: .asciiz "\nDo you want to continue playing? (Y/N) "
newGamePrompt: .asciiz "New Game? (Y/N) "

gridSelect: .asciiz "\tGrid: (0 - 3) "
cellSelect: .asciiz "\tCell: (a - p) "

invalidPiece: .asciiz "***** Invalid Piece! *****\n"
invalidGrid: .asciiz "***** Invalid Grid! *****\n"
invalidCell: .asciiz "***** Invalid Cell! *****\n"
invalidEmpty: .asciiz "***** Nonempty Cell! *****\n"
invalidCnt: .asciiz "*****Invalid Answer!*****\n"

input: .space 3

.text
main: # {
	li $v0, 4 #
	la $a0, intro # Print intro string
	syscall #
	la $a0, grid # Print grid
	syscall #

	jal verifyPiece

	move $s0, $a1

	li $t0, 'X'

	beq $t0, $s0, XTurn
	li $t0, 'x'
	beq $t0, $s0, XTurn

	bne $t0, $s0, OTurn
# }
XTurn: # {
	li $v0, 4
	la $a0, movePromptX
	syscall

	jal verifyGrid
	move $s1, $a0
	jal verifyCell
	move $s2, $a0

	li $t0, 97
	sub $s2, $s2, $t0
	# Ok so $s0 = 'X', $s1 = grid, $s2 = cell number, and I'm going to make $t0 be index of offset

	div $t0, $s2, 4 # $t0 = $s2 / 4
	li $t1, 16
	mult $t0, $t1 # $t0 = $t0 * 16
	mflo $t0
	
	li $t1, 4 # $s1 = $s1 * 4
	mult $s1, $t1
	mflo $s1

	add $t0, $t0, $s1 # $t0 = $t0 + $s1 iow $t0 = (cell/4) * 16 + grid * 4

	li $t1, 4
	div $s2, $t1 # division puts remainder in hi
	mfhi $s2

	add $t0, $t0, $s2 # $t0 is now the index for the offset

	li $t1, 2
	mult $t0, $t1 # Make sure index aligns with halfword boundary
	mflo $t0

	li $t1, '.'
	li $s0, 'X' # $s0 is the piece. Remember that
	lh $t0, offset($t0)

	lb $t2, grid($t0)
	
	bne $t1, $t2, nonemptyError
	sb $s0, grid($t0)

	li $v0, 4
	la $a0, grid
	syscall

	jal verifyContinue

	j OTurn
# }
OTurn: # {
	li $v0, 4
	la $a0, movePromptO
	syscall

	jal verifyGrid
	move $s1, $a0
	jal verifyCell
	move $s2, $a0

	li $t0, 97
	sub $s2, $s2, $t0
	# Ok so $s0 = 'O', $s1 = grid, $s2 = cell number, and I'm going to make $t0 be index of offset

	div $t0, $s2, 4 # $t0 = $s2 / 4
	li $t1, 16
	mult $t0, $t1 # $t0 = $t0 * 16
	mflo $t0

	li $t1, 4 # $s1 = $s1 * 4
	mult $s1, $t1
	mflo $s1

	add $t0, $t0, $s1 # $t0 = $t0 + $s1 iow $t0 = (cell/4) * 16 + grid * 4

	li $t1, 4
	div $s2, $t1 # division puts remainder in hi
	mfhi $s2

	add $t0, $t0, $s2 # $t0 is now the index for the offset

	li $t1, 2
	mult $t0, $t1 # Make sure index aligns with halfword boundary
	mflo $t0

	li $t1, '.'
	li $s0, 'O' # $s0 is the piece. Remember that
	lh $t0, offset($t0)

	lb $t2, grid($t0)
	bne $t1, $t2, nonemptyError
	sb $s0, grid($t0)
	
	li $v0, 4
	la $a0, grid
	syscall

	jal verifyContinue
	
	j XTurn
# }
nonemptyError: # {
	li $v0, 4
	la $a0, invalidEmpty
	syscall

	li $t0, 'O'
	beq $t0, $s0, OTurn
	bne $t0, $s0, XTurn
# }
verifyPiece: # {
	li $v0, 4
	la $a0, pieceSelect # Print piece selection prompt
	syscall

	li $v0, 8 # Enter a character
	la $a0, input
	li $a1, 3
	syscall

	la $s0, input # Grab the string
	lbu $a0, 0($s0) # Put string[0] into $a0
	li $a1, 'X' # Put 'x' into $a1
	beq $a0, $a1, return # If $a0 == $a1, then return

	li $a1, 'O'
	beq $a0, $a1, return # Similar but with 'o' instead

	li $a1, 'x'
	beq $a0, $a1, return

	li $a1, 'o'
	beq $a0, $a1, return

	li $v0, 4
	la $a0, invalidPiece # Print error
	syscall

	j verifyPiece # If it didn't return by this point, we know we have bad input and need to re-enter
# }
verifyCell: # {
	li $v0, 4
	la $a0, cellSelect # Print cell selection prompt
	syscall

	li $v0, 8 # Enter a character
	la $a0, input
	li $a1, 3
	syscall

	la $s0, input # Grab the string
	lbu $a0, 0($s0) # Put string[0] into $a0 // ascii a = 97 ascii p = 112

	li $a1, 97
	blt $a0, $a1, verifyCellPt2
	li $a1, 112
	bgt $a0, $a1, verifyCellPt2

	j return
# }
verifyCellPt2: # {
	li $v0, 4
	la $a0, invalidCell # Print error
	syscall

	j verifyCell # If it didn't return by this point, we know we have bad input and need to re-enter
# }
verifyGrid: # {
	li $v0, 4
	la $a0, gridSelect # Print grid selection prompt
	syscall

	li $v0, 8 # Enter a character
	la $a0, input
	li $a1, 3
	syscall

	la $s0, input # Grab the string
	lbu $a0, 0($s0) # Put string[0] into $a0
	li $t0, 48
	sub $a0, $a0, $t0

	beqz $a0, return

	li $t0, 1
	beq $t0, $a0, return

	li $t0, 2
	beq $t0, $a0, return

	li $t0, 3
	beq $t0, $a0, return

	li $v0, 4
	la $a0, invalidGrid # Print error
	syscall

	j verifyGrid # If it didn't return by this point, we know we have bad input and need to re-enter
# }
verifyContinue: # {
	li $v0, 4
	la $a0, continuePrompt # Print continue prompt
	syscall

	li $v0, 8 # Enter a character
	la $a0, input
	li $a1, 3
	syscall

	la $s0, input # Grab the string
	lbu $a0, 0($s0) # Put string[0] into $a0
	li $a1, 'Y' # Put 'N' into $a1
	beq $a0, $a1, return # If $a0 == $a1, then return

	li $a1, 'N'
	beq $a0, $a1, verifyNew # Similar but with 'N' instead

	li $a1, 'y'
	beq $a0, $a1, return

	li $a1, 'n'
	beq $a0, $a1, verifyNew

	li $v0, 4
	la $a0, invalidCnt # Print error
	syscall

	j verifyContinue # If it didn't return by this point, we know we have badinput and need to re-enter
# }
verifyNew: # {
	li $v0, 4
	la $a0, newGamePrompt # Print continue prompt
	syscall

	li $v0, 8 # Enter a character
	la $a0, input
	li $a1, 3
	syscall

	la $s0, input # Grab the string
	lbu $a0, 0($s0) # Put string[0] into $a0
	li $a1, 'Y'

	li $s0, 0 # Put 'N' into $a1
	beq $a0, $a1, clearBoard # If $a0 == $a1, then return

	li $a1, 'N'
	beq $a0, $a1, exit # Similar but with 'N' instead

	li $a1, 'y'
	li $s0, 0
	beq $a0, $a1, clearBoard

	li $a1, 'n'
	beq $a0, $a1, exit

	li $v0, 4
	la $a0, invalidCnt # Print error
	syscall

	j verifyNew
# }
clearBoard: # {
	lh $t1, offset($s0)
	li $s1, '.'
	sb $s1, grid($t1)
	
	add $s0, $s0, 2

	bne $s0, 130, clearBoard

	li $v0, 4 #
	la $a0, intro # Print intro string
	syscall #
	la $a0, grid # Print grid
	syscall #
	
	jal verifyPiece

	move $s0, $a1

	li $t0, 'X'
	beq $t0, $s0, XTurn
	li $t0, 'x'
	beq $t0, $s0, XTurn

	bne $t0, $s0, OTurn
# }
return: # {
	jr $ra
# }
exit: # {
	# Exit program
	li $v0, 10
	syscall
# }