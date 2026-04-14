/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:13:53 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/13 14:23:42 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_flags	the_flags(char **argv)
{
	t_flags	flags;
	int		i;

	i = 0;
	flags.simple = 0;
	flags.medium = 0;
	flags.complex = 0;
	flags.adaptive = 0;
	flags.bench = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			flags.simple = 1;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			flags.medium = 1;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			flags.complex = 1;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			flags.adaptive = 1;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			flags.bench = 1;
		i++;
	}
	return (flags);
}

t_flags	check_flags(char **argv, int argc)
{
	t_flags	flags;
	int		i;
	int		bench_count;

	flags = the_flags(argv);
	if (!flags.simple && !flags.medium && !flags.complex)
		flags.adaptive = 1;
	if (flags.simple + flags.medium + flags.complex + flags.adaptive > 1)
		print_error();
	i = 1;
	bench_count = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			bench_count++;
		i++;
	}
	if (bench_count > 1)
		print_error();
	return (flags);
}
