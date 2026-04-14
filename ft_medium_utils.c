/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 23:04:28 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/06 22:50:03 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_find_max_index(t_list *stack)
{
	int	max;

	max = stack->index;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	ft_find_pos_of_index(t_list *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	ft_back_to_a(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	max;
	int	pos;
	int	size;

	while (*stack_b)
	{
		max = ft_find_max_index(*stack_b);
		pos = ft_find_pos_of_index(*stack_b, max);
		size = ft_lstsize(*stack_b);
		if (pos <= size / 2)
		{
			while ((*stack_b)->index != max)
				ft_rb(stack_b, bench);
		}
		else
		{
			while ((*stack_b)->index != max)
				ft_rrb(stack_b, bench);
		}
		ft_pa(stack_a, stack_b, bench);
	}
}

void	ft_push_all_b(t_list **stack_a, t_list **stack_b, int chunk,
		t_bench *bench)
{
	int		i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			ft_pb(stack_a, stack_b, bench);
			ft_rb(stack_b, bench);
			i++;
		}
		else if ((*stack_a)->index <= i + chunk)
		{
			ft_pb(stack_a, stack_b, bench);
			i++;
		}
		else
			ft_ra(stack_a, bench);
	}
	ft_back_to_a(stack_a, stack_b, bench);
}
