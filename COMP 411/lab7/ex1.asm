.data
  AA:     .space 400  		# int AA[100]
  BB:     .space 400  		# int BB[100]
  CC:     .space 400  		# int CC[100]
  m:      .space 4   		# m is an int whose value is at most 10
                     		# actual size of the above matrices is mxm
  temp:   .space 8
  newline:.asciiz "\n"
  addspace:.asciiz " "

  # You may add more variables here if you need to

.text

main:

#------- INSERT YOUR CODE HERE for main -------#
#
#  Best is to convert the C program line by line
#  into its assembly equivalent. Carefully review
#  the coding templates near the end of Lecture 8.
#
#  1.  First, read m (the matrices will then be size mxm).

  addi	$v0, $0, 5	 # system call 5 is for reading an integer
  syscall 		 # integer value read is in $v0
  add	$8, $0, $v0	 # copy m into $8
  
#  2.  Next, read matrix A followed by matrix B.

  add   $a1, $0, $0     # i in $9 = 0
  add   $a2, $0, $0     # j in $10 = 0
  add   $a3, $0, $0     # k in $11 = 0
  add   $a0, $0, $0     # temp in $12 = 0
  
loopA:

  sll $9, $a1, 2         # convert "i" to word offset
  bge $a1, $8, startB    # go to loopB if i > m
  addi $a1, $a1, 1       # i++
  li $a2, 0              # set j to 0
  j loopA2

loopA2:
  
  sll $10, $a2, 2       # convert "j" to word offset
  bge $a2, $8, loopA    # go to loopA if j > m
  addi $v0, $0, 5       # system call 5 is for reading an integer
  syscall               # integer value read is in $v0
  add $a0, $0, $v0      # copy value into temp
  mul $24, $9, $8       # multiply i * m 
  add $24, $24, $10     # add j to $24
  sw $a0, AA($24)       # store temp into AA[i*m+j]
  addi $a2, $a2, 1
  j loopA2
  
startB:

  add   $a1, $0, $0     # i in $9 = 0
  add   $a2, $0, $0     # j in $10 = 0
  add   $a3, $0, $0     # k in $11 = 0
  add   $a0, $0, $0     # temp in $12 = 0
  
loopB:
 
  sll $9, $a1, 2        # convert "i" to word offset
  bge $a1, $8, startC     # go to loopB if i > m
  addi $a1, $a1, 1      # i++
  li $a2, 0
  j loopB2

loopB2:

  sll $10, $a2, 2       # convert "j" to word offset
  bge $a2, $8, loopB    # go to loopA if j > m
  addi $v0, $0, 5       # system call 5 is for reading an integer
  syscall               # integer value read is in $v0
  add $a0, $0, $v0      # copy value into temp
  mul $24, $9, $8       # multiply i * m 
  add $24, $24, $10     # add j to $24
  sw $a0, BB($24)       # store temp into BB[i*m+j]
  addi $a2, $a2, 1
  j loopB2

#  3.  Compute matrix product. You will need triple-nested loops for this.

startC:

  add   $a1, $0, $0     # i in $9 = 0
  add   $a2, $0, $0     # j in $10 = 0
  add   $a3, $0, $0     # k in $11 = 0
  add   $a0, $0, $0     # temp in $12 = 0
  
loopC:

  sll $9, $a1, 2            # convert "i" to word offset
  bge $a1, $8, startPrint   # exit if i > m
  addi $a1, $a1, 1          # i++
  li $a2, 0                 # reset j to 0
  li $a3, 0                 # reset k to 0
  j loopC2

loopC2:

  sll $10, $a2, 2       # convert "j" to word offset
  bge $a2, $8, loopC    # go back to loopC if true
  addi $a2, $a2, 1      # j++
  li $a3, 0             # reset k to 0
  j loopC3

loopC3:

  sll $11, $a3, 2        # convert "k" to word offset
  bge $a3, $8, loopC2    # go back to loopC2 if true
  
  # get address of BB
  mul $24, $11, $8       # multiply k * m
  add $24, $24, $10      # add j
  lw $25, BB($24)        # get the index of BB
  
  # get address of AA
  mul $24, $9, $8        # multiply i * m
  add $24, $24, $11      # add k
  lw $14, AA($24)        # get the index of AA
  
  # get address of CC
  mul $24, $9, $8        # multiply i * m
  add $24, $24, $10      # add j
  lw $13, CC($24)        # get the index of CC
  
  # multiply and add values
  mul $12, $25, $14      # multiply AA and BB
  add $13, $13, $12      # add that value to CC
  sw $13, CC($24)        # store it in CC
  
  addi $a3, $a3, 1       # k++
  j loopC3

#  4.  Print the result, one row per line, with one (or more) space(s) between values within a row.

startPrint:

  add   $a1, $0, $0     # i in $9 = 0
  add   $a2, $0, $0     # j in $10 = 0
  add   $a3, $0, $0     # k in $11 = 0
  add   $a0, $0, $0     # temp in $12 = 0
  
printloop:

  sll $9, $a1, 2        # convert "i" to word offset
  bge $a1, $8, exit      # go to exit if i > m
  addi $a1, $a1, 1      # i++
  li $a2, 0             # reset j to 0
  j printloop2

  
printloop2:

  sll $10, $a2, 2           # convert "j" to word offset
  bge $a2, $8, newlineloop    # go to loopA if j > m
  mul $24, $9, $8           # multiply i * m 
  add $24, $24, $10         # add j to $24
  lw $15, CC($24)           # store value of CC[i*r+j]
  addi $v0, $0, 1
  add  $a0, $0, $15         # print value
  syscall
  addi 	$v0, $0, 4  		
  la 	$a0, addspace 			
  syscall
  addi $a2, $a2, 1          # j++
  j printloop2

newlineloop:

  addi 	$v0, $0, 4  		
  la 	$a0, newline 			
  syscall
  j printloop  


#  5.  Exit.
#
#------------ END CODE ---------------#


exit:                     # this is code to terminate the program -- don't mess with this!
  addi $v0, $0, 10        # system call code 10 for exit
  syscall                 # exit the program



#------- If you decide to make other functions, place their code here -------#
#
#  You do not have to use helper methods, but you may if you would like to.
#  If you do use them, be sure to do all the proper stack management.
#  For this exercise though, it is easy enough to write all your code
#  within main.
#
#------------ END CODE ---------------#
