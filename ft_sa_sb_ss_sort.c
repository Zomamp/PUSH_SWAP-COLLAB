/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:10:13 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/28 03:15:37 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_switch(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_sa(t_list **stack, t_bench *bench)
{
	ft_switch(stack);
	ft_putendl_fd("sa", 1);
	bench->sa++;
	bench->total++;
}

void	ft_sb(t_list **stack, t_bench *bench)
{
	ft_switch(stack);
	ft_putendl_fd("sb", 1);
	bench->sb++;
	bench->total++;
}

void	ft_ss(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	ft_switch(stack_a);
	ft_switch(stack_b);
	ft_putendl_fd("ss", 1);
	bench->ss++;
	bench->total++;
}