/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 22:59:21 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/27 01:57:28 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_double(double nbr)
{
	double	right;
	int		left;
	int		count;

	left = (int)nbr;
	right = nbr - left;
	count = 0;
	if (left < 0)
	{
		count += write(1, "-", 1);
		right *= (-1);
		left *= (-1);
	}
	count += ft_putnbr(left);
	count += write(1, ".", 1);
	right *= 100;
	count += ft_putnbr((int)right);
	return (count);
}