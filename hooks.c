/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:18:20 by zael-wad          #+#    #+#             */
/*   Updated: 2022/12/26 15:20:39 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <mlx.h>
#include <stdio.h>

int	up(t_var *data, int in)
{
	move_up(data);
	mlx_string_put(data->mlx, data->win, 10, 10, 0x00FF0000, data->nbr);
	return (in);
}

void	down(t_var *data, int in)
{
	move_down(data);
	ft_printf("    Moves : %d move \n", in++);
	mlx_string_put(data->mlx, data->win, 10, 10, 0x00FF0000, data->nbr);
}

void	left(t_var *data, int in)
{
	move_left(data);
	ft_printf("    Moves : %d move \n", in++);
	mlx_string_put(data->mlx, data->win, 10, 10, 0x00FF0000, data->nbr);
}

void	right(t_var *data, int in)
{
	move_right(data);
	ft_printf("    Moves : %d move \n", in++);
	mlx_string_put(data->mlx, data->win, 10, 10, 0x00FF0000, data->nbr);
}

void	exit_game(t_var *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	mouse_press(t_var *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	key_press(int i, t_var *data)
{
	// count_coins(data);
	player_position(data);
	static int in = 1;

	data->nbr = ft_itoa(in);
	if (i == 53)
		exit_game(data);
	else if ((i == 126 || i == 13) && data->p[data->y_pos - 1][data->x_pos] != '1' && data->p[data->y_pos][data->x_pos] == 'P')
		up(data, in++);
	else if ((i == 125 || i == 1) && data->p[data->y_pos
			+ 1][data->x_pos] != '1'
			&& data->p[data->y_pos][data->x_pos] == 'P')
		down(data, in++);
	else if ((i == 123 || i == 0) && data->p[data->y_pos][data->x_pos
			- 1] != '1' && data->p[data->y_pos][data->x_pos] == 'P')
		left(data, in++);
	else if ((i == 124 || i == 2) && (data->p[data->y_pos][data->x_pos
				+ 1] != '1') && data->p[data->y_pos][data->x_pos] == 'P')
		right(data, in++);
	return (in);
}