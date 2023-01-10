/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:45:59 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/06 15:08:59 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_press(t_var *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void	destroy_fun(t_var *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	check_path_coins(int x, int y, char **tab, t_var *data)
{
	if (x < 0 || x >= data->x_last || y < 0 || y >= data->len)
		return ;
	if (tab[x][y] == '1' || tab[x][y] == 'M' || tab[x][y] == 'E')
		return ;
	if (tab[x][y] == 'C')
		data->count_coins++;
	tab[x][y] = '1';
	check_path_coins(x + 1, y, tab, data);
	check_path_coins(x - 1, y, tab, data);
	check_path_coins(x, y + 1, tab, data);
	check_path_coins(x, y - 1, tab, data);
}

int	check_pathto(int x, int y, char **tab1, t_var *data)
{
	if (x < 0 || x >= data->x_last || y < 0 || y >= data->len)
		return (0);
	if (x == data->exit_xpos && y == data->exit_ypos)
		return (1);
	if (tab1[x][y] == '1' || tab1[x][y] == 'M')
		return (0);
	tab1[x][y] = '1';
	if (check_pathto(x + 1, y, tab1, data))
		return (1);
	if (check_pathto(x, y + 1, tab1, data))
		return (1);
	if (check_pathto(x - 1, y, tab1, data))
		return (1);
	if (check_pathto(x, y - 1, tab1, data))
		return (1);
	return (0);
}
