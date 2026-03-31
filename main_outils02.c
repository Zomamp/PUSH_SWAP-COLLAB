/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_outils02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:30:06 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/24 10:10:09 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_method(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (2);
	if (ft_strcmp(arg, "--complex") == 0)
		return (3);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (0);
	return (-1);
}

int	check_flags(int argc, char *argv[], int *bench_mode, int *start)
{
	int	i;
	int	method;

	i = 1;
	method = 0;
	*start = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (ft_strcmp(argv[i], "--bench") == 0)
				*bench_mode = 1;
			else
			{
				method = choose_method(argv[i]);
				if (method == -1)
					return (-1);
			}
		}
		i++;
	}
	return (method);
}

char	**final_filter_args(int argc, char *argv[], int start)
{
	char	**args;

	if (argc - start < 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	args = build_args(argc, argv, start);
	if (!args)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	if (parse_all(args) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		free_tab(args);
		return (NULL);
	}
	return (args);
}

int	flags_final_filter(int argc, char *argv[], t_var *var)
{
	var->method = check_flags(argc, argv, &var->bench_mode, &var->start);
	if (var->method == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	var->args = final_filter_args(argc, argv, var->start);
	if (!var->args)
		return (1);
	return (0);
}
