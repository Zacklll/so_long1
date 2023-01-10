/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:14:24 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/06 14:04:18 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_var *data, int in)
{
	if (data->p[data->x_pos][data->y_pos + 1] == 'M')
	{
		data->p[data->x_pos][data->y_pos] = 'D';
		data->p[data->x_pos][data->y_pos + 1] = '0';
		ft_printf("KO\n");
		put_image(data);
	}
	if (data->p[data->x_pos][data->y_pos + 1] == 'C')
		data->p[data->x_pos][data->y_pos + 1] = '0';
	if (data->p[data->x_pos][data->y_pos + 1] == 'E')
		exit_handel(data);
	else
	{
		data->tmp = data->p[data->x_pos][data->y_pos + 1];
		data->p[data->x_pos][data->y_pos
			+ 1] = data->p[data->x_pos][data->y_pos];
		data->p[data->x_pos][data->y_pos] = data->tmp;
		mlx_clear_window(data->mlx, data->win);
		put_image(data);
		ft_printf("		%d steps   right\n   ", in);
		mlx_string_put(data->mlx, data->win, 10, 10, 0x00FF0000, data->nbr);
	}
}

void	move_left(t_var *data, int in)
{
	if (data->p[data->x_pos][data->y_pos - 1] == 'M')
	{
		data->p[data->x_pos][data->y_pos] = 'D';
		data->p[data->x_pos][data->y_pos - 1] = '0';
		ft_printf("KO\n");
		put_image(data);
	}
	if (data->p[data->x_pos][data->y_pos - 1] == 'C')
		data->p[data->x_pos][data->y_pos - 1] = '0';
	if (data->p[data->x_pos][data->y_pos - 1] == 'E')
		exit_handel(data);
	else
	{
		data->tmp = data->p[data->x_pos][data->y_pos - 1];
		data->p[data->x_pos][data->y_pos
			- 1] = data->p[data->x_pos][data->y_pos];
		data->p[data->x_pos][data->y_pos] = data->tmp;
		mlx_clear_window(data->mlx, data->win);
		put_image(data);
		ft_printf("		%d steps    left\n    ", in);
		mlx_string_put(data->mlx, data->win, 10, 10, 0x00FF0000, data->nbr);
	}
}

void	move_down(t_var *data, int in)
{
	if (data->p[data->x_pos + 1][data->y_pos] == 'M')
	{
		data->p[data->x_pos][data->y_pos] = 'D';
		data->p[data->x_pos + 1][data->y_pos] = '0';
		ft_printf("KO\n");
		put_image(data);
	}
	if (data->p[data->x_pos + 1][data->y_pos] == 'C')
		data->p[data->x_pos + 1][data->y_pos] = '0';
	if (data->p[data->x_pos + 1][data->y_pos] == 'E')
		exit_handel(data);
	else
	{
		data->tmp = data->p[data->x_pos + 1][data->y_pos];
		data->p[data->x_pos
			+ 1][data->y_pos] = data->p[data->x_pos][data->y_pos];
		data->p[data->x_pos][data->y_pos] = data->tmp;
		mlx_clear_window(data->mlx, data->win);
		put_image(data);
		ft_printf("		%d steps    down\n    ", in);
		mlx_string_put(data->mlx, data->win, 10, 10, 0x00FF0000, data->nbr);
	}
}

void	move_up(t_var *data, int in)
{
	if (data->p[data->x_pos - 1][data->y_pos] == 'M')
	{
		data->p[data->x_pos][data->y_pos] = 'D';
		data->p[data->x_pos - 1][data->y_pos] = '0';
		ft_printf("KO\n");
		put_image(data);
	}
	if (data->p[data->x_pos - 1][data->y_pos] == 'C')
		data->p[data->x_pos - 1][data->y_pos] = '0';
	if (data->p[data->x_pos - 1][data->y_pos] == 'E')
		exit_handel(data);
	else
	{
		data->tmp = data->p[data->x_pos - 1][data->y_pos];
		data->p[data->x_pos
			- 1][data->y_pos] = data->p[data->x_pos][data->y_pos];
		data->p[data->x_pos][data->y_pos] = data->tmp;
		mlx_clear_window(data->mlx, data->win);
		put_image(data);
		ft_printf("		%d steps    up\n  ", in);
		mlx_string_put(data->mlx, data->win, 10, 10, 0x00FF0000, data->nbr);
	}
}

void	exit_handel(t_var *data)
{
	if (count_coins(data) == 0)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
}
