/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Overflowfunction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mampionona <mampionona@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 07:11:52 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/14 18:56:21 by mampionona       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	is_invalid_format(char *str)
{
	int	i;

	if (!str || !str[0])
		return (1);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_limits(char *str)
{
	long long	n;

	n = ft_atol(str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

int	ft_has_duplicate(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (!numbers[i] || is_flags(numbers[i]))
		{
			i++;
			continue ;
		}
		if (check_dup_inner(numbers, i))
			return (1);
		i++;
	}
	return (0);
}

void	check_token(char *str)
{
	if (is_invalid_format(str))
		print_error();
	if (!check_limits(str))
		print_error();
}
