/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:57:42 by zael-wad          #+#    #+#             */
/*   Updated: 2022/11/04 19:09:28 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int	ft_check(va_list args, char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	if (s == 's')
		count += ft_putstr(va_arg(args, char *));
	if (s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (s == 'u')
		count += ft_unsputnbr(va_arg(args, unsigned long));
	if (s == 'x' || s == 'X')
		count += ft_hex(va_arg(args, unsigned long), s);
	if (s == 'p')
		count += ft_printadd(va_arg(args, unsigned long));
	if (s == '%')
		count += ft_putchar('%');
	return (count);
}
