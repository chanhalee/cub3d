/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:41:57 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/15 00:56:56 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_parsing(t_map *map)
{
	if (map->s_path == NULL)
		return (1);
	if (map->n_path == NULL)
		return (1);
	if (map->w_path == NULL)
		return (1);
	if (map->e_path == NULL)
		return (1);
	if (map->floor_rgb == 1)
		return (1);
	if (map->ceil_rgb == 1)
		return (1);
	return (0);
}

int	ft_atoi(char **nptr)
{
	int				nbr;
	int				sign;
	unsigned int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	if ((*nptr)[i] == '-')
		sign = -1;
	if ((*nptr)[i] == '-' || (*nptr)[i] == '+')
		i++;
	while ((*nptr)[i] >= '0' && (*nptr)[i] <= '9')
	{
		nbr = (nbr * 10) + ((*nptr)[i++] - '0') * sign;
		if (nbr > 255)
			return (-1);
		if (nbr < 0)
			return (-1);
	}
	*nptr = *nptr + i;
	return (nbr);
}

unsigned int	get_rgb(char *input)
{
	int				r;
	int				g;
	int				b;
	unsigned int	rgb;

	r = ft_atoi(&input);
	if (r < 0 || *input++ != ',')
		return (1);
	g = ft_atoi(&input);
	if (g < 0 || *input++ != ',')
		return (1);
	b = ft_atoi(&input);
	if (b < 0 || *input++ != '\0')
		return (1);
	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

int	parse_value(t_map *map, char *line)
{
	char	**token;
	int		ret;

	ret = 0;
	if (word_cnt(line, ' ') != 2)
		return (1);
	token = ft_split(line, ' ');
	if (equals(token[0], "NO") == 0 && !map->n_path)
		map->n_path = ft_strdup(token[1]);
	else if (equals(token[0], "SO") == 0 && !map->s_path)
		map->s_path = ft_strdup(token[1]);
	else if (equals(token[0], "WE") == 0 && !map->w_path)
		map->w_path = ft_strdup(token[1]);
	else if (equals(token[0], "EA") == 0 && !map->e_path)
		map->e_path = ft_strdup(token[1]);
	else if (equals(token[0], "F") == 0 && map->floor_rgb == 1)
		map->floor_rgb = get_rgb(token[1]);
	else if (equals(token[0], "C") == 0 && map->ceil_rgb == 1)
		map->ceil_rgb = get_rgb(token[1]);
	else
		ret = 1;
	free(token[0]);
	free(token[1]);
	free(token);
	return (ret);
}

int	get_texture(t_map *map, int fd)
{
	int		parsing;
	char	*line;

	get_next_line(fd, &line);
	parsing = 1;
	while (parsing && line != NULL)
	{
		if (ft_strlen(line) != 0 && parse_value(map, line))
		{
			free(line);
			free_texpath(map);
			close(fd);
			return (1);
		}
		parsing = check_parsing(map);
		if (parsing != 0)
		{
			free(line);
			get_next_line(fd, &line);
		}
	}
	free(line);
	if (check_texname(map) != 0)
		return (1);
	return (0);
}
