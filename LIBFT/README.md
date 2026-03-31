*This project has been created as part of the 42 curriculum by zo-rakot*

## Description
---
The LIBFT project consists of creating a custom C library, which contains standard functions and additional functionalities that are commonly used in C programming. The primary goal is to gain a deeper understanding of memory management, data structures, and the functioning of C libraries. This project aims to equip students with the skills necessary to implement their own functions, supplementing their programming toolkit.

## Instructions
---
To compile and use the LIBFT library, follow the instructions below:

1. **Clone the repository:**
   ```bash
   git clone repository_of_your_LIBFT
    ```
2. **Navigate to the folder**
    ```bash
   cd libft_or_additional_name_of_clone
    ```
3. **Compile the library:**
    Use the make command to compile the library.
    ```bash
    bash
    make
    ```
    This will create a libft.a file in the repository.

4. After this you must see something like this :
    ```
    c1r11s6% make
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
    cc -Wall -Wextra -Werror -c ft_toupper.c
    cc -Wall -Wextra -Werror -c ft_isprint.c
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
    ar rcs libft.a ft_atoi.o ft_strlen.o ft_strrchr.o ft_strlcat.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_strlcpy.o ft_strlcat.o ft_strnstr.o ft_strdup.o ft_strjoin.o ft_substr.o ft_strtrim.o ft_calloc.o ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o
    Library created successfully
    c1r11s6% 
    ```
Don't worry, this is normal, you just compile all .c of the project **LIBFT** and it's success, your code have no problem.


## Resources
---
1.    C Standard Library Documentation
2.    42 Curriculum Documentation
3.    Memory Management in C
4.    Various articles and tutorials found on platforms like ww3shcool, Openclassroom

## AI Usage
---
AI tools were utilized for:

    Code reviews: Ensuring adherence to coding standards and best practices.
    Understanding complex concepts: Assisting in the explanation of specific functions and optimization techniques.

## Detailed Description of the Library
---

The LIBFT library includes the following main components:

### Part 1 : Memory Management ,String Manipulation , Character Classification , Conversion Functions: ###
    
```
    isalpha : checks  for an alphabetic character.
```
```
    isdigit : checks for a digit (0 through 9).
```
```
    isalnum : checks for an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c)).
```
```
    isascii : checks whether c is a 7-bit unsigned char value that  fits  into
              the ASCII character set.
```    
        isprint : checks for any printable character including space.
```
    strlen : function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0').
```
        memset : The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
```
    bzero : The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.
```
        memcpy : The memcpy() function copies n bytes from memory area src to memory area dest.  The memory areas must not overlap.
```
    memmove : function copies n bytes from memory area src to memory area dest.
```
        strlcpy : functions copy and concatenate strings respectively.
```
    strlcat : functions copy and concatenate strings respectively. But the difference with 
    strlcpy is that strlcat takes overlaps into account.
```
        toupper : These functions convert to uppercase.
```
    tolower : These functions convert lowercase.
```
        strchr : The strchr() function returns a pointer to the first occurrence of the character c in the string s.
```
    strrchr : The strrchr() function returns a pointer to the last occurrence of the character c in the string s.
```
        strncmp : The strcmp() function compares the two strings s1 and s2.
```
    memchr : The  memchr()  function scans the initial n bytes of the memory area pointed to by s for the first instance of c.
```
        memcmp : The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.
```
    strnstr : The strnstr() function locates the first occurrence of the null-terminated string little in the string big, where not more than len characters are searched.
```
        atoi : The atoi() function converts the initial portion of the string pointed to by nptr to int.        
### Part 2 : Part 2 - Additional functions ###
```
    ft_substr : return a substring that starts with start and ends with len.
```
        ft_strjoin : Create a new channel big enough to hold everything.
```
    ft_strtrim :  returns a copy of ’s1’ with characters from ’set’ removed from the beginning and the end.
```
        ft_split : Allocates memory (using malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. Each string in the returned array is allocated independently.The array of pointers itself is also allocated dynamically.The returned array must be NULL terminated.
```
    ft_itoa : Allocates memory (using malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.
```
        ft_strmapi : loops through a string and creates a new string where each character is the result of a function applied to the original index and character.
```
    ft_striteri : applies a function to each character in a string by modifying it directly, taking the index into account.
```
        ft_putchar_fd : Outputs the character ’c’ to the specified file descriptor.
```
    ft_putstr_fd : Outputs the string ’s’ to the specified file descriptor.
```
        ft_putendl_fd : Outputs the string ’s’ to the specified file descriptor followed by a newline.
```
    ft_putnbr_fd : Outputs the integer ’n’ to the specified file descriptor.
```
### Part 3 : Linked List Functions: ###
```
    ft_lstnew : Allocates memory (using malloc(3)) and returns a new node.
```
        ft_lstadd_front : Adds the node ’new’ at the beginning of the list.
```
    ft_lstsize : Counts the number of nodes in the list.
```
        ft_lstlast : Returns the last node of the list.
```
    ft_lstadd_back : Adds the node ’new’ at the end of the list.
```
        ft_lstdelone : Takes a node as parameter and frees its content using the function ’del’.
    Free the node itself but does NOT free the next node.
```    
    ft_lstclear : Deletes and frees the given node and all its successors, using the function ’del’ and free(3). Finally, set the pointer to the list to NULL.
```    
        ft_lstiter : Iterates through the list ’lst’ and applies the function ’f’ to the content of each node.
```    
    ft_lstmap : is used to traverse a linked list and create a NEW list by applying a function f to the content of each link.
```
**The library is designed to be modular, allowing for easy extension and modification as needed.**
Additional Notes

> **All functions were previously tested with a LIBTESTEUR-tester and with francinette**

## How do I test the functions? ## 

Now create your main for testing one of these code :
```bash 
    bash
    touch main.c
```
Enter in the file main.c :
```bash
    bash 
    vim main.c 
```
In the file enter this line and call the function you want :
```bash 
    #include "libft.h"

    int main (void)
    {
        // Call the function you want to test //
        // Example : ft_strlen();
        return (0);
    }
```
If you have question or problems contact me on via Slack : **zo-rakot**

