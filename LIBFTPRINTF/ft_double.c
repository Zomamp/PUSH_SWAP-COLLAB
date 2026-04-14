/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 22:59:21 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/09 06:32:57 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_double_fd(double nbr, int fd)
{
	double	right;
	int		left;
	int		count;

	count = 0;
	left = (int)nbr;
	right = nbr - left;
	if (nbr < 0)
	{
		count += write(fd, "-", 1);
		left = -left;
		right = -right;
	}
	count += ft_putnbr_fd(left, fd);
	count += write(fd, ".", 1);
	right = right * 100 + 0.5;
	if ((int)right >= 100)
	{
		left += 1;
		right = 0;
	}
	count += ft_putnbr_fd((int)right, fd);
	return (count);
}
