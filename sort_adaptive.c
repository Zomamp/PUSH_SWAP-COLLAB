/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:31:34 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/23 12:52:10 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack_info *a, t_stack_info *b, double disorder,
		t_bench *bench)
{
	if (a->size == 1)
		return ;
	if (a->size == 2)
	{
		swap_a(a, bench);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a, bench);
		return ;
	}
	if (a->size == 5)
	{
		sort_five(a, b, bench);
		return ;
	}
	if (a->size > 1000)
		sort_complex(a, b, bench);
	else if (disorder < 0.2)
		sort_simple(a, b, bench);
	else if (disorder < 0.5)
		sort_medium(a, b, bench);
	else
		sort_complex(a, b, bench);
}
