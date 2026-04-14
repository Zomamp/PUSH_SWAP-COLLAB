*This project has been created as part of the 42 curriculum by zo-rakot and firahari.*

# push_swap

---

## 📌 Description

The **push_swap** project aims to sort a list of integers using a limited set of operations on two stacks (**stack A** and **stack B**).

The main goal is to produce the shortest possible sequence of instructions to sort the numbers in ascending order.

This project helps develop skills in:
- algorithm design and optimization  
- manipulation of data structures (stacks)  
- computational complexity and performance  
- efficient sorting algorithm design  

---

## 🔧 Allowed Operations

The sorting must be done using only the following stack operations:

### Swap
- `sa` : swap the first two elements of stack A  
- `sb` : swap the first two elements of stack B  
- `ss` : `sa` and `sb` at the same time  

### Push
- `pa` : push the top element from stack B to stack A  
- `pb` : push the top element from stack A to stack B  

### Rotate
- `ra` : shift up all elements of stack A (first element becomes last)  
- `rb` : shift up all elements of stack B  
- `rr` : `ra` and `rb` at the same time  

### Reverse Rotate
- `rra` : shift down all elements of stack A (last element becomes first)  
- `rrb` : shift down all elements of stack B  
- `rrr` : `rra` and `rrb` at the same time  

---

## ⚙️ Sorting Strategies

To achieve optimal performance, different strategies are used depending on input size:

### 🟢 Simple method
Used for very small datasets (2–5 numbers).  
Relies on direct comparisons and minimal operations such as:
- `sa`, `ra`, `rra`

---

### 🟡 Medium method
Used for medium-sized inputs.  
Combines stack manipulation and targeted positioning using:
- `pb`, `pa`
- `ra`, `rra`

---

### 🔴 Complex method
Used for large inputs.  
Based on advanced strategies such as radix or chunk sorting.

Uses:
- `pb`, `pa`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

Goal: achieve near **O(n log n)** performance while respecting stack constraints.

---

## 📊 Benchmark (bench)

A benchmarking mode is available to evaluate performance.

It provides:
- number of operations generated  
- distribution of operations  
- disorder percentage  
- strategy used  

Example output:
```bash
[bench] disorder: 100.0%
[bench] Strategy: Adaptive / O(n√n)
[bench] total_ops: 10
[bench] sa: 2 sb: 0 ss: 0 pa: 2 pb: 2
[bench] ra: 3 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0

## Instructions

### Compilation

To compile the project, run the following command at the root of the repository:

```bash
Current repository >	make
```

If you want to test this project , after "**make**", you can see this : 
```bash
	cc -Wall -Wextra -Werror -c ft_utils_simple1.c -o ft_utils_simple1.o
cc -Wall -Wextra -Werror -c main.c -o main.o
cc -Wall -Wextra -Werror -c ft_sa_sb_ss_sort.c -o ft_sa_sb_ss_sort.o
cc -Wall -Wextra -Werror -c ft_ra_rb_rr_sort.c -o ft_ra_rb_rr_sort.o
cc -Wall -Wextra -Werror -c ft_rra_rrb_rrr.c -o ft_rra_rrb_rrr.o
cc -Wall -Wextra -Werror -c ft_pa_pb.c -o ft_pa_pb.o
cc -Wall -Wextra -Werror -c ft_computer_desorder.c -o ft_computer_desorder.o
cc -Wall -Wextra -Werror -c ft_simple.c -o ft_simple.o
cc -Wall -Wextra -Werror -c ft_set_index.c -o ft_set_index.o
cc -Wall -Wextra -Werror -c ft_medium.c -o ft_medium.o
cc -Wall -Wextra -Werror -c ft_complex.c -o ft_complex.o
cc -Wall -Wextra -Werror -c ft_utils_simple.c -o ft_utils_simple.o
cc -Wall -Wextra -Werror -c ft_utils_complex.c -o ft_utils_complex.o
cc -Wall -Wextra -Werror -c ft_adaptative.c -o ft_adaptative.o
cc -Wall -Wextra -Werror -c ft_bench_utils.c -o ft_bench_utils.o
cc -Wall -Wextra -Werror -c ft_medium_utils.c -o ft_medium_utils.o
cc -Wall -Wextra -Werror -c ft_splitError.c -o ft_splitError.o
cc -Wall -Wextra -Werror -c utilsError.c -o utilsError.o
cc -Wall -Wextra -Werror -c parsing.c -o parsing.o
cc -Wall -Wextra -Werror -c ft_is_flags.c -o ft_is_flags.o
cc -Wall -Wextra -Werror -c ft_bench_utils1.c -o ft_bench_utils1.o
cc -Wall -Wextra -Werror -c ft_utils_simple2.c -o ft_utils_simple2.o
make -C LIBFT
make[1]: Entering directory '/home/zo-rakot/Desktop/42_Cursus/PUSH_SWAP/IMPORTANT/COPIE/LIBFT'
cc -Wall -Wextra -Werror -c ft_atoi.c
cc -Wall -Wextra -Werror -c ft_strlen.c
cc -Wall -Wextra -Werror -c ft_strrchr.c
cc -Wall -Wextra -Werror -c ft_strlcat.c
cc -Wall -Wextra -Werror -c ft_memset.c
cc -Wall -Wextra -Werror -c ft_bzero.c
cc -Wall -Wextra -Werror -c ft_memcpy.c
cc -Wall -Wextra -Werror -c ft_memmove.c
cc -Wall -Wextra -Werror -c ft_memchr.c
cc -Wall -Wextra -Werror -c ft_memcmp.c
cc -Wall -Wextra -Werror -c ft_isalpha.c
cc -Wall -Wextra -Werror -c ft_isdigit.c
cc -Wall -Wextra -Werror -c ft_isalnum.c
cc -Wall -Wextra -Werror -c ft_isascii.c
cc -Wall -Wextra -Werror -c ft_isprint.c
cc -Wall -Wextra -Werror -c ft_toupper.c
cc -Wall -Wextra -Werror -c ft_tolower.c
cc -Wall -Wextra -Werror -c ft_strchr.c
cc -Wall -Wextra -Werror -c ft_strncmp.c
cc -Wall -Wextra -Werror -c ft_strlcpy.c
cc -Wall -Wextra -Werror -c ft_strnstr.c
cc -Wall -Wextra -Werror -c ft_strdup.c
cc -Wall -Wextra -Werror -c ft_strjoin.c
cc -Wall -Wextra -Werror -c ft_substr.c
cc -Wall -Wextra -Werror -c ft_strtrim.c
cc -Wall -Wextra -Werror -c ft_calloc.c
cc -Wall -Wextra -Werror -c ft_split.c
cc -Wall -Wextra -Werror -c ft_itoa.c
cc -Wall -Wextra -Werror -c ft_strmapi.c
cc -Wall -Wextra -Werror -c ft_striteri.c
cc -Wall -Wextra -Werror -c ft_putchar_fd.c
cc -Wall -Wextra -Werror -c ft_putstr_fd.c
cc -Wall -Wextra -Werror -c ft_putendl_fd.c
cc -Wall -Wextra -Werror -c ft_putnbr_fd.c
cc -Wall -Wextra -Werror -c ft_lstnew.c
cc -Wall -Wextra -Werror -c ft_lstadd_front.c
cc -Wall -Wextra -Werror -c ft_lstsize.c
cc -Wall -Wextra -Werror -c ft_lstlast.c
cc -Wall -Wextra -Werror -c ft_lstadd_back.c
cc -Wall -Wextra -Werror -c ft_lstdelone.c
cc -Wall -Wextra -Werror -c ft_lstclear.c
cc -Wall -Wextra -Werror -c ft_lstiter.c
cc -Wall -Wextra -Werror -c ft_lstmap.c
cc -Wall -Wextra -Werror -c ft_strcmp.c
ar rcs libft.a ft_atoi.o ft_strlen.o ft_strrchr.o ft_strlcat.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_strlcpy.o ft_strlcat.o ft_strnstr.o ft_strdup.o ft_strjoin.o ft_substr.o ft_strtrim.o ft_calloc.o ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o ft_strcmp.o
----------------------------------------
     libft.a = NOW READY FOR USE!✅
----------------------------------------
make[1]: Leaving directory '/home/zo-rakot/Desktop/42_Cursus/PUSH_SWAP/IMPORTANT/COPIE/LIBFT'
----------------------------------------
     LIBFT/libft.a = NOW READY FOR USE!✅
----------------------------------------
make -C LIBFTPRINTF
make[1]: Entering directory '/home/zo-rakot/Desktop/42_Cursus/PUSH_SWAP/IMPORTANT/COPIE/LIBFTPRINTF'
cc  -Wall -Wextra -Werror -c ft_printf.c ft_utils.c ft_put_u.c ft_putuphex.c ft_putptr.c ft_double.c
ar rcs libftprintf.a ft_printf.o ft_utils.o ft_put_u.o ft_putuphex.o ft_putptr.o ft_double.o
make[1]: Leaving directory '/home/zo-rakot/Desktop/42_Cursus/PUSH_SWAP/IMPORTANT/COPIE/LIBFTPRINTF'
----------------------------------------
     LIBFTPRINTF/libftprintf.a = NOW READY FOR USE!✅
----------------------------------------
Compiled with -Wall -Wextra -Werror
cc ft_utils_simple1.c main.c ft_sa_sb_ss_sort.c ft_ra_rb_rr_sort.c ft_rra_rrb_rrr.c ft_pa_pb.c ft_computer_desorder.c ft_simple.c ft_set_index.c ft_medium.c ft_complex.c ft_utils_simple.c ft_utils_complex.c ft_adaptative.c ft_bench_utils.c ft_medium_utils.c ft_splitError.c utilsError.c parsing.c ft_is_flags.c ft_bench_utils1.c ft_utils_simple2.c LIBFT/libft.a LIBFTPRINTF/libftprintf.a -Wall -Wextra -Werror -o push_swap -lm
----------------------------------------
     push_swap = NOW READY FOR USE!✅
----------------------------------------
```
Now the program is ready to be use : so let's use.

1 - This program sort numbers in input : so if you wanna test it enter this in your terminal : 
```bash 
	./push_swap 8 5 2 1
```
2 - Choose method you want to sorting : --simple , --medium , --complex 
```bash
	./push_swap 8 5 2 1 --simple
				Or 
	./push_swap --simple 8 5 2 1
```
```bash 
	./push_swap 8 5 2 1 --complex or --medium
				Or 
	./push_swap --complex or medium 8 5 2 1
```

```bash
	./push_swap 8 5 2 1 --bench
				Or 
	./push_swap --bench 8 5 2 1
```
NB : the flag can't be called twice so you'll see "**Error**", Duplicate number "**Error**". Invalid Flags "**Error**".
```bash
After entering ./push_swap --bench 8 5 2 1
```
You'll see : 
```bash 
	COPIE ❯ ./push_swap --bench 8 5 2 1
	ra
	ra
	pb
	pb
	ra
	rra
	sa
	pa
	pa
	sa
	[bench] disorder: 100.0%
	[bench] Strategy: Adaptive / O(n√n)
	[bench] total_ops: 10
	[bench] sa: 2 sb: 0 ss: 0 pa:  2 pb:  2
	[bench] ra: 3 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0
```

```bash 
	COPIE ❯ ./push_swap 8 5 2 1
	ra
	ra
	pb
	pb
	ra
	rra
	sa
	pa
	pa
	sa
```

## Resources

### Documentation and references

- https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
- https://en.wikipedia.org/wiki/Sorting_algorithm
- https://www.geeksforgeeks.org/stack-data-structure/
- https://harm-smits.github.io/42docs/projects/push_swap
- https://medium.com/tag/sorting-algorithms (articles on sorting optimization and strategies)
- https://www.programiz.com/dsa/merge-sort (general algorithmic understanding)

These resources were used to better understand stack manipulation, sorting strategies, and algorithmic complexity in the context of the push_swap project.

### AI usage

Artificial Intelligence (ChatGPT) was used as a support tool during the development of this project.

It helped with:
- understanding and comparing sorting strategies (simple, medium, and complex approaches)
- structuring and optimizing algorithm design ideas
- debugging logical issues in sorting implementations
- improving code readability and organization
- writing and refining documentation (README, explanations, and project structure)

AI was used as an educational and guidance tool, not as a direct replacement for implementation. All code and final decisions were understood and implemented manually.

---

## 🤝 Contributions

This project was developed collaboratively.

### zo-rakot
Implemented the core sorting logic and main algorithm components:
- ft_adaptive  
- ft_bench_utils  
- ft_bench_utils1  
- ft_complex  
- ft_computer_desorder  
- ft_is_flag  
- ft_medium  
- ft_pa_pb  
- ft_push_swap.h  
- ft_ra_rb_rr_sort  
- ft_set_index  
- ft_simple  
- ft_utils_complex  
- ft_utils_simple  
- ft_utils_simple1  
- ft_utils_simple2  
- main  
- README.md  

### firahari
Responsible for parsing, error handling, and code quality:
- ft_splitError  
- parsing  
- utilsError  
- norminette compliance and cleanup of the entire project  