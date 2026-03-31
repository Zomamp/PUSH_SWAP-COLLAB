/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:14:06 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/20 13:43:10 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexation(t_stack_info *a)
{
	t_list	*i;
	t_list	*j;
	int		index;

	i = a->top;
	while (i)
	{
		index = 0;
		j = a->top;
		while (j)
		{
			if (*(int *)i->content > *(int *)j->content)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}

void	sort_three(t_stack_info *x, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	if (x->size <= 1)
		return ;
	if (x->size == 2)
	{
		if (*(int *)x->top->content > *(int *)x->bottom->content)
			swap_a(x, bench);
		return ;
	}
	top = *(int *)x->top->content;
	mid = *(int *)x->top->next->content;
	bot = *(int *)x->bottom->content;
	if (top > mid && top > bot)
		rotate_a(x, bench);
	else if (mid > top && mid > bot)
		reverse_rotate_a(x, bench);
	top = *(int *)x->top->content;
	mid = *(int *)x->top->next->content;
	if (top > mid)
		swap_a(x, bench);
}

void	sort_five(t_stack_info *stack_a, t_stack_info *stack_b, t_bench *bench)
{
	while (stack_a->size > 3)
	{
		if (stack_a->top->index == 0 || stack_a->top->index == 1)
			push_b(stack_a, stack_b, bench);
		else
			rotate_a(stack_a, bench);
	}
	sort_three(stack_a, bench);
	if (stack_b->size == 2)
	{
		if (stack_b->top->index < stack_b->top->next->index)
			swap_b(stack_b, bench);
	}
	while (stack_b->size != 0)
		push_a(stack_a, stack_b, bench);
}
