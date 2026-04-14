/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_simple2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mampionona <mampionona@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 07:12:16 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/14 18:55:50 by mampionona       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	is_flags(char *argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(&argv[i], "--simple") == 0)
			return (1);
		else if (ft_strcmp(&argv[i], "--medium") == 0)
			return (1);
		else if (ft_strcmp(&argv[i], "--complex") == 0)
			return (1);
		else if (ft_strcmp(&argv[i], "--adaptive") == 0)
			return (1);
		else if (ft_strcmp(&argv[i], "--bench") == 0)
			return (1);
		i++;
	}
	return (0);
}

void	process_numbers(char **numbers, t_list **stack_a)
{
	int		j;
	int		*cast;
	t_list	*tmp;	

	j = 0;
	while (numbers[j])
	{
		if (is_invalid_format(numbers[j]) || !check_limits(numbers[j]))
			print_error();
		tmp = *stack_a;
		while (tmp)
		{
			if (*(int *)tmp->content == (int)ft_atol(numbers[j]))
				print_error();
			tmp = tmp->next;
		}
		cast = malloc(sizeof(int));
		if (!cast)
			return ;
		*cast = (int)ft_atol(numbers[j]);
		ft_lstadd_back(stack_a, ft_lstnew(cast));
		free(numbers[j]);
		j++;
	}
	free(numbers);
}

t_list	*ft_add_stack(char **argv, int argc)
{
	t_list	*stack_a;
	int		i;
	char	**numbers;

	i = 1;
	numbers = NULL;
	stack_a = NULL;
	while (i < argc)
	{
		if (is_flags(argv[i]))
		{
			i++;
			continue ;
		}
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			print_error();
		process_numbers(numbers, &stack_a);
		i++;
	}
	return (stack_a);
}
