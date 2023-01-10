/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:22:39 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/10 17:41:19 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lstnew(int a, int b)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (0);
	ptr->a = a;
	ptr->b = b;
	ptr->next = NULL;
	return (ptr);
}
