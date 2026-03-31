/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:23:12 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/15 15:16:39 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack_info *stack)
{
	int	tmp;

	if (!stack || !stack->top || stack->size < 2)
		return (1);
	tmp = *(int *)stack->top->content;
	*(int *)stack->top->content = *(int *)stack->top->next->content;
	*(int *)stack->top->next->content = tmp;
	return (0);
}

void	swap_a(t_stack_info *stack_a, t_bench *bench)
{
	if (swap(stack_a) == 0)
	{
		if (bench)
		{
			bench->sa++;
			bench->total++;
		}
		ft_putstr_fd("sa\n", 1);
	}
}

void	swap_b(t_stack_info *stack_b, t_bench *bench)
{
	if (swap(stack_b) == 0)
	{
		if (bench)
		{
			bench->sb++;
			bench->total++;
		}
		ft_putstr_fd("sb\n", 1);
	}
}

void	swap_both(t_stack_info *stack_a, t_stack_info *stack_b, t_bench *bench)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || stack_b->size < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	if (bench)
	{
		bench->ss++;
		bench->total++;
	}
	ft_putstr_fd("ss\n", 1);
}
