/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firahari <firahari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:20:08 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/13 12:58:47 by firahari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	ft_choose_method(t_list **stack, char **argv,
			int argc, t_bench *bench)
{
	t_flags	flags;
	t_list	*stack_b;

	stack_b = NULL;
	flags = check_flags(argv, argc);
	if (flags.simple)
	{
		bench->strategy = " Simple / O(n²)";
		ft_simple_sort(stack, bench);
	}
	else if (flags.complex)
	{
		bench->strategy = " Complex / O(n√n)";
		ft_complex_sort(stack, bench);
	}
	else if (flags.medium)
	{
		bench->strategy = " Medium / O(nlogn)";
		ft_medium_sort(stack, &stack_b, bench);
	}
	else
		ft_adaptative(stack, bench);
}

static void	ft_print_help1(t_bench *bench, double d)
{
	int	fd;

	fd = bench->fd;
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_double_fd(d, fd);
	ft_putstr_fd("%\n", fd);
	ft_putstr_fd("[bench] Strategy:", fd);
	ft_putstr_fd(bench->strategy, fd);
	ft_putstr_fd("\n[bench] total_ops: ", fd);
	ft_putnbr_fd(bench->total, fd);
	ft_putstr_fd("\n", fd);
}

static void	ft_print_help2(t_bench *bench)
{
	int	fd;

	fd = bench->fd;
	ft_putstr_fd("[bench] sa: ", fd);
	ft_putnbr_fd(bench->sa, fd);
	ft_putstr_fd(" sb: ", fd);
	ft_putnbr_fd(bench->sb, fd);
	ft_putstr_fd(" ss: ", fd);
	ft_putnbr_fd(bench->ss, fd);
	ft_putstr_fd(" pa:  ", fd);
	ft_putnbr_fd(bench->pa, fd);
	ft_putstr_fd(" pb:  ", fd);
	ft_putnbr_fd(bench->pb, fd);
	ft_putstr_fd("\n[bench] ra: ", fd);
	ft_putnbr_fd(bench->ra, fd);
}

static void	ft_print_help3(t_bench *bench)
{
	int	fd;

	fd = bench->fd;
	ft_putstr_fd(" rb: ", fd);
	ft_putnbr_fd(bench->rb, fd);
	ft_putstr_fd(" rr: ", fd);
	ft_putnbr_fd(bench->rr, fd);
	ft_putstr_fd(" rra: ", fd);
	ft_putnbr_fd(bench->rra, fd);
	ft_putstr_fd(" rrb: ", fd);
	ft_putnbr_fd(bench->rrb, fd);
	ft_putstr_fd(" rrr: ", fd);
	ft_putnbr_fd(bench->rrr, fd);
	ft_putstr_fd("\n", fd);
}

void	ft_print_bench(t_list **stack, t_bench *bench, char **argv, int argc)
{
	double	d;

	d = ft_compute_disorder(stack);
	if (bench->is_checker)
	{
		ft_choose_adaptive(stack, argv, argc, bench);
		ft_choose_method(stack, argv, argc, bench);
	}
	ft_print_help1(bench, d);
	ft_print_help2(bench);
	ft_print_help3(bench);
}
