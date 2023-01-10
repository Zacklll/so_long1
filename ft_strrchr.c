/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:49:40 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/06 12:00:57 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(char *str, int arg)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	while (len >= 0)
	{
		if (str[len] == (unsigned char)arg)
			return ((char *)str + len);
		if (len == 0)
			break ;
		len--;
	}
	return (NULL);
}
