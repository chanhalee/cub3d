/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:49:26 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/15 01:19:16 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	*invalid_file(int fd, t_map *map, char *line)
{
	free_texpath(map);
	free(line);
	close(fd);
	return (NULL);
}

t_str	*buffer_map(int fd, t_map *map)
{
	t_str	*temp;
	char	*line;
	int		x;

	temp = NULL;
	x = get_next_line(fd, &line);
	while (x != 0 && ft_strlen(line) == 0)
	{
		free(line);
		x = get_next_line(fd, &line);
	}
	if (x == 0)
		return (invalid_file(fd, map, line));
	while (x)
	{
		if (ft_strlen(line) > map->size_y)
			map->size_y = ft_strlen(line);
		(map->size_x)++;
		str_add_back(&temp, ft_strdup(line));
		free(line);
		x = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	return (temp);
}

t_str	*convert_line(t_map *map, t_str *cur, int i)
{
	int	len;

	if (i == 0 || i == map->size_x + 1)
		ft_strfill(map->map[i], 0, map->size_y + 2, ' ');
	else
	{
		len = ft_strlen(cur->content) + 1;
		map->map[i][0] = ' ';
		ft_strcpy(map->map[i] + 1, cur->content);
		ft_strfill(map->map[i], len, map->size_y + 2, ' ');
		cur = cur->next;
	}
	return (cur);
}

int	convert_map(t_map *map, t_str *temp)
{
	t_str	*cur;
	int		i;

	map->map = (char **)malloc(sizeof(char *) * (map->size_x + 2));
	if (map->map == NULL)
		return (1);
	i = 0;
	cur = temp;
	while (i < map->size_x + 2)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->size_y + 3));
		if (map->map[i] == NULL)
		{
			free_map_all(map, i);
			return (1);
		}
		cur = convert_line(map, cur, i);
		i++;
	}
	return (0);
}

int	parse_map(t_map *map, char *filename)
{
	int		fd;
	t_str	*temp;

	if (check_filename(filename) != 0)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (2);
	init_map(map);
	if (get_texture(map, fd) != 0)
		return (3);
	temp = buffer_map(fd, map);
	if (temp == NULL)
		return (4);
	if (convert_map(map, temp) != 0)
	{
		str_clear(&temp);
		free_texpath(map);
		return (5);
	}
	str_clear(&temp);
	if (check_valid_map(map) != 0)
		return (6);
	inc_size(map);
	return (0);
}
