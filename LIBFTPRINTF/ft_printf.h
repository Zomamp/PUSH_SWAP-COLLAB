/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:22:48 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/08 21:38:49 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_puthex(long nbr);
int		ft_putptr(void *ptr);
int		ft_put_u(unsigned long u);
int		ft_putuphex(unsigned int nbr);
int		ft_puti(long nbr);
int		ft_double_fd(double nbr, int fd);
int		ft_putnbr_fd(int n, int fd);

#endif