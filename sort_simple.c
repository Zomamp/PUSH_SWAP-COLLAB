/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemanamp <hemanamp@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:19:11 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/25 07:12:06 by hemanamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_stack_info *stack, int target_index)
{
	t_list	*current;
	int		pos;

	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current->index == target_index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

static void	bring_to_top(t_stack_info *stack, int position, t_bench *bench)
{
	int	center;

	if (!stack || position < 0 || position >= stack->size)
		return ;
	center = stack->size / 2;
	if (position == 0)
		return ;
	center = stack->size / 2;
	if (position <= center)
	{
		while (position-- > 0)
			rotate_a(stack, bench);
	}
	else
	{
		position = stack->size - position;
		while (position-- > 0)
			reverse_rotate_a(stack, bench);
	}
}

int	speed_test(t_stack_info *stack_a, t_bench *bench)
{
	if (stack_a->size == 2)
	{
		swap_a(stack_a, bench);
		return (0);
	}
	if (stack_a->size == 3)
	{
		sort_three(stack_a, bench);
		return (0);
	}
	return (1);
}

void	sort_simple(t_stack_info *stack_a, t_stack_info *stack_b,
		t_bench *bench)
{
	int	target_index;
	int	curr_pos;

	if (is_sorted(stack_a) == 0)
		return ;
	if (speed_test(stack_a, bench) == 0)
		return ;
	target_index = 0;
	while (stack_a->size > 3)
	{
		curr_pos = find_pos(stack_a, target_index);
		bring_to_top(stack_a, curr_pos, bench);
		push_b(stack_a, stack_b, bench);
		target_index++;
	}
	sort_three(stack_a, bench);
	while (stack_b->size > 0)
		push_a(stack_a, stack_b, bench);
}
