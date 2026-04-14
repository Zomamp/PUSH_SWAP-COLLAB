CC = cc

NAME = push_swap

SRC_FT_LIBFT = LIBFT/libft.a

SRC_FT_PRINTF = LIBFTPRINTF/libftprintf.a

SRC_PUSHSWAP =  ft_utils_simple1.c main.c ft_sa_sb_ss_sort.c ft_ra_rb_rr_sort.c ft_rra_rrb_rrr.c ft_pa_pb.c ft_computer_desorder.c \
				ft_simple.c ft_set_index.c ft_medium.c ft_complex.c ft_utils_simple.c ft_utils_complex.c ft_adaptative.c ft_bench_utils.c \
				ft_medium_utils.c ft_splitError.c utilsError.c parsing.c ft_is_flags.c ft_bench_utils1.c ft_utils_simple2.c \
				Overflowfunction.c Overflowfunction2.c

CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC_PUSHSWAP:.c=.o}

RED     := \033[31m
GREEN   := \033[32m
RESET   := \033[0m
BOLD    := \033[1m
PINK 	:= \033[35m

all: ${NAME}

${NAME}: ${OBJ} ${SRC_FT_LIBFT} ${SRC_FT_PRINTF}
	@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
	${CC} ${SRC_PUSHSWAP} ${SRC_FT_LIBFT} ${SRC_FT_PRINTF} ${CFLAGS} -o ${NAME} -lm
	@echo "$(PINK)$(BOLD)----------------------------------------"
	@echo "     $(NAME) = NOW READY FOR USE!✅"
	@echo "----------------------------------------$(RESET)"

$(SRC_FT_LIBFT):
	make -C LIBFT
	@echo "$(GREEN)$(BOLD)----------------------------------------"
	@echo "     ${SRC_FT_LIBFT} = NOW READY FOR USE!✅"
	@echo "----------------------------------------$(RESET)"

$(SRC_FT_PRINTF):
	make -C LIBFTPRINTF
	@echo "$(GREEN)$(BOLD)----------------------------------------"
	@echo "     ${SRC_FT_PRINTF} = NOW READY FOR USE!✅"
	@echo "----------------------------------------$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C LIBFT
	make clean -C LIBFTPRINTF
	rm -f ${OBJ}
	@echo "${BLUE} ${BOLD} ${OBJ} ${RESET} .o Cleaned ✅"

fclean: clean
	make fclean -C LIBFT
	make fclean -C LIBFTPRINTF
	rm -f ${NAME}
	@echo "$(BLUE) $(BOLD)$(NAME) $(RESET) Clean ✅"

re: fclean all

.PHONY: fclean clean re all