.data 0x0

Binarypattern: .asciiz "0"

.text 0x3000

main:
#N is always in $a1
#current level is $a2, it  starts at 0
#store binarypattern and set it equal to null 
	la $sp, 0x3000		
	addi $fp, $sp, -4
	li $v0, 5		
	syscall
	add $a1, $0, $v0	
	li $a2, 0		
	li $t0, 4		
	mult $t0, $a1
	mflo $t0
	li $t1, 0x00
	sw $t1, Binarypattern($t0)	


jal makeBinaryPattern		#calling the function

end: 
	ori   $v0, $0, 10     # system call 10 for exit
	syscall               


makeBinaryPattern:	
	#allocate stack space for 3 arguments(including return address)
	addi $sp, $sp, -12
	addi $fp, $sp, 12	


	#saving values to registers
	sw $a2, -4($fp)		
	sw $a1, -8($fp)
	sw $ra, -12($fp)

	subu $t0, $a1, $a2	
	sltu $t0, $0, $t0
	xori $t0, $t0, 1
	bne $t0, $0, print

	li $t0, 4	
	mult $t0, $a2
	mfhi $t0
	mflo $t0
	li $t1, 0x30
	sw $t1, Binarypattern($t0)	

	addi $a2, $a2, 1	#currentlevel+1

	jal makeBinaryPattern


	addi $sp, $sp, 12	
	addi $fp, $sp, 12

#loading arguments
	lw $a2, -4($fp)		
	lw $a1, -8($fp)
	lw $ra, -12($fp)

	li $t0, 4	
	mult $t0, $a2
	mfhi $t0
	mflo $t0
	li $t1, 0x31
	sw $t1, Binarypattern($t0)	
	addi $a2, $a2, 1	
	jal makeBinaryPattern
	addi $sp, $sp, 12	
	addi $fp, $sp, 12
	#load arguments and return address
	lw $a2, -4($fp)		
	lw $a1, -8($fp)
	lw $ra, -12($fp)
	jr $ra
print:
	li $t0, 0	
printloop:	
	li $t1, 4	
	mult $t0, $t1
	mflo $t1
	#print character offset by $t0
	li $v0, 4		
	la $a0, Binarypattern($t1)
	syscall
	addi $t0, $t0, 1
	bne $t0, $a1, printloop
	#printing newline
	li $v0, 11		
	li $a0, 0x0a
	syscall
	jr $ra #return address
