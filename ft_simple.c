/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:31:41 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/28 03:44:16 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_simple_sort(t_list **stack, t_bench *bench)
{
	int		size;
	t_list	*stack_b;

	stack_b = NULL;
	if (!stack || !*stack || !(*stack)->next)
		return ;

	size = ft_lstsize(*stack);

	if (!ft_is_sorted(stack) && size <= 3)
		ft_is_three(stack, bench);
	else if (!ft_is_sorted(stack) && size <= 5)
	{
		stack_b = NULL;
		ft_is_five(stack, &stack_b, bench);
	}
	else
		if (!ft_is_sorted(stack))
			ft_insertion_sort(stack, &stack_b, bench);
}
