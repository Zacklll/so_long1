/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:14:08 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/05 15:33:45 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	player_position(t_var *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->p[x])
	{
		y = 0;
		while (data->p[x][y])
		{
			if (data->p[x][y] == 'P')
			{
				data->x_pos = x;
				data->y_pos = y;
			}
			if (data->p[x][y] == 'E')
			{
				data->exit_xpos = x;
				data->exit_ypos = y;
			}
			y++;
		}
		x++;
	}
}

int	count_coins(t_var *data)
{
	int	x;
	int	y;
	int	cpt;

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
