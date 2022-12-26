/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:14:08 by zael-wad          #+#    #+#             */
/*   Updated: 2022/12/26 17:20:08 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	player_position(t_var *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->p[y])
	{
		x = 0;
		while (data->p[y][x])
		{
			if (data->p[y][x] == 'P')
			{
				data->x_pos = x;
				data->y_pos = y;
			}
			x++;
		}
		y++;
	}
}

int	count_coins(t_var *data)
{
	int x;
	int y;
	int cpt;

	x = 0;
	cpt = 0;
	while (data->p[x])
	{
		y = 0;
		while (data->p[x][y])
		{
			if (data->p[x][y] == 'C')
				cpt++;
			y++;
		}
		x++;
	}
	return (cpt);
}