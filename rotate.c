/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:20:11 by hemanamp          #+#    #+#             */
/*   Updated: 2026/03/15 15:09:49 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack_info *stack)
{
	t_list	*first;

	if (!stack || !stack->top || stack->size < 2)
		return (1);
	first = stack->top;
	stack->top = stack->top->next;
	first->next = NULL;
	stack->bottom->next = first;
	stack->bottom = first;
	return (0);
}

void	rotate_a(t_stack_info *a, t_bench *bench)
{
	if (rotate(a) == 0)
	{
		if (bench)
		{
			bench->ra++;
			bench->total++;
		}
		ft_putstr_fd("ra\n", 1);
	}
}

void	rotate_b(t_stack_info *b, t_bench *bench)
{
	if (rotate(b) == 0)
	{
		if (bench)
		{
			bench->rb++;
			bench->total++;
		}
		ft_putstr_fd("rb\n", 1);
	}
}

void	rotate_both(t_stack_info *a, t_stack_info *b, t_bench *bench)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	rotate(a);
	rotate(b);
	if (bench)
	{
		bench->rr++;
		bench->total++;
	}
	ft_putstr_fd("rr\n", 1);
}
