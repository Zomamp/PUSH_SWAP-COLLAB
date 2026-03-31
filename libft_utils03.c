/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:22:19 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/11 17:57:22 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_word(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t len)
{
	size_t	icopy;
	char	*ptr;

	icopy = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (s[icopy] && icopy < len)
	{
		ptr[icopy] = s[icopy];
		icopy++;
	}
	ptr[icopy] = '\0';
	return (ptr);
}

static void	*free_tb(char **ptr_tb, int j)
{
	while (0 < j)
	{
		j--;
		free(ptr_tb[j]);
	}
	free(ptr_tb);
	return (NULL);
}

static char	**split_loop(char const *s, char c, char **ptr_tb)
{
	size_t	i;
	size_t	start;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i - start > 0)
		{
			ptr_tb[j] = ft_strndup(s + start, i - start);
			if (!ptr_tb[j])
				return (free_tb(ptr_tb, j));
			j++;
		}
	}
	ptr_tb[j] = NULL;
	return (ptr_tb);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_tb;
	char	**result;

	if (!s)
		return (NULL);
	ptr_tb = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!ptr_tb)
		return (NULL);
	result = split_loop(s, c, ptr_tb);
	return (result);
}
