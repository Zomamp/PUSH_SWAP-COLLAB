/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 06:51:53 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/28 03:16:27 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*prev;

	// Gestion d'erreur
	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	// Recherche de la fin de la liste
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rra(t_list **stack, t_bench *bench)
{
	ft_rotate(stack);
	ft_putendl_fd("rra", 1);
	bench->rra++;
	bench->total++;
}

void	ft_rrb(t_list **stack, t_bench *bench)
{
	ft_rotate(stack);
	ft_putendl_fd("rrb", 1);
	bench->rra++;
	bench->total++;
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	bench->rra++;
	bench->total++;
}