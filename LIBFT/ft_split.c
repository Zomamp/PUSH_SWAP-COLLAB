/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <:zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:20:18 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/02/15 23:37:42 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *str, int c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_put_word(char const *str, int start, int end)
{
	char	*stock;
	int		i;

	stock = malloc(sizeof(char) * (end - start + 1));
	if (!stock)
		return (NULL);
	i = 0;
	while (start < end)
	{
		stock[i] = str[start];
		start++;
		i++;
	}
	stock[i] = '\0';
	return (stock);
}

static void	ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static int	ft_split_helper(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tab[j++] = ft_put_word(s, start, i);
			if (!tab[j - 1])
			{
				ft_free(tab, j - 1);
				return (0);
			}
			start = -1;
		}
		i++;
	}
	tab[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_count(s, c);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	if (!ft_split_helper(s, c, tab))
		return (NULL);
	return (tab);
}
