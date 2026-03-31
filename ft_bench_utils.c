/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:20:08 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/28 21:52:14 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_initialize_count(t_bench *bench)
{
	bench->total = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

void	ft_print_bench(t_list **stack_a, t_bench *bench, double	d)
{
	ft_printf("[bench] disorder: %f%%\n", d);
	ft_printf("[bench] Strategy: ");
	ft_adaptative(stack_a, bench);
	// Comptage des methodes
	ft_printf("\n[bench]	total_ops:	%d\n", bench->total);
	ft_printf("[bench]	sa:	%d	sb:	%d	ss:	%d	pa:	%d	pb:	%d\n", bench->sa, bench->sb,
	bench->ss, bench->pa, bench->pb);
	ft_printf("[bench]	ra:	%d	rb:	%d	rr:	%d	rra:	%d	rrb:	%d	rrr:	%d\n", bench->ra, bench->rb, bench->rr,
	bench->rra, bench->rrb, bench->rrr);
}

int	ft_bench_is_flag(char *arg)
{
	return (ft_strcmp(arg, "--bench"));
}