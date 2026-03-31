/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb_rr_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:52:11 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/28 03:51:03 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_rotate_reverse(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = *stack;
	while (second->next)
		second = second->next;
	*stack = first->next;
	first->next = NULL;
	second->next = first;
}

void	ft_ra(t_list **stack, t_bench *bench)
{
	ft_rotate_reverse(stack);
	ft_putendl_fd("ra", 1);
	bench->ra++;
	bench->total++;
}

void	ft_rb(t_list **stack, t_bench *bench)
{
	ft_rotate_reverse(stack);
	ft_putendl_fd("rb", 1);
	bench->rb++;
	bench->total++;
}

void	ft_rr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	ft_rotate_reverse(stack_a);
	ft_rotate_reverse(stack_b);
	ft_putendl_fd("rr", 1);
	bench->rr++;
	bench->total++;
}