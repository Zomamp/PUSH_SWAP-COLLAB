/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:25:02 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/24 09:42:40 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_is_number(char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (1);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!ft_isdigit(s[i]))
		return (1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_duplicate(char **args)
{
	int		i;
	int		j;
	long	n1;
	long	n2;

	i = 0;
	while (args[i])
	{
		n1 = ft_atol(args[i]);
		j = i + 1;
		while (args[j])
		{
			n2 = ft_atol(args[j]);
			if (n1 == n2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_range(char *s)
{
	long long	number;

	number = ft_atol(s);
	if (number < INT_MIN || number > INT_MAX)
		return (1);
	return (0);
}

int	parse_all(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (check_is_number(args[i]) == 1 || check_range(args[i]) == 1)
			return (1);
		i++;
	}
	if (check_duplicate(args) == 1)
		return (1);
	return (0);
}
