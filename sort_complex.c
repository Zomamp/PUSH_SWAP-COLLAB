/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemanamp <hemanamp@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:42:46 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/25 08:13:02 by hemanamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_stack_info *stack_a, t_stack_info *stack_b,
		t_bench *bench)
{
	int	nb_bits, i, j;

	nb_bits = 0;
	while (((stack_a->size - 1) >> nb_bits) != 0)
		nb_bits++;
	i = 0;
	while (i < nb_bits)
	{
		j = stack_a->size;
		while (j--)
		{
			if (((stack_a->top->index >> i) & 1) == 0)
				push_b(stack_a, stack_b, bench);
			else
				rotate_a(stack_a, bench);
		}
		while (stack_b->size != 0)
		{
			if (((stack->top->index >> (i + 1)) & 1) == 1)
				rotate_b(stack_b, bench);
			push_a(stack_a, stack_b, bench);
		}
		i++;
	}
}
