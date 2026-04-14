/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firahari <firahari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 06:43:03 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/13 12:58:54 by firahari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_initialize_count(t_bench *bench, int is_checker)
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
	bench->strategy = "none";
	bench->is_checker = is_checker;
	if (is_checker == 1)
		bench->fd = 2;
	else
		bench->fd = 1;
}

void	ft_choose_adaptive(t_list **stack, char **argv,
		int argc, t_bench *bench)
{
	t_flags	flags;
	double	d;
	t_list	*stack_b;

	d = ft_compute_disorder(stack);
	flags = check_flags(argv, argc);
	stack_b = NULL;
	if (flags.adaptive)
	{
		if (d < 20)
		{
			bench->strategy = " Adaptive / O(n²)";
			ft_simple_sort(stack, bench);
		}
		else if (d <= 50)
		{
			bench->strategy = " Adaptive / O(nlogn)";
			ft_medium_sort(stack, &stack_b, bench);
		}
		else
		{
			bench->strategy = " Adaptive / O(n√n)";
			ft_complex_sort(stack, bench);
		}
	}
}
