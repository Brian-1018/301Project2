          .data #This is boilerplate stuff to get QTSPIM to read this file the right way
    end_str: .asciiz "End of inventory report." # This is to print later.
          .text
          .align 2
          .globl main 

main:
# Write your code here.
# Sets up dummy head/tail
addi $v0, $zero, 9     # primes syscall to get heap space
addi $a0, $zero, 32     # allocates enough space for 2 nodes (head and tail)
syscall     # the instruction that gets the memory, now start of this is in $v0
add $s0, $zero, $v0     # a=head
addi $s1, $s0, 16       # b=tail
sw $s1, 8($s0)      # a->next=b
sw $s0, 12($s1)     # b->prev=a

Main_While:
# Gets Inputs
addi $v0, $zero, 5      # set up get int syscall
syscall     # puts user int in $v0
beq $zero, $v0, print_list     # ends program if user input is 0
add $t0, $zero, $v0     # sets t0 to itemNumber
addi $v0, $zero, 5      # set up get int syscall
syscall     # puts user int in $v0
add $t1, $zero, $v0     # sets t1 to count
beq $t1, $zero, Main_While      # if count is 0, then nothing changes

# Tests if new item
lw $s2, 8($s0)      # c = head->next
NewItem:
beq $s2, $s1, IsNew # if c = tail then item is new
lw $t3, 0($s2)      # t3 is c->itemNumber
beq $t3, $t0, NotNew    # if newest item number and t3 are equal, then item is not new
lw $s2, 8($s2)      # c = c->next
j NewItem       # continues loop

# If item is new add it to the end
IsNew:
slt $t3, $t1, $zero     # 1 if count<0
bne $t3, $zero, Main_While  # if new item count is negative, don't add it
lw $s2, 12($s1)     # c = tail->prev
addi $a0, $zero, 16     # setting up to get 16 memory on heap for new list item
addi $v0, $zero, 9      # the code to get more memory
syscall     # address is now in $v0
add $s3, $v0, $zero # d is address of new list item
sw $s2, 12($s3)     # d->prev=change
sw $s1, 8($s3)      # d->next=tail
sw $s3, 8($s2)      # c->next=data
sw $s3, 12($s1)     # tail->prev=data
sw $t0, 0($s3)      # d->itemNumber=input item t0
sw $t1, 4($s3)      # d->count= input count t1
j Main_While    # get new input

# If item is not new, edit count (c should be the correct list)
NotNew:
lw $t2, 4($s2)      # t2 = c->count
add $t2, $t2, $t1   # t2 = t3+count (if count is negative will subtract)
addi $t3, $zero, 1      # t3=1
slt $t3, $t2, $t3   # t3=1 if new total count is <1 (0 or negative), t3=0 otherwise
bne $t3, $zero, Remove      # if count is now <1, remove that list
sw $t2, 4($s2)      # c->count = updated count
j Main_While    # get new input

# if list item is needed to be removed
Remove:
lw $s3, 8($s2)      # d=c->next
lw $s2, 12($s2)     # c=c->prev
sw $s3, 8($s2)      # c->next=d
sw $s2, 12($s3)     # d->prev=c
j Main_While    # get new input

########## Helper code provided for you. Do not change! ########## 
print_list:
# Assumes head is in $s0, tail is in $s1, and data is organized
# as in the InventoryListNode struct from the assignment (hint:
# if it's not printing, check your offsets)

# Current node = head->next
lw $t2, 8($s0)            # t2 = current node
print_while:
# If current == tail, end the loop.
beq $t2, $s1, end_print_while 
    # Get and print item_num
    lw $a0, 0($t2)
    addi $v0, $0, 1
    syscall

    # print space
    addi $a0, $0, 32
    addi $v0, $0, 11
    syscall

    # Get and print count
    lw $a0, 4($t2)
    addi $v0, $0, 1
    syscall

    # print newline
    addi $a0, $0, 10
    addi $v0, $0, 11
    syscall

    # current = current->next
    lw $t2, 8($t2)
    j print_while

end_print_while:
# Print end message
la $a0, end_str # This is a pseudoinstruction
addi $v0, $0, 4
syscall

end:
    addi $v0, $0, 10
    syscall