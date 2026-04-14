/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_simple1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mampionona <mampionona@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:44:36 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/14 19:33:55 by mampionona       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	get_min_index(t_list **stack)
{
	t_list	*tmp;
	int		min;
	int		min_index;
	int		index;

	index = 0;
	min_index = 0;
	min = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		if (*(int *)tmp->content < min)
		{
			min = *(int *)tmp->content;
			min_index = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (min_index);
}

void	ft_find_min(t_list **stack, t_bench *bench)
{
	int		index;
	int		min_index;
	int		moves;

	index = ft_lstsize(*stack);
	min_index = get_min_index(stack);
	if (min_index <= index / 2)
		while (min_index-- > 0)
			ft_ra(stack, bench);
	else
	{
		moves = index - min_index;
		while (moves-- > 0)
			ft_rra(stack, bench);
	}
}

int	ft_is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (!tmp || !(tmp)->next)
		return (1);
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_search_max_bit(t_list **stack)
{
	int		max;
	t_list	*tmp;

	if (!stack || !*stack)
		return (-1);
	max = (*stack)->index;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
