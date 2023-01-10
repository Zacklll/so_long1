/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:00:32 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/06 12:01:27 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(char *str1, char *str2, size_t size)
{
	size_t	i;

	i = 0;
	while ((i < size) && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}
