/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:17:55 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/10 14:26:19 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdint.h>

char	*join_utils(char *s1)
{
	s1 = malloc(sizeof(char *) * 1);
	s1[0] = '\0';
	return (s1);
}

char	*ft_strjoin_split(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;
	int		full_len;

	i = 0;
	j = 0;
	if (!s1)
		s1 = join_utils(s1);
	if (!s2)
		return (NULL);
	full_len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(full_len + 1);
	if (!p)
		return (NULL);
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = 0;
	free(s1);
	return (p);
}

char	*ft_join(int fd)
{
	char	*str;
	char	*tmp;

	tmp = NULL;
	str = get_next_line(fd);
	if (str == NULL)
	{
		ft_printf("invalid map");
		exit(0);
	}
	while (str != NULL)
	{
		if (ft_strlen(str) <= 1)
			exit(0);
		tmp = ft_strjoin_split(tmp, str);
		free(str);
		str = NULL;
		str = get_next_line(fd);
	}
	return (tmp);
}

char	**ftt_split(t_var *data, int fd)
{
	int		i;
	char	*save;
	char	**test;

	i = 0;
	save = ft_join(fd);
	test = ft_split(save, '\n');
	data->tmp_arry = ft_split(save, '\n');
	data->tmp_arry2 = ft_split(save, '\n');
	free(save);
	save = NULL;
	return (test);
}

void	checkall_map(t_var *data)
{
	int	res1;

	if (count_coins(data) == 0)
	{
		ft_printf("it must be at least one collectibles at least\n");
		exit(0);
	}
	check_map(data);
	check_rep(data);
	cheack_boundaries(data);
	check_path_coins(data->x_pos, data->y_pos, data->tmp_arry, data);
	res1 = check_pathto(data->x_pos, data->y_pos, data->tmp_arry2, data);
	if (res1 == 1)
	{
		if (count_coins(data) != data->count_coins)
		{
			ft_printf("no path to get all collectibles \n");
			exit(0);
		}
	}
	else if (res1 == 0)
	{
		ft_printf("no valid path\n");
		exit(0);
	}
}
