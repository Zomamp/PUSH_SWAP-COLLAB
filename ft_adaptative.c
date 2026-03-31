/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:17:01 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/28 21:44:41 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_adaptative(t_list **stack, t_bench *bench)
{
	int			size;
	t_list		*stack_b;

	size = ft_lstsize(*stack);
	stack_b = NULL;
	if (size <= 3)
		ft_is_three(stack, bench);
	else  if (size <= 5)
		ft_is_five(stack, &stack_b, bench);
	else if (ft_compute_disorder(stack) < 20)
		ft_simple_sort(stack, bench);
	else if (ft_compute_disorder(stack) >= 50)
		ft_complex_sort(stack, bench);
}
