/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:18:06 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/20 13:29:08 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*init_bench(void)
{
	t_bench	*bench;

	bench = ft_calloc(1, sizeof(t_bench));
	if (!bench)
		return (NULL);
	return (bench);
}

static char	*get_method_name(t_var *var)
{
	if (var->method == 1)
		return ("Simple / O(n²)");
	if (var->method == 2)
		return ("Medium / O(n√n)");
	if (var->method == 3)
		return ("Complex / O(n log n)");
	if (var->disorder < 0.2)
		return ("Adaptive / O(n²)");
	if (var->disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}

static void	display_nbr_operations(t_var *var)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(var->bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(var->bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(var->bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(var->bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(var->bench->pb, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(var->bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(var->bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(var->bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(var->bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(var->bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(var->bench->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	display_bench(t_var *var)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_double_fd(var->disorder * 100, 2, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(get_method_name(var), 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(var->bench->total, 2);
	ft_putchar_fd('\n', 2);
	display_nbr_operations(var);
}
