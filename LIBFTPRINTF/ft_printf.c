/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:13:09 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/17 23:22:05 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_convert(char s, va_list ap)
{
	int		count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (s == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (s == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (s == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (s == 'u')
		count += ft_put_u(va_arg(ap, unsigned int));
	else if (s == 'x')
		count += ft_puthex(va_arg(ap, unsigned int));
	else if (s == 'X')
		count += ft_putuphex(va_arg(ap, unsigned int));
	else if (s == 'i')
		count += ft_puti(va_arg(ap, int));
	else if (s == 'f')
		count +=  ft_double(va_arg(ap, double));
	else if (s == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		arg;
	int			result;

	va_start(arg, format);
	result = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			result += ft_convert(format[++i], arg);
		else
			result += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (result);
}
