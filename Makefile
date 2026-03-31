NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = main.c main_outils01.c main_outils02.c stack_utils.c helper.c sort_simple.c sort_medium.c sort_helper.c sort_complex.c sort_adaptive.c swap.c rotate.c \
reverse_rotate.c push.c bench_utils.c ft_outils.c libft_utils01.c libft_utils02.c libft_utils03.c libft_utils04.c parsing.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
