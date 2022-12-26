/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:14:24 by zael-wad          #+#    #+#             */
/*   Updated: 2022/12/26 15:23:36 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_var *data)
{
	if (data->p[data->y_pos][data->x_pos + 1] == 'M')
	{
		data->p[data->y_pos][data->x_pos] = 'D';
		data->p[data->y_pos][data->x_pos + 1] = '0';
		printf("KO\n");
		put_image(data);
	}
	if (data->p[data->y_pos][data->x_pos + 1] == 'C')
		data->p[data->y_pos][data->x_pos + 1] = '0';
	if (data->p[data->y_pos][data->x_pos + 1] == 'E')
	{
		data->p[data->y_pos][data->x_pos] = 'P';
		if (count_coins(data) == 0)
		{
			mlx_destroy_image(data->mlx, data->win);
			exit(0);
		}
	}
		data->tmp = data->p[data->y_pos][data->x_pos + 1];
		data->p[data->y_pos][data->x_pos + 1] = data->p[data->y_pos][data->x_pos];
		data->p[data->y_pos][data->x_pos] = data->tmp;
		mlx_clear_window(data->mlx, data->win);
		put_image(data);
		ft_printf("    right   ");
}

void	move_left(t_var *data)
{
	if (data->p[data->y_pos][data->x_pos - 1] == 'M')
	{
		data->p[data->y_pos][data->x_pos] = 'D';
		data->p[data->y_pos][data->x_pos - 1] = '0';
		printf("KO\n");
		put_image(data);
	}
	if (data->p[data->y_pos][data->x_pos - 1] == 'C')
		data->p[data->y_pos][data->x_pos - 1] = '0';
	if (data->p[data->y_pos][data->x_pos - 1] == 'E')
	{
		data->p[data->y_pos][data->x_pos] = 'P';
		if (count_coins(data) == 0)
		{
			mlx_destroy_image(data->mlx, data->win);
			exit(0);
		}
	}
	else
	{
		data->tmp = data->p[data->y_pos][data->x_pos - 1];
		data->p[data->y_pos][data->x_pos - 1] = data->p[data->y_pos][data->x_pos];
		data->p[data->y_pos][data->x_pos] = data->tmp;
		mlx_clear_window(data->mlx, data->win);
		put_image(data);
		ft_printf("    left    ");
	}
}

void	move_down(t_var *data)
{
	if (data->p[data->y_pos + 1][data->x_pos] == 'M')
	{
		data->p[data->y_pos][data->x_pos] = 'D';
		data->p[data->y_pos + 1][data->x_pos] = '0';
		printf("KO\n");
		put_image(data);
	}
	if (data->p[data->y_pos + 1][data->x_pos] == 'C')
		data->p[data->y_pos + 1][data->x_pos] = '0';
	if (data->p[data->y_pos + 1][data->x_pos] == 'E')
	{
		data->p[data->y_pos][data->x_pos] = 'P';
		if (count_coins(data) == 0)
		{
			mlx_destroy_image(data->mlx, data->win);
			exit(0);
		}
	}
	else 
	{
		data->tmp = data->p[data->y_pos + 1][data->x_pos];
		data->p[data->y_pos + 1][data->x_pos] = data->p[data->y_pos][data->x_pos];
		data->p[data->y_pos][data->x_pos] = data->tmp;
		mlx_clear_window(data->mlx, data->win);
		put_image(data);
		ft_printf("    down    ");
	}
}

void	move_up(t_var *data)
{
	if (data->p[data->y_pos - 1][data->x_pos] == 'M')
	{
		data->p[data->y_pos][data->x_pos] = 'D';
		data->p[data->y_pos - 1][data->x_pos] = '0';
		printf("KO\n");
		put_image(data);
	}
	if (data->p[data->y_pos - 1][data->x_pos] == 'C')
		data->p[data->y_pos - 1][data->x_pos] = '0';
	if (data->p[data->y_pos - 1][data->x_pos] == 'E')
	{
		data->p[data->y_pos][data->x_pos] = 'P';
		if (count_coins(data) == 0)
		{
			mlx_destroy_image(data->mlx, data->win);
			exit(0);
		}
	}
	else 
	{
		data->tmp = data->p[data->y_pos - 1][data->x_pos];
		data->p[data->y_pos - 1][data->x_pos] = data->p[data->y_pos][data->x_pos];
		data->p[data->y_pos][data->x_pos] = data->tmp;
		mlx_clear_window(data->mlx, data->win);
		put_image(data);
		ft_printf("    up  ");
	}
}