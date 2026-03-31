/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:19:13 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/30 15:48:11 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PUSHSWAP_H
#define FT_PUSHSWAP_H

#include "LIBFT/libft.h"
#include "LIBFTPRINTF/ft_printf.h"
#include <limits.h>

typedef	struct t_bench
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
}	t_bench;

t_list		*ft_add_stack(char **argv, int argc);
void		ft_print_list(t_list *stack_a);
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
int			ft_find_min (t_list **stack);
void		ft_is_five(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		ft_is_three(t_list **stack, t_bench *bench);
void		ft_set_index(t_list **stack, int link_size);
int			ft_is_sorted (t_list **stack);
void		ft_insertion_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		ft_radix(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		ft_complex_sort(t_list **stack, t_bench *bench);
void		ft_adaptative(t_list **stack, t_bench *bench);
void		ft_print_bench(t_list **stack_a, t_bench *bench, double	d);
void		ft_initialize_count(t_bench *bench);
void		ft_back_to_a(t_list **stack_a, t_list **stack_b, t_bench *bench);
int			ft_find_pos_max(t_list **stack);
void		ft_push_all_b(t_list **stack_a, t_list **stack_b, int chunk, t_bench *bench);
void		ft_medium_sort (t_list **stack_a, t_list **stack_b, t_bench *bench);
# endif