/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:22:58 by hemanamp          #+#    #+#             */
/*   Updated: 2026/03/15 15:16:11 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	return (write(2, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
	}
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	nb;
	int				len_base;
	int				count;

	nb = n;
	count = 0;
	len_base = 0;
	while (base[len_base])
		len_base++;
	if (nb >= (unsigned long)len_base)
	{
		count += ft_putnbr_base((nb / len_base), base);
	}
	count += ft_putchar(base[nb % len_base]);
	return (count);
}
