/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 08:39:47 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/15 15:08:38 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack_info *stack_a, t_stack_info *stack_b, t_bench *bench)
{
	t_list	*tmp;

	if (!stack_a || !stack_b || !stack_b->top)
		return ;
	tmp = stack_b->top;
	stack_b->top = tmp->next;
	if (stack_b->top == NULL)
		stack_b->bottom = NULL;
	stack_b->size--;
	if (stack_a->size == 0)
		stack_a->bottom = tmp;
	tmp->next = stack_a->top;
	stack_a->top = tmp;
	stack_a->size++;
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack_info *stack_a, t_stack_info *stack_b, t_bench *bench)
{
	t_list	*tmp;

	if (!stack_a || !stack_a->top || !stack_b)
		return ;
	tmp = stack_a->top;
	stack_a->top = tmp->next;
	if (stack_a->top == NULL)
		stack_a->bottom = NULL;
	stack_a->size--;
	if (stack_b->size == 0)
		stack_b->bottom = tmp;
	tmp->next = stack_b->top;
	stack_b->top = tmp;
	stack_b->size++;
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
	ft_putstr_fd("pb\n", 1);
}
