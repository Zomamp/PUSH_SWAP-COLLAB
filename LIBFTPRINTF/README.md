*This project has been created as part of the 42 curriculum by zo-rakot.*

# Description

## FT_PRINTF

ft_printf is a function coded to exactly reproduce the printf function.

## INSTRUCTIONS

If you want to run and test de program, follow all the step :
1. Enter this command in your terminal of the folder of the project

```

	bash 

	c1r13s6% make

```

```

	output

	c1r13s6% make
	cc  -Wall -Wextra -Werror -c ft_printf.c ft_utils.c ft_put_u.c ft_putuphex.c
	ar rcs libftprintf.a ft_printf.o ft_utils.o ft_put_u.o ft_putuphex.o
	c1r13s6% 

```
2. After create main.c in the folder

```bash

	bash

	touch main.c 

```
In main.c enter specific script like : 
```bash

	#include "ft_printf.h"

	int main (void)
	{
		ft_printf("example");
		return (0);
	}

```

## RESOURCES
1.	Youtube 
2.	ChatGpt 
3.	gitBook

### Youtube : 
	For watching how to implement variadic function.
### Chatgpt :
	For giving example and some exercises of variadic function.
### gitBook :
	To understand how the printf algorithm works.

