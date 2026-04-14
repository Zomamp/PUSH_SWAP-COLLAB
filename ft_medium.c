/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:47:25 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/10 19:47:52 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_medium_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	size;
	int	chunk;

	size = ft_lstsize(*stack_a);
	if (size <= 100)
		chunk = 20;
	else
		chunk = 45;
	if (ft_is_sorted(stack_a))
		return ;
	else if (!ft_is_sorted(stack_a) && size <= 2)
		ft_is_two(stack_a, bench);
	else if (!ft_is_sorted(stack_a) && size <= 3)
		ft_is_three(stack_a, bench);
	else if (!ft_is_sorted(stack_a) && size <= 5)
		ft_is_five(stack_a, stack_b, bench);
	else
		ft_push_all_b(stack_a, stack_b, chunk, bench);
}
