NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC =  ft_atoi.c ft_strlen.c ft_strrchr.c ft_strlcat.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strdup.c ft_strjoin.c ft_substr.c \
	ft_strtrim.c ft_calloc.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strcmp.c
	
OBJ = ${SRC:.c=.o}
RED     := \033[31m
GREEN   := \033[32m
RESET   := \033[0m
BOLD    := \033[1m
PINK 	:= \033[35m

########################################

all : ${NAME}

########################################

${NAME}: ${OBJ}
	$(AR) ${NAME} ${OBJ}
	@echo "$(GREEN)$(BOLD)----------------------------------------"
	@echo "     $(NAME) = NOW READY FOR USE!✅"
	@echo "----------------------------------------$(RESET)"

########################################

%.o:%.c
	$(CC) ${CFLAGS} -c $<

########################################

bonus: all	

########################################

clean: 
	rm -f $(OBJ)

########################################

fclean: clean
	rm -f $(NAME)

########################################

re: fclean all

#######################################

.PHONY : fclean re all bonus clean

#######################################
