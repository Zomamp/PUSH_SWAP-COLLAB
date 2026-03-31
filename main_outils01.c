/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_outils01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 08:31:26 by hemanamp          #+#    #+#             */
/*   Updated: 2026/03/20 14:09:40 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initiate(t_var *var)
{
	var->stack_a = init_stack();
	var->stack_b = init_stack();
	var->bench = init_bench();
	if (!var->stack_a || !var->stack_b || !var->bench)
	{
		free_stacks(var->stack_a, var->stack_b);
		free(var->bench);
		return (1);
	}
	return (0);
}

void	init_variable(t_var *var)
{
	var->start = 1;
	var->bench_mode = 0;
	var->disorder = 0.0;
	var->method = 0;
	var->stack_a = NULL;
	var->stack_b = NULL;
	var->bench = NULL;
	var->args = NULL;
}

int	ready_stack(t_var *var)
{
	if (check_stack(var->stack_a, var->stack_b, var->args) == 1)
	{
		free(var->bench);
		return (1);
	}
	if (fill_stack(var->stack_a, var->stack_b, var->args) == 1)
	{
		free(var->bench);
		free_tab(var->args);
		return (1);
	}
	indexation(var->stack_a);
	free_tab(var->args);
	var->args = NULL;
	if (is_sorted(var->stack_a) == 0)
		return (2);
	return (0);
}

void	sorting(t_var *var)
{
	if (var->method == 1)
		sort_simple(var->stack_a, var->stack_b, var->bench);
	else if (var->method == 2)
		sort_medium(var->stack_a, var->stack_b, var->bench);
	else if (var->method == 3)
		sort_complex(var->stack_a, var->stack_b, var->bench);
	else
		sort_adaptive(var->stack_a, var->stack_b, var->disorder, var->bench);
}
