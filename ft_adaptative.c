/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:17:01 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/10 13:22:52 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_adaptative(t_list **stack, t_bench *bench)
{
	int			size;
	t_list		*stack_b;
	double		disorder;

	size = ft_lstsize(*stack);
	stack_b = NULL;
	disorder = ft_compute_disorder(stack);
	if (disorder < 20)
		ft_simple_sort(stack, bench);
	else if (disorder <= 50)
		ft_medium_sort(stack, &stack_b, bench);
	else
		ft_complex_sort(stack, bench);
}
