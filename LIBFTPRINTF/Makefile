CC = cc 

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_utils.c ft_put_u.c ft_putuphex.c ft_putptr.c ft_double.c

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

AR = ar rcs

all: ${NAME}

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}

%.o: %.c
	${CC} ${CFLAGS} -c ${SRC}

clean: 
	rm -f ${OBJ}

fclean: 
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all