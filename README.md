*This project has been created as part of the 42 curriculum by [hemanamp], [arajonso].*

## DESCRIPTION
**Push Swap** is an algorithmic project from the 42 curriculum whose objective is to sort a list of integers using **a limited set of stack operations**. The challenge is not only to sort the numbers correctly but also to minimize the number of operations performed.

The program receives **a list of integers** as arguments and must output a sequence of operations that sorts the numbers **in ascending order** using two stacks:

* ``Stack A – initially contains all the numbers``.

* ``Stack B – initially empty and used as auxiliary storage``.

The project focuses on algorithmic optimization, data structure management, and problem-solving under constraints.\
The allowed operations simulate stack manipulation and must be printed as output. The goal is to produce the shortest possible sequence of operations to sort the input.

**FEATURES**
* **Sorting using only two stacks**
* **Implementation of restricted stack operations**
* **Optimized algorithm depending on the number of elements**
* **Input validation (duplicates, invalid characters, integer limits)**
* **Efficient sorting for large datasets (100–500 numbers)**

## Push_swap – Global Algorithm

``1. Input Parsing and Validation``

Before sorting, the program performs several checks:\
Read arguments from the command line.\
Split arguments if numbers are provided as a single string.\
Convert each argument into an integer.\
Check for:
* **invalid characters**
* **integer overflow**
* **duplicate numbers**
* **Store the numbers into Stack A using a linked list structure.**
* **If an error occurs, the program prints "Error" and exits.**

``2. Check if Already Sorted``

Before running any algorithm, the program checks whether Stack A is already sorted.
If the stack is sorted, the program exits immediately without printing any operations.
This avoids unnecessary work.

``3. Indexing the Numbers``

To simplify sorting, the program converts each value into its sorted index.\
Example:

**Original numbers**
```
40 10 30 20
```
**Sorted order**
```
10 20 30 40
```
**Indexes become**
```
40 → 3
10 → 0
30 → 2
20 → 1
```
Using indexes instead of values simplifies the algorithm and improves performance.

``4. Algorithm Selection``

The program chooses the sorting algorithm depending on the number of elements.\
**Typical strategy**:

| SIZE            |   ALGORITHM     |
| ----------------| ----------------|
| 2–5 elements    | Simple sorting  |
| ≤ 100 elements  | Chunk Sort      |
| > 100 elements  | Radix Sort      |

This hybrid strategy ensures good performance for all input sizes.

``5. Selection Sort``

For very small stacks, dedicated algorithms are used.\
Examples:\
2 numbers → swap if needed.\
3 numbers → optimal sequence using sa, ra, rra.\
4–5 numbers:
* Push the smallest numbers to stack B
* Sort the remaining numbers in A
* Push elements back to A

This guarantees a minimal number of moves.

``6. Chunk Sort``

For medium-sized stacks (usually up to 100 elements), the program uses Chunk Sorting.\
Principle\
The stack is divided into chunks (groups of indexes).\
Numbers belonging to the current chunk are pushed to Stack B.\
Elements are pushed in a way that keeps Stack B partially ordered.\
Once all elements are in Stack B, they are pushed back to Stack A in sorted order.\
Steps\
Divide the index range into chunks.\
Scan Stack A:\
* If the index belongs to the current chunk → pb
* Otherwise → ra

Repeat until Stack A is empty.\
Push the largest elements from Stack B back to Stack A using rotations.\
This reduces the number of operations significantly.

``7. Radix Sort``

For large stacks (typically more than 100 elements), Radix Sort (Binary Radix) is used.\
This algorithm sorts numbers bit by bit.\
Principle\
Each number's binary representation is analyzed.\
For each bit position:
* If the bit is 0 → push to Stack B
* If the bit is 1 → rotate Stack A

After processing all elements:
* Push everything back from Stack B to Stack A
* Repeat this process for every bit until all bits are processed.

Example:
Numbers (indexes):
```
0 1 2 3
```
Binary:
```
00
01
10
11
```
Sorting occurs bit by bit.\
``Advantages``
* Very efficient for large datasets
* Predictable complexity
* Simple implementation

``8. Final Result``

After the algorithm finishes:

Stack A is sorted in ascending order

Stack B is empty

The program outputs the sequence of operations required to achieve this result.

**ALLOWED OPERATIONS**

The following operations are permitted:
| Operation | Description                                   |
| --------- | --------------------------------------------- |
| `sa`      | Swap the first two elements of stack A        |
| `sb`      | Swap the first two elements of stack B        |
| `ss`      | `sa` and `sb` at the same time                |
| `pa`      | Push the first element of B onto A            |
| `pb`      | Push the first element of A onto B            |
| `ra`      | Rotate A (first element becomes last)         |
| `rb`      | Rotate B                                      |
| `rr`      | `ra` and `rb` simultaneously                  |
| `rra`     | Reverse rotate A (last element becomes first) |
| `rrb`     | Reverse rotate B                              |
| `rrr`     | `rra` and `rrb` simultaneously                |


## INSTRUCTIONS
**COMPILATION**

To compile the program, use the provided Makefile.
```Bash
make
```

This command will compile all source files and generate the executable:
```
push_swap
```
Additional Makefile commands:
```Bash

make clean      # Remove object files

make fclean     # Remove object files and executable

make re         # Recompile the project from scratch
```

**RUNNING THE PROGRAM**

The program takes a list of integers as arguments and outputs the instructions needed to sort them.

Example:
```Bash
./push_swap 2 1 3 6 5 8
```

Output example:
```
sa
pb
ra
...
```
Each instruction corresponds to an operation applied to the stacks.

**ACCEPTED INPUT FORMATS**

Numbers can be provided in two ways.

Multiple arguments:
```Bash
./push_swap 4 67 3 87 23
```
Single string argument:
```Bash
./push_swap "4 67 3 87 23"
```
Both formats are supported by the parser.

The push_swap program supports optional flags to choose the sorting strategy depending on the size or complexity of the input.

These flags allow the program to select the most appropriate algorithm.

USAGE:
```bash
./push_swap [FLAG] <list_of_integers>
```

**--simple**

The --simple flag is used for small datasets.

It applies a simplified sorting algorithm optimized for a small number of elements.

Example:
```
./push_swap --simple 3 1 2
```
This mode focuses on producing the minimum number of operations for small stacks.

**--medium**

The --medium flag is designed for moderate-sized datasets.

It uses a more advanced strategy suitable for stacks containing dozens of numbers.

Example:
```
./push_swap --medium 8 3 5 1 9 2 6 4
```
This mode balances efficiency and operation count for medium inputs.

**--complex**

The --complex flag is intended for large datasets.

It activates a more sophisticated sorting algorithm designed to handle large stacks efficiently.

Example:
```
./push_swap --complex 34 2 78 12 9 45 67 1 23
```
This mode focuses on scalability and performance when sorting many elements.

**Notes**

Only one flag should be used at a time.

If no flag is provided, the program may automatically choose the appropriate strategy based on the number of input elements.

Example:
```
./push_swap --medium 10 4 6 2 8 1
```

**ERROR HANDLING**

The program prints:
```
Error
```
if one of the following cases occurs:

* Non-numeric arguments

* Integer overflow or underflow

* Duplicate numbers

* Invalid input format

**BENCHMARK MODE**

The project includes a benchmark option to evaluate sorting performance.

Example:
```Bash
./push_swap --bench 6 41 0 98 30 25
```
This mode generates random numbers and measures the number of operations used by the implemented algorithms.

It allows comparison between the implemented strategies:

Selection Sort

Chunk Sort

Radix Sort

The benchmark helps determine which algorithm performs best depending on the input size and disorder level.


## TEAM WORK & METHODOLOGY

This project was developed through a collaborative approach, where tasks were divided while maintaining shared understanding and continuous communication.

### hemanamp's Contributions:

* Implementation of core operations:

  * `push`
  * `rotate`
* Sorting logic:

  * `sort_medium`
* Project documentation:

  * `README`

### arajonso's Contributions:

* Core operations:

  * `swap`
  * `reverse_rotate`
* Sorting algorithms:

  * `sort_simple`
  * `sort_complex`

### Shared Work

The remaining parts of the project were developed together, including:

* Parsing and error handling
* Stack management
* Adaptive strategy design
* Testing and optimization

We regularly discussed algorithmic strategies, compared different approaches (simple, chunk-based, and radix), and shared ideas to improve performance and code structure. This helped us better understand the problem and explore multiple optimization techniques.

Each member, however, implemented their own version of the project, wrote their own code, and ensured full understanding of every part of the implementation.

This collaborative approach allowed us to:

* Gain deeper insight into sorting algorithms
* Identify and fix edge cases more efficiently
* Improve overall performance and code quality

## RESOURCES

**DOCUMENTATION**

42 Intranet – Push Swap subject

**TUTORIALS**

https://www.youtube.com/watch?v=OaG81sDEpVk

**AI USAGE**

Artificial Intelligence tools were used during this project for the following tasks:

* Understanding algorithmic strategies (e.g: radix sort and chunk sort)
* Explaining algorithm complexity
* Improving documentation and README formatting
* Debugging conceptual issues in sorting logic

However, all core implementation, algorithm selection, and code writing were performed manually, ensuring a full understanding of the project requirements.