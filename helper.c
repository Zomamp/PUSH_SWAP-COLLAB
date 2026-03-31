/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 20:50:34 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/23 09:54:31 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tb)
{
	int	i;

	i = 0;
	while (tb[i])
	{
		free(tb[i]);
		i++;
	}
	free(tb);
}

void	free_z(char **tb, int z)
{
	while (z > 0)
	{
		z--;
		free(tb[z]);
	}
	free(tb);
}

int	check_stack(t_stack_info *stack_a, t_stack_info *stack_b, char **args)
{
	if (!stack_a || !stack_b)
	{
		free_tab(args);
		free_stacks(stack_a, stack_b);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

double	compute_disorder(t_stack_info *stack_a)
{
	int		mistakes;
	int		total_pairs;
	double	result;
	t_list	*current_node;
	t_list	*next_node;

	mistakes = 0;
	total_pairs = 0;
	current_node = stack_a->top;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		while (next_node != NULL)
		{
			if (*(int *)current_node->content > *(int *)next_node->content)
				mistakes++;
			total_pairs++;
			next_node = next_node->next;
		}
		current_node = current_node->next;
	}
	if (total_pairs == 0)
		return (0.0);
	result = (double)mistakes / total_pairs;
	return (result);
}
