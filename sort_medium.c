/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:54:25 by hemanamp          #+#    #+#             */
/*   Updated: 2026/03/11 17:43:05 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chunks_to_b(t_stack_info *a, t_stack_info *b, int chunk,
		t_bench *bench)
{
	int	i;

	i = 0;
	while (a->size)
	{
		if (a->top->index <= i)
		{
			push_b(a, b, bench);
			rotate_b(b, bench);
			i++;
		}
		else if (a->top->index <= i + chunk)
		{
			push_b(a, b, bench);
			i++;
		}
		else
			rotate_a(a, bench);
	}
}

static int	max_position_b(t_stack_info *b)
{
	t_list	*tmp;
	int		max;
	int		position;
	int		i;

	if (!b->top)
		return (1);
	tmp = b->top;
	max = tmp->index;
	position = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			position = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (position);
}

static void	back_to_a(t_stack_info *a, t_stack_info *b, t_bench *bench)
{
	int	position;

	while (b->size)
	{
		position = max_position_b(b);
		if (position <= b->size / 2)
		{
			while (position--)
				rotate_b(b, bench);
		}
		else
		{
			position = b->size - position;
			while (position--)
				reverse_rotate_b(b, bench);
		}
		push_a(a, b, bench);
	}
}

void	sort_medium(t_stack_info *a, t_stack_info *b, t_bench *bench)
{
	int	chunk;

	if (a->size <= 100)
		chunk = 20;
	else
		chunk = 45;
	chunks_to_b(a, b, chunk, bench);
	back_to_a(a, b, bench);
}
