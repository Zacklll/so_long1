#include <stdio.h>
#include <mlx.h>
#include "get_next_line.h"
#include "so_long.h"
#include "ft_printf.h"

// void    cheack_srounding(t_var *data)
// {
//     int i;
//     int x, y = 0;
//     i = 0;
//     while (data->p[y])
//     {
//         x = 0;
//         while (data->p[y][x])
//         {
//             if (data->p[y][x] == 'P' || data->p[y][x] == 'C' || data->p[y][x] == 'E')
//             {
//                 if ((data->p[y][x + 1] == '1' && data->p[y + 1][x] == '1' && data->p[y][x - 1] == '1' && data->p[y - 1][x]) == '1')
//                     exit (0);
//             }
//             x++;
//         }
//         y++;
//     }
// }



void put_image(t_var  *data)
{
    data->rows = 0;
    while (data->p[data->rows])
    {
        data->colums = 0;
        while (data->p[data->rows][data->colums])
        {
            if (data->p[data->rows][data->colums] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img  , data->colums * 50, data->rows * 50);
            else if (data->p[data->rows][data->colums] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2 , data->colums * 50, data->rows * 50);
            else if (data->p[data->rows][data->colums] == 'P')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2 , data->colums * 50, data->rows * 50);
                mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img3 , data->colums * 50, data->rows * 50);
            }
            else if (data->p[data->rows][data->colums] == 'C')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2 , data->colums * 50, data->rows * 50);
                mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img5 , data->colums * 50, data->rows * 50);
            }
            else if (data->p[data->rows][data->colums] == 'M')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img2 , data->colums * 50, data->rows * 50);
                mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img1 , data->colums * 50, data->rows * 50);
            }
            else if (data->p[data->rows][data->colums] == 'D')
                mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img6 , data->colums * 50, data->rows * 50);
            else if (data->p[data->rows][data->colums] == 'E')
            {
                if (count_coins(data) == 0)
                    mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img7 , data->colums * 50, data->rows * 50);
                else
                    mlx_put_image_to_window(data->mlx, data->win, data->img_ptr.img4 , data->colums * 50, data->rows * 50);
                
            }
            else
                exit (0);
            data->colums++;
        }
        data->rows++;
    }
}

char *ft_join(int fd)
{
    char *str;
    char *ptr;
    char *tmp;
   
    tmp = NULL;
    while ((str = get_next_line(fd)) != NULL)
    {
        tmp = ft_strjoin(ptr,str);
        free(ptr);
        ptr = tmp;
    }
    free(str);
    return (tmp);
}

char    **ftt_split(int fd)
{
    int i;
    char *save;
    char **test;

    i = 0;
    save = ft_join(fd);
    test = ft_split(save,'\n');
    free(save);
    return (test);
}

// int fun(t_var *data)
// {
//     int i = 0;
//     int x = 0;
//     int y = 0;
    
//     while (data->p[y])
//     {
//         x = 0;
//         while (data->p[y][x])
//         {
            
//         }
//     }
// }

int main()
{
    t_var   mlx_ptr;
    int fd;
    int i;

    fd = open("map2.ber", O_RDONLY);
    mlx_ptr.p = ftt_split(fd);
    count_coins(&mlx_ptr);
    check_map(&mlx_ptr);
    check_rep(&mlx_ptr);
    cheack_boundaries(&mlx_ptr);
    // cheack_srounding(&mlx_ptr);
    mlx_ptr.mlx = mlx_init();
    mlx_ptr.win = mlx_new_window(mlx_ptr.mlx, x_width(mlx_ptr.p), y_height(mlx_ptr.p), "hg");
    mlx_ptr.img_ptr.img = mlx_xpm_file_to_image(mlx_ptr.mlx,"t2.xpm", &i, &i);
    mlx_ptr.img_ptr.img1 = mlx_xpm_file_to_image(mlx_ptr.mlx,"monster.xpm", &i, &i);
    mlx_ptr.img_ptr.img7 = mlx_xpm_file_to_image(mlx_ptr.mlx,"opendoor4.xpm", &i, &i);
    mlx_ptr.img_ptr.img6 = mlx_xpm_file_to_image(mlx_ptr.mlx,"death.xpm", &i, &i);
    mlx_ptr.img_ptr.img2 = mlx_xpm_file_to_image(mlx_ptr.mlx,"ground.xpm", &i, &i);
    mlx_ptr.img_ptr.img3 = mlx_xpm_file_to_image(mlx_ptr.mlx,"character.xpm", &i, &i);
    mlx_ptr.img_ptr.img4 = mlx_xpm_file_to_image(mlx_ptr.mlx,"door2.xpm", &i, &i);
    mlx_ptr.img_ptr.img5 = mlx_xpm_file_to_image(mlx_ptr.mlx,"coin.xpm", &i, &i);
    put_image(&mlx_ptr);
    // player_position(&mlx_ptr);
    // mlx_loop_hook(mlx_ptr,,&mlx_ptr);
    mlx_hook(mlx_ptr.win, 2 , 0, key_press , &mlx_ptr);
    mlx_hook(mlx_ptr.win, 17, 0, mouse_press , &mlx_ptr);
   
    mlx_loop(mlx_ptr.mlx);
    free(&mlx_ptr);
    mlx_destroy_window(mlx_ptr.mlx,mlx_ptr.win);
}
// int main(int ac, char *av[])
// {
//     (void)ac;
//     int x = 0;
//     while (av[0])
//     {
//         while (av[0][x])
//         {
//             x++;
//         }
//     }
// }