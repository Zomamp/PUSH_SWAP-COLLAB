/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mampionona <mampionona@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 22:14:43 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/14 19:00:53 by mampionona       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	choose_flags(t_list **stack_a, t_list **stack_b,
			t_bench *bench, t_flags flags)
{
	if (flags.simple)
		ft_simple_sort(stack_a, bench);
	else if (flags.complex)
		ft_complex_sort(stack_a, bench);
	else if (flags.medium)
		ft_medium_sort(stack_a, stack_b, bench);
	else
		ft_adaptative(stack_a, bench);
	if (flags.bench)
		ft_print_bench(stack_a, bench, bench->argv, bench->argc);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_bench		bench;
	t_flags		flags;

	if (argc < 2)
		return (0);
	stack_a = ft_add_stack(argv, argc);
	stack_b = NULL;
	if (!stack_a)
		return (-1);
	flags = check_flags(argv, argc);
	ft_initialize_count(&bench, flags.bench);
	bench.argv = argv;
	bench.argc = argc;
	ft_set_index(&stack_a, ft_lstsize(stack_a));
	choose_flags(&stack_a, &stack_b, &bench, flags);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
