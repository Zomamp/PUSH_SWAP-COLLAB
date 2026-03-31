/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 08:56:31 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/24 10:29:59 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_args(int argc, char *argv[], int start)
{
	char	**new_args;
	int		count;
	int		j;

	count = 0;
	while (start < argc)
	{
		if (argv[start][0] == '-' && argv[start][1] == '-')
		{
			start++;
			continue ;
		}
		new_args = ft_split(argv[start], ' ');
		if (!new_args)
			return (-1);
		j = 0;
		while (new_args[j])
		{
			count++;
			j++;
		}
		free_tab(new_args);
		start++;
	}
	return (count);
}

static char	**store_real_args(int argc, char *argv[], char **final, int start)
{
	char	**tmp;
	int		j;
	int		z;

	z = 0;
	while (start < argc)
	{
		if (argv[start][0] == '-' && argv[start][1] == '-')
		{
			start++;
			continue ;
		}
		tmp = ft_split(argv[start++], ' ');
		if (!tmp)
		{
			free_tab(final);
			return (NULL);
		}
		j = 0;
		while (tmp[j])
			final[z++] = tmp[j++];
		free(tmp);
	}
	return (final);
}

char	**build_args(int argc, char *argv[], int start)
{
	char	**final;
	int		total;

	total = count_args(argc, argv, start);
	if (total == -1 || total == 0)
		return (NULL);
	final = ft_calloc(total + 1, sizeof(char *));
	if (!final)
		return (NULL);
	final = store_real_args(argc, argv, final, start);
	if (!final)
		return (NULL);
	return (final);
}

int	main(int argc, char *argv[])
{
	t_var	var;
	int		status;

	init_variable(&var);
	if (flags_final_filter(argc, argv, &var) == 1)
		return (1);
	if (initiate(&var) == 1)
	{
		free_tab(var.args);
		return (1);
	}
	status = ready_stack(&var);
	if (status == 1)
		return (1);
	if (status == 0)
	{
		var.disorder = compute_disorder(var.stack_a);
		sorting(&var);
	}
	if (var.bench_mode == 1)
		display_bench(&var);
	free_stacks(var.stack_a, var.stack_b);
	free(var.bench);
	return (0);
}
