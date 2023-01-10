/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:10:44 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/05 15:54:10 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	to_find(int num)
{
	int	nb;

	nb = 0;
	if (num == 0)
		nb++;
	if (num < 0)
		nb++;
	while (num != 0)
	{
		num /= 10;
		nb++;
	}
	return (nb);
}

static char	*count(int nbr, char *str, int i)
{
	int	j;

	if (nbr == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	j = i - 1;
	while (nbr > 0)
	{
		str[j] = nbr % 10 + '0';
		nbr /= 10;
		j--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	i = to_find(nbr);
	str = malloc(i + 1);
	if (!str)
		return (0);
	str = count(nbr, str, i);
	return (str);
}
