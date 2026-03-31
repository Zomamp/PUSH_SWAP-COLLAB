/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <:zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:32:45 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/02/17 05:20:48 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*concate;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	concate = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!concate)
		return (NULL);
	while (s1[i] != '\0')
	{
		concate[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		concate[i + j] = s2[j];
		j++;
	}
	concate[i + j] = '\0';
	return (concate);
}
