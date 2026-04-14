/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <:zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:00:36 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/02/20 20:18:32 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned long u)
{
	int	count;

	count = 0;
	if (u > 9)
	{
		count += ft_putnbr(u / 10);
	}
	count += ft_putchar((u % 10) + '0');
	return (count);
}
