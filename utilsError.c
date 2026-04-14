/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firahari <firahari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:22:15 by firahari          #+#    #+#             */
/*   Updated: 2026/03/19 15:20:09 by firahari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_list	*find_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	atol_helper(char *str, int i, long *nb)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if (*nb > (LONG_MAX - (str[i] - '0')) / 10)
			return (0);
		*nb = *nb * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	nb;
	int		i;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (LONG_MAX);
	if (!atol_helper(str, i, &nb))
		return (LONG_MAX);
	return (nb * sign);
}

void	append_node(t_list **stack, int n)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->nb = n;
	node->next = NULL;
	if (*stack == NULL)
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
