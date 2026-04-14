/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firahari <firahari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:10:14 by firahari          #+#    #+#             */
/*   Updated: 2026/04/13 11:44:07 by firahari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	is_valid_number(char *str)
{
	if (!str || is_flags(str))
		return (0);
	return (1);
}

int	compare_values(char *a, char *b)
{
	if (ft_atol(a) == ft_atol(b))
		return (1);
	return (0);
}

int	is_skip(char **numbers, int i)
{
	if (!numbers[i] || !is_valid_number(numbers[i]))
		return (1);
	return (0);
}

int	check_dup_inner(char **numbers, int i)
{
	int	j;

	j = i + 1;
	while (numbers[j])
	{
		if (!is_valid_number(numbers[j]))
		{
			j++;
			continue ;
		}
		if (compare_values(numbers[i], numbers[j]))
			return (1);
		j++;
	}
	return (0);
}

void	free_split(char **numbers)
{
	int	k;

	k = 0;
	while (numbers[k])
	{
		free(numbers[k]);
		k++;
	}
	free(numbers);
}
