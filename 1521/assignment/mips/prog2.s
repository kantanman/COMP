# COMP1521 19t2 ... Game of Life on a NxN grid
#
# Written by Eugene Clark, June 2019

## Requires (from `boardX.s'):
# - N (word): board dimensions
# - board (byte[][]): initial board state
# - newBoard (byte[][]): next board state

## Provides:

########################################################################

        .data

        .globl  main
        .globl  decideCell
        .globl  neighbours
        .globl  copyBackAndShow

# strings used for output

iterations:     .asciiz    "# Iterations: " 
a_iterations_1: .asciiz    "=== After iteration "
a_iterations_2: .asciiz    " ===\n"
n_line:         .asciiz    "\n" 
hash:           .asciiz    "#"
f_stop:         .asciiz    "."

	.text
                
# Frame:	$fp, $ra, $s0, $s1, $s2, $s3, $s4, $s5, $s6
# Uses:		$a0, $a1, $s0, $s1, $s2, $s3, $s4, $s5, $s6, $t0, $t1
# Clobbers:	$a0, $a1, $t0, $t1

# Locals:	...

# Structure:
#	main
#	-> [prologue]
#	-> ...
#	-> [epilogue]

main:

        # set up stack frame

        addi    $sp, $sp, -4
        sw      $fp, ($sp)      # push $fp
        la      $fp, ($sp)
        addi    $sp, $sp, -4
        sw      $ra, ($sp)      # push $ra
        addi    $sp, $sp, -4
        sw      $s0, ($sp)      # push $s0
        addi    $sp, $sp, -4
        sw      $s1, ($sp)      # push $s1
        addi    $sp, $sp, -4
        sw      $s2, ($sp)      # push $s2
        addi    $sp, $sp, -4
        sw      $s3, ($sp)      # push $s3
        addi    $sp, $sp, -4
        sw      $s4, ($sp)      # push $s1
        addi    $sp, $sp, -4
        sw      $s5, ($sp)      # push $s2
        addi    $sp, $sp, -4
        sw      $s6, ($sp)      # push $s3

#ask for user input:

	la    $a0, iterations     # print string "# Iterations: "
        li    $v0, 4
        syscall

        li    $v0, 5              # scan input into maxiters
        syscall

        move  $s0, $v0            #currently $s0 holds maxiters	

#initialise n variable
n_init:
        li    $s1, 1        # n = 1

#initialise i variable
i_init:
        li    $s2, 0        # i = 0

#initialise j variable
j_init:
        li    $s3, 0        # j = 0

#load N        
N_init:
        lw    $s4, N        # N       
        j     j_cond

n_cond:
        bgt   $s1, $s0 ret_0     # check if n > maxiters
        j     exec     

i_cond:
        bge   $s2, $s4 i_restart     # checking if i >= N
        j     exec

j_cond:
        bge   $s3, $s4 j_restart      # if j >= N jump to j_restart
        j     exec

exec:
        move  $a0, $s2
        move  $a1, $s3
        jal   neighbours 
        nop
        move   $s5, $v0          # $s5 = int nn
        mul    $t0, $s2, $s4
        add    $t0, $t0, $s3                
        lb     $t1, board($t0)
        move   $a0, $t1   
        move   $a1, $s5
        jal    decideCell
        mul    $t0, $s2, $s4
        add    $t0, $t0, $s3     #get back the value of $t0
        nop
        move   $s6, $v0          #$s6 = return char of decide cell
        sb     $s6, newBoard($t0)

        j     j_step

n_count_step:
       addi   $s1, 1     # n++
       
       j      n_cond

i_step:
       addi   $s2, 1     # i++
       j      i_cond

j_step:
       addi   $s3, 1     # j++
       j      j_cond

i_restart:
        li    $s2, 0     # i = 0
        j     print       

j_restart:
        li    $s3, 0          # reset j = 0
        j     i_step      

print:
        la     $a0, a_iterations_1      # print string "=== After iteration "
        li     $v0, 4
        syscall 
        move   $a0, $s1
        li     $v0, 1
        syscall                         # print integer n
        la     $a0, a_iterations_2
        li     $v0, 4
        syscall                         # print rest of the string " ===\n" 

        jal    copyBackAndShow
        nop 
        j      n_count_step 

ret_0:
        li     $v0, 0

main__post:


        lw    $s6, -32($fp)
        lw    $s5, -28($fp)
        lw    $s4, -24($fp)
        lw    $s3, -20($fp)
        lw    $s2, -16($fp)
        lw    $s1, -12($fp)
        lw    $s0, -8($fp)
        lw    $ra, -4($fp)
        lw    $sp, 4($fp)
        lw    $fp, ($fp)
        jr    $ra

############# Put your other functions here ##############################
    .text
decideCell:        #using arguments (int old, int nn)    $a0 = int old, $a1, int nn

# Frame:	$fp, $ra, $s0, $s1,
# Uses:		$a0, $a1, $s0, $s1, $t0, $t1
# Clobbers:	$a0, $a1, $t0, $t1
#
# Locals:
#	- `old' in $s0 (from $a0)
#	- `nn' in $s1 (from $a1)
#
# Structure:
#	decide_cell
#	-> [prologue]
#	-> old_cond
#	   -> old_el_if
#	-> nn_cond
#       -> ret_0
#       -> ret_1
#	-> [epilogue]
#
# Code:

        addi    $sp, $sp, -4
        sw      $fp, ($sp)      # push $fp
        la      $fp, ($sp)
        addi    $sp, $sp, -4
        sw      $ra, ($sp)      # push $ra
        addi    $sp, $sp, -4
        sw      $s0, ($sp)      # push $s0
        addi    $sp, $sp, -4
        sw      $s1, ($sp)      # push $s1

        move  $s0, $a0        #$s0 is int old
        move  $s1, $a1        #$s1 is int nn

old_cond:
        li    $t0, 1
        beq   $s0, $t0 nn_cond
        nop
        j old_el_if

old_el_if:
        li    $t0, 3
        beq   $s1, $t0 return_1
        nop
        j return_0


nn_cond:
        li    $t0, 2
        li    $t1, 3
        blt   $s1, $t0 return_0
        nop
        beq   $s1, $t0 return_1
        nop
        beq   $s1, $t1 return_1
        nop
        j return_0

return_0:
        li    $v0, 0
        j ending

return_1:
        li    $v0, 1
        j ending

ending:
        lw    $s1, ($sp)     # pop $s1
        addi  $sp, $sp, 4
        lw    $s0, ($sp)     # pop $s0
        addi  $sp, $sp, 4
        lw    $ra, ($sp)     # pop $ra
        addi  $sp, $sp, 4
        lw    $fp, ($sp)     # pop $fp
        addi  $sp, $sp, 4
        jr    $ra
       
#######################################################
        .text

neighbours:        #using arguments (int i, int jj)    $a0 = int i, $a1 = int j

# Frame:        $fp, $ra, $s0, $s1, $s2, $s3, $s4
# Uses:         $a0, $a1, $s0, $s1, $s2, $s3, $s4, $t0, $t1, $t2, $t3
# Clobbers:     $a0, $a1, $t0, $t1, $t2, $t3
#
# Locals:
#       - `i' in $s0 (from $a0)
#       - `j' in $s1 (from $a1)
#
# Structure:
#       neigbours
#       -> [prologue]
#       -> x_init
#       -> y_init
#         -> y_cond
#         -> x_cond
#       -> main_cond
#         -> y_restart
#         -> n_step
#         -> x_step
#         -> y_step
#       -> ret
#       -> ending
#       -> [epilogue]
#
# Code:


        addi    $sp, $sp, -4
        sw      $fp, ($sp)      # push $fp
        la      $fp, ($sp)
        addi    $sp, $sp, -4
        sw      $ra, ($sp)      # push $ra
        addi    $sp, $sp, -4
        sw      $s0, ($sp)      # push $s0
        addi    $sp, $sp, -4
        sw      $s1, ($sp)      # push $s1
        addi    $sp, $sp, -4
        sw      $s2, ($sp)      # push $s2
        addi    $sp, $sp, -4
        sw      $s3, ($sp)      # push $s3
        addi    $sp, $sp, -4
        sw      $s4, ($sp)      # push $s2
        addi    $sp, $sp, -4
        sw      $s5, ($sp)      # push $s3

        move  $s0, $a0          #$s0 is int i
        move  $s1, $a1          #$s1 is int j

        li    $s2, 0            #nn = 0

x_init:
        li    $s3, -1           #$s3 = x

y_init:
        li    $s4, -1           #$s4 = y

Max_init:
        lw    $s5, N            #$s5 = N
 
y_cond:
        li    $t0, 1
        bgt   $s4, $t0 y_restart
        j     main_cond

x_cond:
        li    $t0, 1
        bgt   $s3, $t0 ret
        j     main_cond

main_cond:
        add   $t0, $s0, $s3      # (i + x)
        add   $t1, $s1, $s4      # (j + y) 
        li    $t3, 0 
        addi  $t2, $s5, -1       # (N - 1_      
        blt   $t0, $t3 y_step    # if (i+x) < 0 increment y
        nop  
        bgt   $t0, $t2 y_step    # if (i + x) > (N - 1) increment y
        nop
        blt   $t1, $t3 y_step    # if (j+y) >= 0 increment y
        nop
        bgt   $t1, $t2 y_step    # if (j + y) > (N - 1) increment y
        nop
        beq   $s3, $t3 y_and_cond  #checking if x = 0 
        nop
        j     board_cond


y_and_cond:                    #x = 0; checking if y = 0
        beq   $s4, $zero y_step
        nop
        j     board_cond

board_cond:                    # checking if board[i + x][j + y] == 1)
        mul   $t3, $t0, $s5    # (i + x) * N
        add   $t3, $t3, $t1    # (i + x) * N + (j+ y)
        lb    $t4, board($t3)
        li    $t5, 1
        bne   $t4, $t5  y_step
        nop
        j     n_step

y_restart:
        li    $s4, -1          # y = -1 (looping for x)
        j     x_step

n_step:
        addi  $s2, 1           # nn++
        j     y_step

x_step:
        addi  $s3, 1           # x++
        j     x_cond

y_step:
        addi  $s4, 1           # y++
        j     y_cond

ret:
        move  $v0, $s2
        j     ending_
       
ending_:
        lw    $s5, ($sp)     # pop $s5
        addi  $sp, $sp, 4
        lw    $s4, ($sp)     # pop $s4
        addi  $sp, $sp, 4
        lw    $s3, ($sp)     # pop $s3
        addi  $sp, $sp, 4
        lw    $s2, ($sp)     # pop $s2
        addi  $sp, $sp, 4
        lw    $s1, ($sp)     # pop $s1
        addi  $sp, $sp, 4
        lw    $s0, ($sp)     # pop s0
        addi  $sp, $sp, 4
        lw    $ra, ($sp)     # pop ra
        addi  $sp, $sp, 4
        lw    $fp, ($sp)     # pop $fp
        addi  $sp, $sp, 4
        jr    $ra


#######################################################
        .text
copyBackAndShow:

        # set up stack frame
        sw    $fp, -4($sp)    #push $fp onto the stack
        la    $fp, -4($sp)    #set up $fp for this function
        sw    $ra, -4($fp)    #save the return address
        sw    $s0, -8($fp)    #save $s0 to use as ...
        sw    $s1, -12($fp)   #save $s1 to use as ...
        sw    $s2, -16($fp)   #save $s1 to use as ...
        addi  $sp, $sp, -20

i_initi:
        li    $s0, 0          #i = 0

j_initi:
        li    $s1, 0          #j = 0

N_initi:
        lw    $s2, N        

j_condi:
        bge   $s1, $s2 J_count_restart
        j     execute

i_condi:
        bge   $s0, $s2 end
        j     execute

execute:
        mul   $t0, $s0, $s2
        add   $t0, $t0, $s1
        lb    $t1, newBoard($t0)
        sb    $t1, board($t0)
        beq   $t1, $zero print_dot
        j     print_hash

print_dot:
        la     $a0, f_stop
        li     $v0, 4
        syscall
        j      j_count_step

print_hash:
        la     $a0, hash
        li     $v0, 4
        syscall
        j      j_count_step

J_count_restart:
        li    $s1, 0
        j     i_count_step

new_line:
        la    $a0, n_line
        li    $v0, 4
        syscall
        j     i_condi

i_count_step:
        addi  $s0, 1
        j     new_line

j_count_step:
        addi  $s1, 1
        j     j_condi

end:
        
        lw    $s2, ($sp)     # pop $s2
        addi  $sp, $sp, 4
        lw    $s1, ($sp)     # pop $s1
        addi  $sp, $sp, 4
        lw    $s0, ($sp)     # pop $s0
        addi  $sp, $sp, 4
        lw    $ra, ($sp)     # pop $ra
        addi  $sp, $sp, 4
        lw    $fp, ($sp)     # pop $fp
        addi  $sp, $sp, 4
        jr    $ra
