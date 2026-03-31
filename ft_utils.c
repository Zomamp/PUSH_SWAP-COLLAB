/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:44:36 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/30 15:13:46 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_list	*ft_add_stack(char **argv, int argc)
{
	t_list	*stack_a;
	t_list	*new;
	int		i;
	int		*cast;

	// i = 1 cause if we have i = 0, so we call the name of the program
	// Example : ./a.out 42 == if i = 0, so we print "./a.out" , not 42 
	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		cast = malloc(sizeof(int));
		if (!cast)
		{
			ft_lstclear(&stack_a, free);
			return (NULL);
		}
		// Using atoi for the convertion , ex if we have "42" == atoi == 42
		*cast = ft_atoi(argv[i]);
		new = ft_lstnew(cast);
		if (!new)
		{
			// Deleting the list and free the memories
			ft_lstclear(&stack_a, free);
			return (NULL);
		}
		ft_lstadd_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}

void	ft_print_list(t_list *stack_a)
{
	// Error
	if (!stack_a)
		ft_putstr_fd("[]", 2);
	// while stack_a exist
	while (stack_a)
	{
		ft_printf("%d ", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
}

int	ft_find_bigest(t_list **stack)
{
	int		big;
	t_list	*tmp;
	
	big = INT_MIN;
	tmp = *stack;
	while (tmp)
	{
		if (*(int *)tmp->content > big)
			big = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (big);
}

int	ft_find_min(t_list **stack)
{
	t_list		*tmp;
	int			min;
	int			index;
	int			min_index;
	int			size;
	t_bench		bench;

	tmp = *stack;
	min = INT_MAX;
	index = 0;
	min_index = 0;

	while (tmp)
	{
		if (*(int *)tmp->content < min)
		{
			min = *(int *)tmp->content;
			min_index = index; // Mis a jour de la valeur minimal de l'index
		}
		tmp = tmp->next;
		index++;
	}

	size = index;
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
			ft_ra(stack, &bench);
	}
	else
	{
		int moves = size - min_index;
		while (moves-- > 0)
			ft_rra(stack, &bench);
	}
	return (min);
}

int	ft_is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (!tmp || !(tmp)->next)
		return (1);
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_search_max_bit(t_list **stack)
{
	int		max;
	t_list	*tmp;
	
	if (!stack || !*stack)
		return (-1);
	max = (*stack)->index;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}