/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:03:43 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/15 01:10:35 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	valid_name(char *name)
{
	int	len;

	if (name == NULL)
		return (1);
	len = ft_strlen(name);
	if (len < 4)
		return (1);
	if (equals(name + len - 4, ".xpm") != 0)
		return (1);
	return (0);
}

int	check_texname(t_map *map)
{
	if (valid_name(map->n_path) != 0)
	{
		free_texpath(map);
		return (1);
	}
	if (valid_name(map->s_path) != 0)
	{
		free_texpath(map);
		return (1);
	}
	if (valid_name(map->w_path) != 0)
	{
		free_texpath(map);
		return (1);
	}
	if (valid_name(map->e_path) != 0)
	{
		free_texpath(map);
		return (1);
	}
	return (0);
}
