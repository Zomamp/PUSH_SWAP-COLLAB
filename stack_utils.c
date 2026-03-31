/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:09 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/23 09:07:27 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_info	*init_stack(void)
{
	t_stack_info	*stack;

	stack = ft_calloc(1, sizeof(t_stack_info));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

int	is_sorted(t_stack_info *stack)
{
	t_list	*current;

	if (!stack || !stack->top || stack->size <= 1)
		return (0);
	current = stack->top;
	while (current->next != NULL)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}

int	push_top(t_stack_info *stack, int value)
{
	t_list	*newlist;
	int		*data;

	data = ft_calloc(1, sizeof(int));
	if (!data)
		return (1);
	*data = value;
	newlist = ft_lstnew(data);
	if (!newlist)
	{
		free(data);
		return (1);
	}
	newlist->next = stack->top;
	stack->top = newlist;
	if (stack->size == 0)
		stack->bottom = newlist;
	stack->size++;
	return (0);
}

int	fill_stack(t_stack_info *a, t_stack_info *b, char **args)
{
	int	total;
	int	i;

	total = 0;
	while (args[total])
		total++;
	i = total - 1;
	while (i >= 0)
	{
		if (push_top(a, ft_atoi(args[i])) == 1)
		{
			free_stacks(a, b);
			return (1);
		}
		i--;
	}
	return (0);
}

void	free_stacks(t_stack_info *stack_a, t_stack_info *stack_b)
{
	t_list	*a;
	t_list	*b;

	if (stack_a)
	{
		a = stack_a->top;
		if (a)
			ft_lstclear(&a, free);
		free(stack_a);
	}
	if (stack_b)
	{
		b = stack_b->top;
		if (b)
			ft_lstclear(&b, free);
		free(stack_b);
	}
}
