/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:51:59 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/20 14:09:55 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct stack_info
{
	t_list			*top;
	t_list			*bottom;
	int				size;

}					t_stack_info;
typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_bench;

typedef struct s_var
{
	double			disorder;
	int				method;
	int				start;
	int				bench_mode;

	t_stack_info	*stack_a;
	t_stack_info	*stack_b;
	t_bench			*bench;
	char			**args;
}					t_var;

void				push_a(t_stack_info *stack_a, t_stack_info *stack_b,
						t_bench *bench);
void				push_b(t_stack_info *stack_a, t_stack_info *stack_b,
						t_bench *bench);
void				reverse_rotate_a(t_stack_info *stack_a, t_bench *bench);
void				reverse_rotate_b(t_stack_info *stack_b, t_bench *bench);
void				reverse_rotate_both(t_stack_info *stack_a,
						t_stack_info *stack_b, t_bench *bench);
void				rotate_a(t_stack_info *a, t_bench *bench);
void				rotate_b(t_stack_info *b, t_bench *bench);
void				rotate_both(t_stack_info *a, t_stack_info *b,
						t_bench *bench);
void				swap_a(t_stack_info *stack_a, t_bench *bench);
void				swap_b(t_stack_info *stack_b, t_bench *bench);
void				swap_both(t_stack_info *stack_a, t_stack_info *stack_b,
						t_bench *bench);
void				sort_adaptive(t_stack_info *a, t_stack_info *b,
						double disorder, t_bench *bench);
void				sort_complex(t_stack_info *stack_a, t_stack_info *stack_b,
						t_bench *bench);
void				sort_medium(t_stack_info *a, t_stack_info *b,
						t_bench *bench);
void				sort_simple(t_stack_info *stack_a, t_stack_info *stack_b,
						t_bench *bench);
void				indexation(t_stack_info *a);
void				sort_three(t_stack_info *x, t_bench *bench);
void				sort_five(t_stack_info *stack_a, t_stack_info *stack_b,
						t_bench *bench);
void				free_tab(char **tb);
void				free_z(char **tb, int z);
int					check_stack(t_stack_info *stack_a, t_stack_info *stack_b,
						char **args);
double				compute_disorder(t_stack_info *stack_a);
t_stack_info		*init_stack(void);
t_bench				*init_bench(void);
int					initiate(t_var *var);
void				init_variable(t_var *var);
int					ready_stack(t_var *var);
void				sorting(t_var *var);
int					is_sorted(t_stack_info *stack);
int					push_top(t_stack_info *stack, int value);
int					fill_stack(t_stack_info *a, t_stack_info *b, char **args);
void				free_stacks(t_stack_info *stack_a, t_stack_info *stack_b);
char				**ft_split(char const *s, char c);
int					parse_all(char **args);
int					ft_isdigit(int c);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_atoi(char *str);
t_list				*ft_lstnew(void *content);
long				ft_atol(const char *nptr);
void				ft_lstclear(t_list **lst, void (*del)(void *));
char				*ft_strdup(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
void				display_bench(t_var *var);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				put_double_fd(double n, int decimals, int fd);
int					ft_putchar(char c);
int					ft_putstr(char *str);
int					ft_putnbr(int n);
int					ft_putnbr_base(unsigned long n, char *base);
int					flags_final_filter(int argc, char *argv[], t_var *var);
int					check_flags(int argc, char *argv[], int *bench_mode,
						int *start);
char				**final_filter_args(int argc, char *argv[], int start);
char				**build_args(int argc, char *argv[], int start);
#endif
