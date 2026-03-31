/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemanamp <hemanamp@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 08:56:45 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/25 07:17:52 by hemanamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack_info *stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || stack->size < 2)
		return (1);
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	stack->bottom = prev;
	return (0);
}

void	reverse_rotate_a(t_stack_info *stack_a, t_bench *bench)
{
	if (reverse_rotate(stack_a) == 0)
	{
		if (bench)
		{
			bench->rra++;
			bench->total++;
		}
		ft_putstr_fd("rra\n", 1);
	}
}

void	reverse_rotate_b(t_stack_info *stack_b, t_bench *bench)
{
	if (reverse_rotate(stack_b) == 0)
	{
		if (bench)
		{
			bench->rrb++;
			bench->total++;
		}
		ft_putstr_fd("rrb\n", 1);
	}
}

void	reverse_rotate_both(t_stack_info *stack_a, t_stack_info *stack_b,
		t_bench *bench)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || stack_b->size < 2)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (bench)
	{
		bench->rrr++;
		bench->total++;
	}
	ft_putstr_fd("rrr\n", 1);
}
