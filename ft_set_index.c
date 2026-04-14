/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 07:06:28 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/02 21:12:16 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_set_index(t_list **stack, int link_size)
{
	t_list	*biggest;
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	while (link_size-- > 0)
	{
		biggest = NULL;
		tmp = *stack;
		while (tmp)
		{
			if (tmp->index == -1 && (biggest == NULL
					|| *(int *)tmp->content > *(int *)biggest->content))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest)
			biggest->index = link_size;
	}
}
