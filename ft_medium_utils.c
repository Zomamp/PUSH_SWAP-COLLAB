/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 23:04:28 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/31 11:42:04 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_push_all_b(t_list **stack_a, t_list **stack_b, int chunk, t_bench *bench)
{
	int	i;

	i = 0;
	while ((*stack_a)->size)
	{
		if ((*stack_a)->top->index <= i)
		{
			ft_pb(stack_a, stack_b, bench);
			i++;
		}
		else if ((*stack_a)->top->index <= i + chunk)
		{
			ft_pb(stack_a, stack_b, bench);
			ft_rb(stack_b, bench);
		}
		else
			ft_ra(stack_a, bench);
	}
}

int	ft_find_pos_max(t_list **stack)
{
	int		max;
	t_list	*tmp;
	int		position;
	int		i;
	
	if (!stack || !*stack)
		return (-1);
	max = (*stack)->index;
	tmp = *stack;
	position = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			position = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (position);
}

void	ft_back_to_a(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	position;
	int	size;
	if (ft_is_sorted(stack_a))
		return ;
	while ((*stack_b))
	{
		position = ft_find_pos_max(stack_b);
		if (position < 0)
			return ;
		size = ft_lstsize(*stack_b);
		if (position <= size / 2)
		{
			while (position--)
				ft_rb(stack_b, bench);
		}
		else
		{
			position = size - position;
			while (position--)
				ft_rrb(stack_b, bench);
		}
		ft_pa(stack_a, stack_b, bench);
	}
}
