/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_computer_desorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:46:52 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/28 03:51:19 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

double	ft_compute_disorder(t_list **stack_a)
{
	int		mistake;
	int		total_pairs;
	t_list 	*a;
	t_list	*b;

	mistake = 0;
	total_pairs = 0;
	a = *stack_a;
	while (a)
	{
		b = a->next;
		while (b)
		{
			total_pairs++;
			if (*(int *)a->content > *(int *)b->content)
				mistake++;
			b = b->next;
		}
		a = a->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return (((double)mistake / total_pairs) * 100);
}
