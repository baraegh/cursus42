# push_swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## The rules :
- You have 2 stacks named a and b.
- At the beginning:
  - The stack `a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - The stack `b` is empty.
- The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
        
        sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
        
        sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
        
        ss : sa and sb at the same time.
        
        pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
        
        pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
        
        ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
        
        rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
        
        rr : ra and rb at the same time.
        
        rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
        
        rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
        
        rrr : rra and rrb at the same time.
## How to use:
run `make`

<img width="602" alt="Screen Shot 2022-03-09 at 4 37 18 PM" src="https://user-images.githubusercontent.com/46541419/157475233-cce4d88d-a42a-43ae-8361-7ee51820311e.png">

## Bonus part:
the goal is to Write a program named checker that takes as an argument the stack `a` formatted as a list of integers. It will wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument. If after executing those instructions, the stack `a` is actually sorted and the stack `b` is empty, then the program must display "OK" on the standard output. In every other case, it must display "KO".

<img width="602" alt="Screen Shot 2022-03-09 at 4 49 40 PM" src="https://user-images.githubusercontent.com/46541419/157477700-90f12c29-a802-4837-b2e4-abd7a4e86d3e.png">

## ressources:
- [Stack in c (1)](https://www.geeksforgeeks.org/stack-data-structure-introduction-program/)
- [Stack in c (2)](https://www.youtube.com/watch?v=A4sRhuGkRb0&t=706s)
- [Big-O Complexity Chart](https://www.bigocheatsheet.com/)
- [Radix sort](https://www.geeksforgeeks.org/radix-sort/)
- [Quik sort](https://www.geeksforgeeks.org/quick-sort/)
- [Bitwise operators](https://www.programiz.com/c-programming/bitwise-operators)
