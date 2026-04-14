/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mampionona <mampionona@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:31:41 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/14 19:28:55 by mampionona       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_simple_sort(t_list **stack, t_bench *bench)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (!ft_is_sorted(stack))
		ft_insertion_sort(stack, &stack_b, bench);
}
