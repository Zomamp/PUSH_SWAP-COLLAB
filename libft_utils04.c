/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils04.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajonso <arajonso@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:32:09 by arajonso          #+#    #+#             */
/*   Updated: 2026/03/14 15:16:10 by arajonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void	put_double_fd(double n, int decimals, int fd)
{
	int		before_coma;
	int		after_coma;
	double	calcul;
	int		i;

	calcul = 1;
	i = 0;
	while (i < decimals)
	{
		calcul *= 10;
		i++;
	}
	before_coma = (int)n;
	after_coma = (int)((n - before_coma) * calcul);
	ft_putnbr_fd(before_coma, fd);
	ft_putchar_fd('.', fd);
	while (i > 0)
	{
		if (after_coma < (int)(calcul / 10))
			ft_putchar_fd('0', fd);
		calcul /= 10;
		i--;
	}
	ft_putnbr_fd(after_coma, fd);
}
