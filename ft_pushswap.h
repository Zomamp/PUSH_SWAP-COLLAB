/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mampionona <mampionona@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:19:13 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/14 19:26:08 by mampionona       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
# define SIMPLE 0
# define MEDIUM 1
# define COMPLEX 3
# define ADAPTIVE 4
# include "LIBFT/libft.h"
# include "LIBFTPRINTF/ft_printf.h"
# include <limits.h>
# include <unistd.h>

typedef struct t_bench
{
	int				pa;
	int				pb;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
	char			*strategy;
	int				is_checker;
	int				fd;
	char			**argv;
	int				argc;
}	t_bench;

typedef struct t_flags
{
	int				simple;
	int				complex;
	int				medium;
	int				adaptive;
	int				bench;
}	t_flags;

typedef struct t_config
{
	int	mode;
}	t_config;

t_flags		check_flags(char **argv, int argc);
void		ft_is_two(t_list **stack, t_bench *bench);
t_list		*ft_add_stack(char **argv, int argc);
void		ft_rotate(t_list **stack);
void		ft_switch(t_list **stack);
void		ft_rotate_reverse(t_list **stack);
void		ft_sa(t_list **stack, t_bench *bench);
void		ft_sb(t_list **stack, t_bench *bench);
void		ft_ss(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		ft_ra(t_list **stack, t_bench *bench);
void		ft_rb(t_list **stack, t_bench *bench);
void		ft_rr(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		ft_rra(t_list **stack, t_bench *bench);
void		ft_rrb(t_list **stack, t_bench *bench);
void		ft_rrr(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		ft_pa(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		ft_pb(t_list **stack_a, t_list **stack_b, t_bench *bench);
double		ft_compute_disorder(t_list **stack_a);
void		ft_simple_sort(t_list **stack, t_bench *bench);
int			ft_find_bigest(t_list **stack);
void		ft_find_min(t_list **stack, t_bench *bench);
void		ft_is_five(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		ft_is_three(t_list **stack, t_bench *bench);
void		ft_set_index(t_list **stack, int link_size);
int			ft_is_sorted(t_list **stack);
void		ft_insertion_sort(t_list **stack_a,
				t_list **stack_b, t_bench *bench);
void		ft_radix(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		ft_complex_sort(t_list **stack, t_bench *bench);
void		ft_adaptative(t_list **stack, t_bench *bench);
void		ft_print_bench(t_list **stack, t_bench *bench,
				char **argv, int argc);
void		ft_initialize_count(t_bench *bench, int is_checker);
void		ft_back_to_a(t_list **stack_a, t_list **stack_b, t_bench *bench);
int			ft_find_pos_of_index(t_list *stack, int index);
void		ft_medium_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);
int			ft_sqrt(int nb);
void		ft_push_all_b(t_list **stack_a, t_list **stack_b, int chunk,
				t_bench *bench);
char		**ft_split(char const *s, char c);
void		parsing(char **argv);
long		ft_atol(char *str);
void		append_node(t_list **stack, int n);
int			ft_find_max_index(t_list *stack);
void		ft_back_to_a(t_list **stack_a, t_list **stack_b, t_bench *bench);
int			is_invalid_format(char *str);
int			is_flags(char *argv);
void		ft_choose_adaptive(t_list **stack, char **argv,
				int argc, t_bench *bench);
int			check_limits(char *str);
void		print_error(void);
int			ft_has_duplicate(char **argv);
void		parse_numbers(char **numbers);
void		check_token(char *str);
int			check_dup_inner(char **numbers, int i);
void		free_split(char **numbers);
#endif