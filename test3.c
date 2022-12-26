// #include <stdio.h>
// #include <mlx.h>
// #include "get_next_line.h"
// #include "so_long.h"
// #include "ft_printf.h"

// void cheack(t_var  *data)
// { 
//     int x = 0;
//     int y;
//     while (data->p[x])
//     {
//         y = 0;
//         while (data->p[x][y])
//         {
//             if (data->p[x][y] == '1')
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img , y * 50, x * 50);
//             else if (data->p[x][y] == '0')
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2 , y * 50, x * 50);
//             else if (data->p[x][y] == 'P')
//             {
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2 , y * 50, x * 50);
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img3 , y * 50, x * 50);
//             }
//             else if (data->p[x][y] == 'E')
//             { 
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2 , y * 50, x * 50);
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img4 , y * 50, x * 50);
//             }
//             else if (data->p[x][y] == 'C')
//             {    
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2 , y * 50, x * 50);
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img5 , y * 50, x * 50);
//             }
//             else if (data->p[x][y] == 'M')
//             {
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2 , y * 50, x * 50);
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img1 , y * 50, x * 50);
//             }
//             else if (data->p[x][y] == 'D')
//             {
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2 , y * 50, x * 50);
//                 mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img6 , y * 50, x * 50);
//             }
//             y++;
//         }
//         x++;
//     }
// }


// char *ft_join(int fd)
// {
//     int k;
//     char *str;
    
//     char *tmp;
//     tmp = NULL;

//     k = 0;
//     while ((str = get_next_line(fd)) != NULL)
//         tmp = ft_strjoin(tmp,str);
//     return (tmp);
// }

// char **ftt_split(int fd)
// {
//     int i;
//     int k;
//     char *save;
    
//     i = 0;
//     save = ft_join(fd);
//     char **test = ft_split(save,'\n');
//     return (test);
// }

// void position(t_var *data)
// {
//     int x;
//     int y = 0;
//     while (data->p[y])
//     {
//         x = 0;
//         while (data->p[y][x])
//         {
//             if (data->p[y][x] == 'P')
//             {
//                 data->x_pos = x;
//                 data->y_pos = y;
//             }
//           x++;  
//         }
//         y++;
//     }
// }

// int exit_game(int i, t_var *data)
// {
 
//     int g;
//     int y,x;
//     static int in = 0;
//     if (i == 53)
//     {
//        mlx_destroy_window(data->mlx, data->win);
//        exit (0);
//     }
//     position(data);
//     if (i == 124 && (data->p[data->y_pos][data->x_pos + 1] != '1') && data->p[data->y_pos][data->x_pos] == 'P')
//     {
//         if (data->p[data->y_pos][data->x_pos + 1] == 'M')
//         {
//            data->p[data->y_pos][data->x_pos] = 'D';
//            data->p[data->y_pos][data->x_pos + 1] = '0';
//            printf("KO\n");
//            cheack(data);
//         }
//         if (data->p[data->y_pos][data->x_pos + 1] == 'C')
//             data->p[data->y_pos][data->x_pos + 1] = '0';

//         if (data->p[data->y_pos][data->x_pos + 1] == 'E')
//         {
//             mlx_destroy_image(data->mlx, data->win);
//             exit (0);
//         }
//         data->c = data->p[data->y_pos][data->x_pos + 1];
//         data->p[data->y_pos][data->x_pos + 1] = data->p[data->y_pos][data->x_pos];
//         data->p[data->y_pos][data->x_pos] = data->c;
//         mlx_clear_window(data->mlx,data->win);
//         cheack(data);
       
//     }
//     else if (i == 123 && data->p[data->y_pos][data->x_pos - 1] != '1' && data->p[data->y_pos][data->x_pos] == 'P')
//     {
//         if (data->p[data->y_pos][data->x_pos - 1] == 'M')
//         {
//            data->p[data->y_pos][data->x_pos] = 'D';
//            data->p[data->y_pos][data->x_pos - 1] = '0';
//            printf("KO\n");
//            cheack(data);
//         }
//         if (data->p[data->y_pos][data->x_pos - 1] == 'C')
//             data->p[data->y_pos][data->x_pos - 1] = '0';

//         if (data->p[data->y_pos][data->x_pos - 1] == 'E')
//         {
//             mlx_destroy_image(data->mlx, data->win);
//             exit (0);
//         }
//         data->c = data->p[data->y_pos][data->x_pos - 1];
//         data->p[data->y_pos][data->x_pos - 1] = data->p[data->y_pos][data->x_pos];
//         data->p[data->y_pos][data->x_pos] = data->c;
//         mlx_clear_window(data->mlx,data->win);
//         cheack(data);
//     }
//     else if (i == 125  && data->p[data->y_pos + 1][data->x_pos] != '1' && data->p[data->y_pos][data->x_pos] == 'P')
//     {
//         if (data->p[data->y_pos + 1][data->x_pos] == 'M')
//         {
//            data->p[data->y_pos][data->x_pos] = 'D';
//            data->p[data->y_pos + 1][data->x_pos] = '0';
//            printf("KO\n");
//            cheack(data);
//         }
//         if (data->p[data->y_pos + 1][data->x_pos] == 'C')
//             data->p[data->y_pos + 1][data->x_pos] = '0';

//         if (data->p[data->y_pos + 1][data->x_pos] == 'E')
//         {  
//             mlx_destroy_image(data->mlx, data->win);
//             exit (0);
//         } 
//         data->c = data->p[data->y_pos + 1][data->x_pos];
//         data->p[data->y_pos + 1][data->x_pos] = data->p[data->y_pos][data->x_pos];
//         data->p[data->y_pos][data->x_pos] = data->c;
//         mlx_clear_window(data->mlx,data->win);
//         cheack(data);
//     }
//     else if (i == 126 && data->p[data->y_pos - 1][data->x_pos] != '1' && data->p[data->y_pos][data->x_pos] == 'P')
//     {
//         if (data->p[data->y_pos - 1][data->x_pos] == 'M')
//         {
//            data->p[data->y_pos][data->x_pos] = 'D';
//            data->p[data->y_pos - 1][data->x_pos] = '0';
//            printf("KO\n");
//            cheack(data);
//         }
//         if (data->p[data->y_pos - 1][data->x_pos] == 'C')
//         {
//             data->p[data->y_pos - 1][data->x_pos] = '0';
//         }
//         if (data->p[data->y_pos - 1][data->x_pos] == 'E')
//         {
//             mlx_destroy_image(data->mlx, data->win);
//             exit (0);
//         }
//         data->c = data->p[data->y_pos - 1][data->x_pos];
//         data->p[data->y_pos - 1][data->x_pos] = data->p[data->y_pos][data->x_pos];
//         data->p[data->y_pos][data->x_pos] = data->c;
//         mlx_clear_window(data->mlx,data->win);
//         cheack(data);
//     }
    
//     return (in+1);
// }

// int x_width(char **p)
// {
//    int i;
//    int j;

//    i = 0;
//    while (p[i])
//    {
//         j = 0;
//         while (p[i][j])
//         {
//             j ++;
//         } 
//         i++;
//    }
//     return (j * 50);
// }

// int y_height(char **p)
// {
//     int y;
//     y = 0;
//     while(p[y])
//         y++;
//     return (y * 50);
// }

// int main()
// {
//     t_var   mlx_ptr;

//     int i ;
//     char  *str;
//     int fd;
	
//     mlx_ptr.img_ptr.y = 0;
//     fd = open("map.ber", O_RDONLY);
//     mlx_ptr.p = ftt_split(fd);
//     mlx_ptr.mlx = mlx_init();
//     mlx_ptr.win = mlx_new_window(mlx_ptr.mlx, x_width(mlx_ptr.p), y_height(mlx_ptr.p), "hg");
//     mlx_ptr.img_ptr.img = mlx_xpm_file_to_image(mlx_ptr.mlx,"t2.xpm", &i, &i);
//     mlx_ptr.img_ptr.img1 = mlx_xpm_file_to_image(mlx_ptr.mlx,"monster.xpm", &i, &i);
//     mlx_ptr.img_ptr.img7 = mlx_xpm_file_to_image(mlx_ptr.mlx,"gameover.xpm", &i, &i);
//     mlx_ptr.img_ptr.img6 = mlx_xpm_file_to_image(mlx_ptr.mlx,"death.xpm", &i, &i);
//     mlx_ptr.img_ptr.img2 = mlx_xpm_file_to_image(mlx_ptr.mlx,"ground.xpm", &i, &i);
//     mlx_ptr.img_ptr.img3 = mlx_xpm_file_to_image(mlx_ptr.mlx,"character.xpm", &i, &i);
//     mlx_ptr.img_ptr.img4 = mlx_xpm_file_to_image(mlx_ptr.mlx,"exit.xpm", &i, &i);
//     mlx_ptr.img_ptr.img5 = mlx_xpm_file_to_image(mlx_ptr.mlx,"coin.xpm", &i, &i);
//     cheack(&mlx_ptr);
//     position(&mlx_ptr);
//     mlx_hook(mlx_ptr.win,2,0,exit_game,&mlx_ptr);
//     mlx_loop(mlx_ptr.mlx);

// }

