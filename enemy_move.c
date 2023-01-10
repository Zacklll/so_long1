/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:41:56 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/10 18:45:12 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int   enemy_moves(t_var *data)
{
   
    int x;
    int y;
    t_list *head =NULL;
    
    y = 0;
   
	while (data->p[y])
	{
		x = 0;
		while (data->p[y][x])
		{
			if (data->p[y][x] == 'M')
			{        
                ft_lstadd_front(&head,ft_lstnew(y,x));
            }
            x++;
        }
        y++;
    }
    funcs(head);
    return (0);
}

void funcs(t_list *head)
{
    printf("etstfvesf \n");
    while (head)
    {
        printf("%d , %d\n", head->a, head->b );
        head = head->next;
    }
}

//                 if (i == 5000)
//                 {
// 				    if (data->p[y][x + 1] != '1' && data->p[y][x + 1] != 'M')
//                     {
//                         data->p[y][x + 1] = 'M';                  
//                         data->p[y][x] = '0';
//                         // mlx_destroy_window(data->mlx,data->win);
//                         put_image(data);             
//                     }
//                     // if (i == 4000)
//                     // {
//                     //     data->p[y][x + 1] = '0';                  
//                     //     data->p[y][x] = 'M';
//                     //     // mlx_destroy_window(data->mlx,data->win);
//                     //     put_image(data);             
//                     // }
//                 }
//                 if (data->p[y][x + 1] == '1' || data->p[y][x + 1] == 'M')
//                 {
//                     if (i == 6000)
//                     {
//                         if (data->p[y][x - 1] != '1' && data->p[y][x - 1] != 'M')
//                         {   
//                             data->p[y][x - 1] = 'M';
//                             data->p[y][x] = '0';
                           
//                             // mlx_destroy_window(data->mlx,data->win);
//                             put_image(data);
//                         }
//                     } 
//                 } 
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
//     i++;
//     if (i == 10000)
//         i = 0;
//     return 0;
// }
