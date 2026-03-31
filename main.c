/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 22:14:43 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/31 08:29:40 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	main (int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_bench	bench;
	double	d;
	
	if (argc < 2)
		return (-1);
	ft_initialize_count(&bench);
	stack_a = ft_add_stack(argv, argc);
	stack_b = NULL;
	if (!stack_a)
	{
		ft_printf("Error in the list creation");
		return (-1);
	}
	ft_printf("The stack is created : ");

	/*********INDEXION *******************************/

	ft_set_index(&stack_a, ft_lstsize(stack_a));
		
	/*****************DISORDERS***********************/
	d = ft_compute_disorder(&stack_a);
	ft_putchar('\n');
	ft_printf("Disorder: %f%%\n", d);

	/*****************SIMPLE***********************/
	ft_medium_sort(&stack_a, &stack_b, &bench);
	ft_print_bench(&stack_a, &bench, d);
	ft_print_list(stack_a);

	// clear all t_list for no leaks
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
