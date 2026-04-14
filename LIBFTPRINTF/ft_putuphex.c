/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:16:26 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/07 06:26:51 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuphex(unsigned int nbr)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_putuphex(nbr / 16);
	count += write(1, &base[nbr % 16], 1);
	return (count);
}
