#################################################################################
#
#	Paul Oliva & C. Hans Thompson
#	Paulmoliva@gmail.com, hans.thompson1@gmail.com
#	Programming assignment number 2
#	Date: 2/23/2016
#
#	PURPOSE:		This program allows the user to play tic-tac-toe, a popular game among children
#				and a popular programming assignment among computer science professors.
#	Algorithm:
#		    	do
#    			{	 
#    				TicTacToe();
#    				initializeBoard();
#    				playerTurn();
#    			}while (ans == "y");
#			NOTE: This stub algorithm only contains the main method of the program. Please see attached documentation for full algorithm.
#
#	Inputs:		mpveCount: Used to track # of moves. Causes a draw when t reaches 9.
#			whoseMove: Used to track whose move it is.
#			board: Used to track the moves made and check for wins.
#			row1, row2, row3: Used to visually display the board.
#			input: Used to accept user input.
#			newline: Used to print a line break.
#			playerx / playero: Used to prompt for user input
#			win: Congratulates player on a job well done winning the game.
#			drawn: Consoles the players that sadly, the game is a draw.
#			again: Prompts the player to play again.
#			d1 - d9: the numbers 1-9. Used to reset the board.
#
.data
	moveCount:	.word	0
	whoseMove:	.asciiz	"X"
	board:		.asciiz	"123456789\n"
	row1:		.asciiz	"_1_|_2_|_3_\n"
	row2:		.asciiz "_4_|_5_|_6_\n"
	row3:		.asciiz " 7 | 8 | 9 \n"
	input:		.word 0
	playerx:	.asciiz "\nPlayer X, enter a move number:"
	playero:	.asciiz "Player O, enter a move number:"
	newline:	.asciiz "\n"
	win:		.asciiz "Congratulations,  !\n"
	drawn:		.asciiz "\nSorry, bro. It's a draw! "
	again:		.asciiz "Would you like to play again?"
	d1:		.byte	49
	d2:		.byte	50
	d3:		.byte	51
	d4:		.byte	52
	d5:		.byte	53
	d6:		.byte	54
	d7:		.byte	55
	d8:		.byte	56
	d9:		.byte	57

.text
main:
	la 		$s0, board		#char[][] board = new char[3][3]
	lw 		$s7 , moveCount		#moveCount = 0
	addi 		$sp, $sp, -4
	sw		$ra, 0($sp)
	jal		displayBoard		#printBoard()
	lw		$ra, 0($sp)
	addi		$sp, $sp, 4

playerxturn:
	addi 		$v0, $zero, 4		#playerTurn()
	la		$a0, playerx
	add		$s7, $s7, 1	
	syscall
	j turn
	
playeroturn:
	addi 		$v0, $zero, 4
	la		$a0, playero
	add		$s7, $s7, 1	
	syscall

turn:
	addi 		$v0, $zero, 12		#System	    	System.out.println("Player "+ whoseMove + ", your turn.");
	    					#System.out.println("Choose row 0, 1, or 2.");
						#moveRow = keys.nextInt();
						#System.out.println("Choose column 0, 1, or 2.");
						#moveCol = keys.nextInt();
	syscall
	


	addi 		$s1, $v0, 0		#board[moveRow][moveCol] = whoseMove
	la 		$s2, board
	lb 		$s3, whoseMove
	li  		$s4, 49
	beq		$s1, $s4, move1
	li 		$s4, 50
	beq 		$s1, $s4, move2
	li  		$s4, 51
	beq 		$s1, $s4, move3
	li  		$s4, 52
	beq 		$s1, $s4, move4
	li  		$s4, 53
	beq 		$s1, $s4, move5
	li  		$s4, 54
	beq 		$s1, $s4, move6
	li  		$s4, 55
	beq 		$s1, $s4, move7
	li  		$s4, 56
	beq 		$s1, $s4, move8
	li  		$s4, 57
	beq 		$s1, $s4, move9
move1:
	sb 		$s3, 0($s2)
	la 		$s4, row1
	sb 		$s3, 1($s4)
	j		print
move2:
	sb 		$s3, 1($s2)
	la 		$s4, row1
	sb 		$s3, 5($s4)
	j		print
move3:
	sb 		$s3, 2($s2)
	la 		$s4, row1
	sb 		$s3, 9($s4)
	j		print
move4:
	sb 		$s3, 3($s2)
	la 		$s4, row2
	sb 		$s3, 1($s4)
	j		print
move5:
	sb 		$s3, 4($s2)
	la 		$s4, row2
	sb 		$s3, 5($s4)
	j		print
move6:
	sb 		$s3, 5($s2)
	la 		$s4, row2
	sb 		$s3, 9($s4)
	j		print
move7:
	sb 		$s3, 6($s2)
	la 		$s4, row3
	sb 		$s3, 1($s4)
	j		print
move8:
	sb 		$s3, 7($s2)
	la 		$s4, row3
	sb 		$s3, 5($s4)
	j		print
move9:
	sb 		$s3, 8($s2)
	la 		$s4, row3
	sb 		$s3, 9($s4)
	j		print
print:
	addi 		$v0, $zero, 4
	la		$a0, board
	syscall
	addi 		$sp, $sp, -4
	sw		$ra, 0($sp)
	jal		displayBoard
	lw		$ra, 0($sp)
	addi		$sp, $sp, 4
checkWin:					#checkForWin()
	lb		$t0, 0($s0)
	lb		$t1, 1($s0)
	lb		$t2, 2($s0)
	lb		$t3, 3($s0)
	lb		$t4, 4($s0)
	lb		$t5, 5($s0)
	lb		$t6, 6($s0)
	lb		$t7, 7($s0)
	lb		$t8, 8($s0)
	beq 		$t0, $t1, winR1
R2:	beq 		$t3, $t4, winR2
R3:	beq 		$t6, $t7, winR3
C1:	beq 		$t0, $t3, winC1
C2:	beq 		$t1, $t4, winC2
C3:	beq 		$t2, $t5, winC3
D1:	beq 		$t0, $t4, winD1
D2:	beq 		$t2, $t4, winD2
	j 		setTurn

winR1:
	beq 		$t1, $t2, itsAWin
	j 		R2
winR2:
	beq 		$t4, $t5, itsAWin
	j 		R3
winR3:
	beq 		$t7, $t8, itsAWin
	j 		C1
winC1:
	beq 		$t3, $t6, itsAWin
	j 		C2
winC2:
	beq 		$t4, $t7, itsAWin
	j 		C3
winC3:
	beq 		$t5, $t8, itsAWin
	j 		D1
winD1:
	beq 		$t4, $t8, itsAWin
	j 		D2
winD2:
	beq 		$t4, $t6, itsAWin
	j 		setTurn
draw:	
	addi 		$v0, $zero, 4
	la		$a0, drawn
	syscall
	j		playAgain
	
itsAWin: 
	la		$t9, win
	sb 		$s3, 17($t9)
	addi 		$v0, $zero, 4
	la		$a0, win
	syscall
	j 		playAgain

setTurn:							#if (whoseMove == 'X')
								#	whoseMove = 'O';
								#else
								#	whoseMove = 'X';
	beq		$s3, 88, setO
	beq		$s3, 79, setx
	
setO:
	li 		$s3, 79
	sw		$s3, whoseMove
	j 		playeroturn

setx:
	li		$s3, 88
	sw		$s3, whoseMove
	j 		playerxturn			

displayBoard:							#printBoard()

        							#System.out.println("-------------");
		
        							#for (int row = 0; row < 3; row++) 
       								# {
            							#	System.out.print("| ");
            							#	for (int col = 0; col < 3; col++) 
            							#	{
            							#   	System.out.print(board[row][col] + " | ");
            							#}
            							#System.out.println();
            							#System.out.println("-------------");
        							#}

	li		$a1, 9
	beq		$s7, $a1, draw
	addi 		$v0, $zero, 4
	la		$a0, newline
	syscall
	addi 		$v0, $zero, 4
	la		$a0, row1
	syscall
	la		$a0, row2
	syscall
	la		$a0, row3
	syscall
	jr	$ra
	
resetBoard:						#// Loop through rows
	    						#for (int row = 0; row < 3; row++) 
	    						#{
	        					#// Loop through columns
	    						#	for (int col = 0; col < 3; col++) 
	    						#	{
	    						#		board[row][col] = ' ';
	    						#	}
	    						#}
	li 		$t0, 'X'
	sb 		$t0, whoseMove
	sw 		$zero, moveCount
	lb 		$t1, d1
	lb 		$t2, d2
	lb 		$t3, d3
	lb 		$t4, d4
	lb 		$t5, d5
	lb 		$t6, d6
	lb 		$t7, d7
	lb 		$t8, d8
	lb 		$t9, d9
	sb 		$t1, 1($s2)
	sb 		$t2, 2($s2)
	sb 		$t3, 3($s2)
	sb 		$t4, 4($s2)
	sb 		$t5, 5($s2)
	sb 		$t6, 6($s2)
	sb 		$t7, 7($s2)
	sb 		$t8, 8($s2)
	sb 		$t9, 9($s2)
	sb 		$t7, 1($s4)
	sb 		$t8, 5($s4)
	sb 		$t9, 9($s4)
	la 		$s4, row2
	sb 		$t4, 1($s4)
	sb 		$t5, 5($s4)
	sb 		$t6, 9($s4)
	la 		$s4, row1
	sb 		$t1, 1($s4)
	sb 		$t2, 5($s4)
	sb 		$t3, 9($s4) 
	j 		main
	
playAgain:
    							#Scanner keys = new Scanner(System.in);
    							#if (checkForWin() == false  && isBoardFull() == true)
							#	{
							#	System.out.println("Tie game. Play again? (y/n): ");
							#	ans = keys.nextLine(); 
							#	}
							#	else if (checkForWin() == true)
							#	{
							#		System.out.println("Player " + whoseMove + " wins!");
							#		System.out.println("Play again? (y/n): ");
							#		ans = keys.nextLine();
							#	}
	addi 		$v0, $zero, 4
	la		$a0, again	
	syscall
	addi 		$v0, $zero, 12
	syscall
	addi 		$s1, $v0, 0
	beq		$s1, 121, resetBoard
	beq		$s1, 89, resetBoard
	li 		$v0,10
	syscall