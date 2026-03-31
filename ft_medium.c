/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:47:25 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/31 08:42:44 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_medium_sort (t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	chunks;

	chunks = 0;
	if ((*stack_a)->size < 100)
		chunks = 20;
	else
		chunks = 45;
	ft_push_all_b(stack_a, stack_b, chunks, bench);
	ft_back_to_a(stack_a, stack_b, bench);
}
