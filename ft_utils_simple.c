/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mampionona <mampionona@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 20:46:52 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/14 19:26:23 by mampionona       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_is_two(t_list **stack, t_bench *bench)
{
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
		ft_sa(stack, bench);
}

void	ft_is_three(t_list **stack, t_bench *bench)
{
	int			biggest;

	biggest = ft_find_bigest(stack);
	if (*(int *)(*stack)->content == biggest)
		ft_ra(stack, bench);
	if (*(int *)(*stack)->next->content == biggest)
		ft_rra(stack, bench);
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
		ft_sa(stack, bench);
}

void	ft_is_five(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int			pushed;

	pushed = 0;
	if (ft_is_sorted(stack_a))
		return ;
	while (pushed < 2)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			ft_pb(stack_a, stack_b, bench);
			pushed++;
		}
		else
			ft_ra(stack_a, bench);
	}
	ft_is_three(stack_a, bench);
	ft_pa(stack_a, stack_b, bench);
	ft_pa(stack_a, stack_b, bench);
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		ft_sa(stack_a, bench);
}

void	ft_insertion_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	if (!stack_a || !*stack_a)
		return ;
	while (*stack_a)
	{
		ft_find_min(stack_a, bench);
		ft_pb(stack_a, stack_b, bench);
	}
	while (*stack_b)
		ft_pa(stack_a, stack_b, bench);
}
