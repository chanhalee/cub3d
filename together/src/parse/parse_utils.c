/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:00:57 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/14 22:16:24 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_map(t_map *map)
{
	map->size_x = 0;
	map->size_y = 0;
	map->map = NULL;
	map->s_path = NULL;
	map->n_path = NULL;
	map->w_path = NULL;
	map->e_path = NULL;
	map->floor_rgb = 1;
	map->ceil_rgb = 1;
	return ;
}

int	check_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (equals(filename + len - 4, ".cub") == 0)
		return (0);
	return (1);
}

int	equals(char *s1, char *s2)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	if (ft_strlen(s2) != len)
		return (1);
	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
