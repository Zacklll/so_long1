/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:12:47 by zael-wad          #+#    #+#             */
/*   Updated: 2022/11/04 20:39:20 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_hex(unsigned int nb, char c)
{
	int		count;
	char	*x;
	char	*upx;

	count = 0;
	x = "0123456789abcdef";
	upx = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_hex(nb / 16, c);
		count += ft_hex(nb % 16, c);
	}
	if (nb < 16)
	{
		if (c == 'X')
			count += ft_putchar(upx[nb % 16]);
		else
			count += ft_putchar(x[nb % 16]);
	}
	return (count);
}

int	ft_unsputnbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_unsputnbr(nb / 10);
		count += ft_unsputnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb % 10 + '0');
		count++;
	}
	return (count);
}

int	ft_printadd(unsigned long a)
{
	char	c;
	int		count;

	count = 2;
	c = 'x';
	write(1, "0x", 2);
	count += ft_hex1(a);
	return (count);
}

int	ft_hex1(unsigned long nb)
{
	int		count;
	char	*x;

	count = 0;
	x = "0123456789abcdef";
	if (nb >= 16)
	{
		count += ft_hex1(nb / 16);
		count += ft_hex1(nb % 16);
	}
	if (nb < 16)
		count += ft_putchar(x[nb % 16]);
	return (count);
}
