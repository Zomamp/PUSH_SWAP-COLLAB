/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:00:19 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/02 23:52:24 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_radix(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	size = ft_lstsize(*stack_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1))
				ft_ra(stack_a, bench);
			else
				ft_pb(stack_a, stack_b, bench);
			j++;
		}
		while (*stack_b)
			ft_pa(stack_a, stack_b, bench);
		i++;
	}
}
