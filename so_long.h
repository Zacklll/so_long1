/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:20:19 by zael-wad          #+#    #+#             */
/*   Updated: 2022/12/26 12:34:24 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "mlx.h"
#include "get_next_line.h"
#include "ft_printf.h"


typedef struct s_tr
{
    int     y;
    int     x_last;
	   
	void	*img;
	void	*img1;
    void    *img2;
    void    *img3;
    void    *img4;
    void    *img5;
    void    *img6;
    void    *img7;
}			t_tr;

typedef struct  s_var
{
    void    *mlx;
    void    *win;
    char    *nbr;
    char    *map;
    char    **p;
    char    tmp;
    int     rows;
    int     colums;
    int     x_pos;
    int		c_count;
    int     y_pos;
    
    t_tr    img_ptr;
        
}       t_var;

void    move_up(t_var *data);
void	move_down(t_var *data);
void	move_left(t_var *data);
void	move_right(t_var *data);
void    put_image(t_var  *data);
void    player_position(t_var *data);
int     count_coins(t_var *data);
int	    key_press(int i, t_var *data);
char	*ft_itoa(int nbr);
int     x_width(char **p);
void    cheack_boundaries(t_var *data);
void    check_rep(t_var *data);
int     y_height(char **p);
int	    ft_printf(const char *str, ...);
void    check_map(t_var *data);
char	*get_next_line(int fd);
char	**ft_split(char const *st, char c);
int 	mouse_press(t_var *data);

#endif


