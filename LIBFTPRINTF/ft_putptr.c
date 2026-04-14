/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <zo-rakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:01:21 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/04/06 22:41:14 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;	

	count = 0;
	if (!ptr)
		return (write (1, "(nil)", 5));
	count = write (1, "0x", 2);
	count += ft_puthex((unsigned long)ptr);
	return (count);
}
