/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:39:23 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/10 19:48:17 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_complex_sort(t_list **stack, t_bench *bench)
{
	int		size;
	t_list	*stack_b;

	stack_b = NULL;
	size = ft_lstsize(*stack);
	if (!ft_is_sorted(stack) && size <= 2)
		ft_is_two(stack, bench);
	if (!ft_is_sorted(stack) && size <= 3)
		ft_is_three(stack, bench);
	else if (!ft_is_sorted(stack) && size <= 5)
		ft_is_five(stack, &stack_b, bench);
	else
		if (!ft_is_sorted(stack))
			ft_radix (stack, &stack_b, bench);
}
