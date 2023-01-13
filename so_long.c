/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:28:03 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/12 00:00:32 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdio.h>

static void	check_chr(t_var *data)
{
	if (data->p[data->rows][data->colums] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img,
			data->colums * 50, data->rows * 50);
	else if (data->p[data->rows][data->colums] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2,
			data->colums * 50, data->rows * 50);
	else if (data->p[data->rows][data->colums] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2,
			data->colums * 50, data->rows * 50);
	else if (data->p[data->rows][data->colums] == 'P')
		insert_image(data, data->img_ptr.img2, data->img_ptr.img3);
	else if (data->p[data->rows][data->colums] == 'M')
		insert_image(data, data->img_ptr.img2, data->img_ptr.img1);
	else if (data->p[data->rows][data->colums] == 'D')
		insert_image(data, data->img_ptr.img2, data->img_ptr.img6);
	else if (data->p[data->rows][data->colums] == 'E')
	{
		if (count_coins(data) == 0)
			insert_image(data, data->img_ptr.img2, data->img_ptr.img7);
		else
			insert_image(data, data->img_ptr.img2, data->img_ptr.img4);
	}
	else
		destroy_fun(data);
}

void	put_image(t_var *data)
{
	data->rows = 0;
	while (data->p[data->rows])
	{
		data->colums = 0;
		while (data->p[data->rows][data->colums])
		{
			check_chr(data);
			data->colums++;
		}
		data->rows++;
	}
}

static void	images(t_var *data)
{
	int	i;

	data->img_ptr.img = mlx_xpm_file_to_image(data->mlx,
			"game_images/wall.xpm", &i, &i);
	data->img_ptr.img1 = mlx_xpm_file_to_image(data->mlx,
			"game_images/monster.xpm", &i, &i);
	data->img_ptr.img2 = mlx_xpm_file_to_image(data->mlx,
			"game_images/ground.xpm", &i, &i);
	data->img_ptr.img3 = mlx_xpm_file_to_image(data->mlx,
			"game_images/character.xpm", &i, &i);
	data->img_ptr.img4 = mlx_xpm_file_to_image(data->mlx,
			"game_images/door2.xpm", &i, &i);
	data->img_ptr.img5 = mlx_xpm_file_to_image(data->mlx,
			"game_images/coin.xpm", &i, &i);
	data->img_ptr.img6 = mlx_xpm_file_to_image(data->mlx,
			"game_images/death.xpm", &i, &i);
	data->img_ptr.img7 = mlx_xpm_file_to_image(data->mlx,
			"game_images/opendoor.xpm", &i, &i);
}

void	chek_ext(char *s)
{
	char	*s1;

	s1 = strrchr(s, '.');
	if (s1)
	{
		if (strncmp(s1, ".ber", 4))
		{
			ft_printf("map file invalide \n");
			exit(0);
		}
	}
}

int	main(int ac, char *av[])
{
	int		fd;
	t_var	mlx_ptr;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		mlx_ptr.p = ftt_split(&mlx_ptr, fd);
		chek_ext(av[1]);
		player_position(&mlx_ptr);
		checkall_map(&mlx_ptr);
		mlx_ptr.mlx = mlx_init();
		mlx_ptr.win = mlx_new_window(mlx_ptr.mlx, x_width(mlx_ptr.p),
				y_height(mlx_ptr.p), "hg");
		enemy_moves(&mlx_ptr);
		images(&mlx_ptr);
		put_image(&mlx_ptr);
		image_coin(&mlx_ptr);
		
		// mlx_loop_hook(mlx_ptr.mlx, enemy_moves, &mlx_ptr)
		mlx_loop_hook(mlx_ptr.mlx, animated_coins, &mlx_ptr);
		mlx_key_hook(mlx_ptr.win, key_press, &mlx_ptr);
		mlx_hook(mlx_ptr.win, 17, 0, mouse_press, &mlx_ptr);
		mlx_loop(mlx_ptr.mlx);
		free(&mlx_ptr);
		mlx_destroy_window(mlx_ptr.mlx, mlx_ptr.win);
	}
}
