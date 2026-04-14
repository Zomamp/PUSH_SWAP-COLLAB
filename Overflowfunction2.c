/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Overflowfunction2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 07:15:10 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/11 07:15:57 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	parse_numbers(char **numbers)
{
	int	j;

	j = 0;
	while (numbers[j])
	{
		if (is_flags(numbers[j]))
		{
			j++;
			continue ;
		}
		check_token(numbers[j]);
		j++;
	}
}

int	ft_find_bigest(t_list **stack)
{
	int		big;
	t_list	*tmp;

	big = INT_MIN;
	tmp = *stack;
	while (tmp)
	{
		if (*(int *)tmp->content > big)
			big = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (big);
}

void	parsing(char **argv)
{
	int		i;
	char	**numbers;

	i = 1;
	while (argv[i])
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			print_error();
		parse_numbers(numbers);
		if (ft_has_duplicate(numbers))
			print_error();
		free_split(numbers);
		i++;
	}
}
