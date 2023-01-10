/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 05:28:25 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/09 10:54:39 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_image(t_var *data, void *img, void *img2)
{
	mlx_put_image_to_window(data->mlx, data->win, img, data->colums * 50,
		data->rows * 50);
	mlx_put_image_to_window(data->mlx, data->win, img2, data->colums * 50,
		data->rows * 50);
}

static void	putimage(t_var *data, int j)
{
	if (j == 0)
		insert_image(data, data->img_ptr.img2, data->img_ptr.coin1);
	if (j == 1000)
		insert_image(data, data->img_ptr.img2, data->img_ptr.coin2);
	if (j == 2000)
		insert_image(data, data->img_ptr.img2, data->img_ptr.coin3);
	if (j == 3000)
		insert_image(data, data->img_ptr.img2, data->img_ptr.coin4);
	if (j == 4000)
		insert_image(data, data->img_ptr.img2, data->img_ptr.coin5);
	if (j == 5000)
		insert_image(data, data->img_ptr.img2, data->img_ptr.coin6);
	if (j == 6000)
		insert_image(data, data->img_ptr.img2, data->img_ptr.coin7);
	if (j == 7000)
		insert_image(data, data->img_ptr.img2, data->img_ptr.coin8);
	if (j == 8000)
		insert_image(data, data->img_ptr.img2, data->img_ptr.coin9);
}

void	image_coin(t_var *data)
{
	int	i;

	data->img_ptr.coin1 = mlx_xpm_file_to_image(data->mlx,
			"coin_images/coin1.xpm", &i, &i);
	data->img_ptr.coin2 = mlx_xpm_file_to_image(data->mlx,
			"coin_images/coin2.xpm", &i, &i);
	data->img_ptr.coin3 = mlx_xpm_file_to_image(data->mlx,
			"coin_images/coin3.xpm", &i, &i);
	data->img_ptr.coin4 = mlx_xpm_file_to_image(data->mlx,
			"coin_images/coin4.xpm", &i, &i);
	data->img_ptr.coin5 = mlx_xpm_file_to_image(data->mlx,
			"coin_images/coin5.xpm", &i, &i);
	data->img_ptr.coin6 = mlx_xpm_file_to_image(data->mlx,
			"coin_images/coin6.xpm", &i, &i);
	data->img_ptr.coin7 = mlx_xpm_file_to_image(data->mlx,
			"coin_images/coin7.xpm", &i, &i);
	data->img_ptr.coin8 = mlx_xpm_file_to_image(data->mlx,
			"coin_images/coin8.xpm", &i, &i);
	data->img_ptr.coin9 = mlx_xpm_file_to_image(data->mlx,
			"coin_images/coin9.xpm", &i, &i);
}

int	animated_coins(t_var *data)
{
	static int	j;

	data->rows = 0;
	while (data->p[data->rows])
	{
		data->colums = 0;
		while (data->p[data->rows][data->colums])
		{
			if (data->p[data->rows][data->colums] == 'C')
			{
				putimage(data, j);
			}
			data->colums++;
		}
		data->rows++;
	}
	if (j == 9000)
		j = 0;
	j++;
	return (0);
}
