/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:18:20 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/05 15:50:39 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdio.h>

static int	up(t_var *data, int in)
{
	move_up(data, in);
	return (in);
}

static int	down(t_var *data, int in)
{
	move_down(data, in);
	return (in);
}

static int	left(t_var *data, int in)
{
	move_left(data, in);
	return (in);
}

static int	right(t_var *data, int in)
{
	move_right(data, in);
	return (in);
}

int	key_press(int i, t_var *data)
{
	static int	in;
	char		*tmp;

	player_position(data);
	data->nbr = ft_itoa(in);
	if (i == 53)
		destroy_fun(data);
	else if ((i == 126) && data->p[data->x_pos - 1][data->y_pos] != '1'
			&& data->p[data->x_pos][data->y_pos] == 'P')
		up(data, in++);
	else if ((i == 125) && data->p[data->x_pos + 1][data->y_pos] != '1'
			&& data->p[data->x_pos][data->y_pos] == 'P')
		down(data, in++);
	else if ((i == 123) && data->p[data->x_pos][data->y_pos - 1] != '1'
			&& data->p[data->x_pos][data->y_pos] == 'P')
		left(data, in++);
	else if ((i == 124) && data->p[data->x_pos][data->y_pos + 1] != '1'
			&& data->p[data->x_pos][data->y_pos] == 'P')
		right(data, in++);
	tmp = data->nbr;
	free(data->nbr);
	data->nbr = tmp;
	return (0);
}
