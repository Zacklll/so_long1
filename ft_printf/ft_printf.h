/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:15:38 by zael-wad          #+#    #+#             */
/*   Updated: 2022/12/22 02:32:06 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_check(va_list args, char s);
int	ft_putnbr(int n);
int	ft_unsputnbr(unsigned int nb);
int	ft_hex1(unsigned long nb);
// int	ft_count(long num);
int	ft_printadd(unsigned long a);
int	ft_hex(unsigned int nb, char c);

#endif