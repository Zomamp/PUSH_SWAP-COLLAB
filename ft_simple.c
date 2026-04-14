/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:31:41 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/14 15:59:02 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_simple_sort(t_list **stack, t_bench *bench)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	ft_insertion_sort(stack, &stack_b, bench);
}
