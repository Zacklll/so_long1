/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:50:35 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/10 14:47:44 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	invalid_map()
{
	ft_printf("invalide map\n");
	exit (0);
}

void	cheack_boundaries(t_var *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->p[0][y])
	{
		if (data->p[0][y] != '1')
			invalid_map();
		y++;
	}
	y = 0;
	while (data->p[data->x_last - 1][y])
	{
		if (data->p[data->x_last - 1][y] != '1')
			invalid_map();
		y++;
	}
	while (data->p[x])
	{
		if (data->p[x][0] != '1' || data->p[x][y - 1] != '1')
			invalid_map();
		x++;
	}
}

void	check_map(t_var *data)
{
	int	x;
	int	y;

	data->len = strlen(data->p[0]);
	x = 1;
	while (data->p[x])
	{
		y = 0;
		while (data->p[x][y])
			y++;
		if (y != data->len)
			invalid_map();
		x++;
	}
	data->x_last = x;
}

void	check_rep(t_var *data)
{
	int	x;
	int	y;
	int	player;
	int	exi;

	x = 0;
	player = 0;
	exi = 0;
	while (data->p[x])
	{
		y = 0;
		while (data->p[x][y])
		{
			if (data->p[x][y] == 'P')
				player++;
			if (data->p[x][y] == 'E')
				exi++;
			y++;
		}
		x++;
	}
	if (player != 1 || exi != 1)
	{
		ft_printf("map must have at least one exit & one player\n");
		exit(0);
	}
}

int	x_width(char **p)
{
	int	i;
	int	j;

	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
			j++;
		i++;
	}
	return (j * 50);
}

int	y_height(char **p)
{
	int	y;

	y = 0;
	while (p[y])
		y++;
	return (y * 50);
}
