/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:01:06 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/15 00:37:53 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_edges(t_map *map)
{
	int		i;
	char	**m;

	m = map->map;
	i = 1;
	while (i <= map->size_y)
	{
		if (!(m[1][i] == ' ' || m[1][i] == '1')
				|| !(m[map->size_x][i] == ' ' || m[map->size_x][i] == '1'))
			return (1);
		i++;
	}
	i = 1;
	while (i <= map->size_x)
	{
		if (!(m[i][1] == ' ' || m[i][1] == '1')
				|| !(m[i][map->size_y] == ' ' || m[i][map->size_y] == '1'))
			return (1);
		i++;
	}
	return (0);
}

int	get_user_vec(t_map *map, int i, int j)
{
	char	cur;

	map->player.pos_y = (double)i + 0.5;
	map->player.pos_x = (double)j + 0.5;
	cur = map->map[i][j];
	if (cur == 'N')
		map->player.vision_theta = TYPE_PI / 2;
	else if (cur == 'S')
		map->player.vision_theta = 3 * (TYPE_PI / 2);
	else if (cur == 'W')
		map->player.vision_theta = TYPE_PI;
	else if (cur == 'E')
		map->player.vision_theta = 0;
	else
		return (1);
	return (0);
}

int	check_user_pos(t_map *map)
{
	int		i;
	int		j;
	char	cur;

	map->player.pos_x = -1;
	i = 1;
	while (i <= map->size_x)
	{
		j = 1;
		while (j <= map->size_y)
		{
			cur = map->map[i][j];
			if (cur != ' ' && cur != '1' && cur != '0')
				if (map->player.pos_x != -1 || get_user_vec(map, i, j) != 0)
					return (1);
			j++;
		}
		i++;
	}
	if (map->player.pos_x == -1)
		return (1);
	return (0);
}

int	check_surrounds(t_map *map, int i, int j)
{
	if (!(map->map[i + 1][j] == ' ' || map->map[i + 1][j] == '1')
			|| !(map->map[i - 1][j] == ' ' || map->map[i - 1][j] == '1')
			|| !(map->map[i][j + 1] == ' ' || map->map[i][j + 1] == '1')
			|| !(map->map[i][j - 1] == ' ' || map->map[i][j - 1] == '1'))
		return (1);
	return (0);
}

int	check_valid_map(t_map *map)
{
	int	i;
	int	j;

	if (check_edges(map) != 0 || check_user_pos(map) != 0)
	{
		free_map_all(map, map->size_x + 2);
		return (1);
	}
	i = 1;
	while (i <= map->size_x)
	{
		j = 1;
		while (j <= map->size_y)
		{
			if (map->map[i][j] == ' ' && check_surrounds(map, i, j) != 0)
			{
				free_map_all(map, map->size_x + 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
