/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <:zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:21:38 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/02/07 15:57:55 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*begin;

	if (size != 0 && nmemb > ((size_t) - 1) / size)
		return (NULL);
	begin = malloc(nmemb * size);
	if (!begin)
		return (NULL);
	ft_memset(begin, 0, nmemb * size);
	return (begin);
}
