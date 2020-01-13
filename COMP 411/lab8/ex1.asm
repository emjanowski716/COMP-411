# Starter file for ex1.asm

.data
     newline:	.asciiz "\n"   
.text 0x3000

main:
  ori     $sp, $0, 0x3000     # Initialize stack pointer to the top word below .text
                              # The first value on stack will actually go at 0x2ffc
                              # because $sp is decremented first.
  addi    $fp, $sp, -4        # Set $fp to the start of main's stack frame

	#----------------------------------------------------------------#
	# Write code here to do exactly what main does in the C program.
	#
	# Please follow these guidelines:
	#
	#	Use syscall 5 each time to read an integer (scanf("%d", ...))
	#	Then call NchooseK to compute the function
	#	Then use syscall 1 to print the result
	#       Put all of the above inside a loop
	#----------------------------------------------------------------#
	
loop:
				# Read n
  addi	$v0, $0, 5			# system call 5 is for reading an integer
  syscall 				# integer value read is in $v0
  add	$8, $0, $v0			# copy n into $8
  
  beqz $8, end                 # if n = 0, exit
  
  				# Read k
  addi	$v0, $0, 5			# system call 5 is for reading an integer
  syscall 				# integer value read is in $v0
  add	$9, $0, $v0			# copy k into $9
  
  add $a0, $0, $8              # put n in a0
  add $a1, $0, $9              # put k in a1
  
  jal NchooseK
  
  add	$a0, $0, $v0		# print the result
  li	$v0, 1
  syscall
  addi 	$v0, $0, 4  		
  la 	$a0, newline 			
  syscall
  j loop

end: 
  ori   $v0, $0, 10     # system call 10 for exit
  syscall               # we are out of here.



NchooseK:    		# PLEASE DO NOT CHANGE THE NAME "NchooseK"
	#----------------------------------------------------------------#
	# $a0 has the number n, $a1 has k, from which to compute n choose k
	#
	# Write code here to implement the function you wrote in C.
	# Your implementation MUST be recursive; an iterative
	# implementation is not acceptable.
	#
	# $v0 should have the NchooseK result to be returned to main.
	#----------------------------------------------------------------#
 
  addi $sp, $sp, -12 
  sw   $ra, 0($sp)
  sw   $s0, 4($sp)
  sw   $s1, 8($sp)
  
  add $s0, $0, $a0        # put n in s0
  add $s1, $0, $a1        # put k in s1
  
  beq $s0, $s1, return1   # if n = k, exit
  beqz $s1, return1       # if k = 0, exit
  
  addi $a0, $a0, -1       # n = n - 1
  addi $a1, $a1, -1       # k = k - 1
  
  jal NchooseK
  
  mul $v0, $v0, $s0
  div $v0, $v0, $s1

exitFunction:

  lw   $ra, 0($sp)        # read registers from stack
  lw   $s0, 4($sp)
  lw   $s1, 8($sp)
  addi $sp, $sp, 12       # bring back stack pointer
  jr $ra

return1:
  
  li $v0,1
  j exitFunction

