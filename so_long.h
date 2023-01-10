/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:20:19 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/10 17:58:04 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>


typedef struct s_tr
{
	void	*img;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*coin7;
	void	*coin8;
	void	*coin9;
	void	*coin10;
}			t_tr;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	char	*nbr;
	char	*map;
	char	**p;
	int		x_last;
	char	tmp;
	int		rows;
	int		len;
	int		colums;
	int		count_coins;
	int		x_pos;
	int		y_pos;
	int		c_count;
	int		exit_xpos;
	int		exit_ypos;
	char	**tmp_arry;
	char	**tmp_arry2;
	t_tr	img_ptr;
}			t_var;

typedef struct s_list
{
	int			a;
	int			b;
	struct s_list	*next;
}			t_list;

void 		funcs(t_list *head);
t_list		*ft_lstnew(int a, int b);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		image_coin(t_var *data);
int			enemy_moves(t_var *data);
int			ft_strncmp(char *str1, char *str2, size_t size);
char		*ft_strrchr(char *str, int arg);
void		move_up(t_var *data, int in);
void		move_down(t_var *data, int in);
void		move_left(t_var *data, int in);
void		move_right(t_var *data, int in);
char		*ft_join(int fd);
char		**ftt_split(t_var *data, int fd);
void		put_image(t_var *data);
void		player_position(t_var *data);
int			count_coins(t_var *data);
int			key_press(int i, t_var *data);
char		*ft_itoa(int nbr);
int			x_width(char **p);
void		cheack_boundaries(t_var *data);
void		check_rep(t_var *data);
int			y_height(char **p);
int			ft_printf(const char *str, ...);
int			animated_coins(t_var *data);
void		check_map(t_var *data);
char		*get_next_line(int fd);
void		destroy_fun(t_var *data);
void		insert_image(t_var *data, void *img, void *img2);
char		**ft_split(char const *st, char c);
int			mouse_press(t_var *data);
void		check_path_coins(int x, int y, char **tab, t_var *data);
void		checkall_map(t_var *data);
int			check_pathto(int x, int y, char **tab1, t_var *data);
void		exit_handel(t_var *data);

#endif
