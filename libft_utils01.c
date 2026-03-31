/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:40:16 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/15 14:27:22 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	while (i < size * nmemb)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *s)
{
	size_t	length;
	size_t	icopy;
	char	*ptr;

	length = 0;
	icopy = 0;
	while (s[length])
		length++;
	ptr = malloc(sizeof(char) * (length + 1));
	if (ptr == NULL)
		return (NULL);
	while (icopy < length)
	{
		ptr[icopy] = s[icopy];
		icopy++;
	}
	ptr[icopy] = '\0';
	return (ptr);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*del_lst_before;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	del_lst_before = *lst;
	while (current != NULL)
	{
		del(current->content);
		current = current->next;
		free(del_lst_before);
		del_lst_before = current;
	}
	*lst = NULL;
}
