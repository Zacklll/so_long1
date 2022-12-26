/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:09:06 by zael-wad          #+#    #+#             */
/*   Updated: 2022/12/22 02:22:06 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			count += ft_check(args, str[i]);
		}
		else if (str[i] != '%' && str[i])
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
