/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <:zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:12:30 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/02/17 21:09:03 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int			i;
	size_t		j;

	i = 0;
	j = 0;
	j = ft_strlen(dst);
	if (size <= j)
		return (ft_strlen(src) + size);
	while (src[i] && (j + i) < size - 1)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (j + ft_strlen((char *)src));
}
