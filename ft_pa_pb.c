/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:05:32 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/02 21:05:39 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_pa(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*stack_tmp;

	if (!*stack_b)
		return ;
	stack_tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	stack_tmp->next = *stack_a;
	*stack_a = stack_tmp;
	ft_putendl_fd("pa", 1);
	bench->pa++;
	bench->total++;
}

void	ft_pb(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*stack_tmp;

	if (!*stack_a)
		return ;
	stack_tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	stack_tmp->next = *stack_b;
	*stack_b = stack_tmp;
	ft_putendl_fd("pb", 1);
	bench->pb++;
	bench->total++;
}
