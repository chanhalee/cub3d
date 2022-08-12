#include "./header/cub3d.h"

int	check_edges(t_map *map)
{
	int	i;

	i = 1;
	while (i <= map->size_y)
	{
		if (!(map->map[1][i] == ' ' || map->map[1][i] == '1')
				|| !(map->map[map->size_x][i] == ' ' || map->map[map->size_x][i] == '1'))
			return (1);
		i++;
	}
	i = 1;
	while (i <= map->size_x)
	{
		if (!(map->map[i][1] == ' ' || map->map[i][1] == '1')
				|| !(map->map[i][map->size_y] == ' ' || map->map[i][map->size_y] == '1'))
			return (1);
		i++;
	}
	return (0);
}

int	get_user_vec(t_map *map, int i, int j)
{
	char	cur;

	map->player.pos_x = (double)i;
	map->player.pos_y = (double)j;
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
	int	i;
	int	j;
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
	if (!(map->map[i + 1][j - 1] == ' ' || map->map[i + 1][j - 1] == '1')
			|| !(map->map[i + 1][j] == ' ' || map->map[i + 1][j] == '1')
			|| !(map->map[i + 1][j + 1] == ' ' || map->map[i + 1][j + 1] == '1')
			|| !(map->map[i - 1][j - 1] == ' ' || map->map[i - 1][j - 1] == '1')
			|| !(map->map[i - 1][j] == ' ' || map->map[i - 1][j] == '1')
			|| !(map->map[i - 1][j + 1] == ' ' || map->map[i - 1][j + 1] == '1')
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
		return (1);
	i = 1;
	while (i <= map->size_x)
	{
		j = 1;
		while (j <= map->size_y)
		{
			if (map->map[i][j] == ' ' && check_surrounds(map, i, j) != 0)
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
	int		nbr;
	int		sign;
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
	int	r;
	int	g;
	int	b;
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
	rgb <<= 8;
	return (rgb);
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

int	parse_value(t_map *map, char *line)
{
	char	**token;
	int	ret;

	ret = 0;
	if (word_cnt(line, ' ') != 2)
		return (1);
	token = ft_split(line, ' ');
	if (equals(token[0], "NO") == 0)
		map->n_path = ft_strdup(token[1]);
	else if (equals(token[0], "SO") == 0)
		map->s_path = ft_strdup(token[1]);
	else if (equals(token[0], "WE") == 0)
		map->w_path = ft_strdup(token[1]);
	else if (equals(token[0], "EA") == 0)
		map->e_path = ft_strdup(token[1]);
	else if (equals(token[0], "F") == 0)
		map->floor_rgb = get_rgb(token[1]);
	else if (equals(token[0], "C") == 0)
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
	int	parsing;
	char	*line;

	get_next_line(fd, &line);
	parsing = 1;
	while (parsing && line != NULL)
	{
		if (ft_strlen(line) != 0)
		{
			if (parse_value(map, line))
				return (1);
		}
		parsing = check_parsing(map);
		if (parsing != 0)
			get_next_line(fd, &line);
	}
	free(line);
	return (0);
}

int	check_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (filename[len - 4] == '.'
			&& filename[len - 3] == 'c'
			&& filename[len - 2] == 'u'
			&& filename[len - 1] == 'b')
		return (0);
	return (1);
}

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

int	parse_map(t_map *map, char *filename)
{
	int		fd;
	int		byte_read;
	t_str	*temp;
	t_str	*cur;
	char	*line;
	int		i;
	int		x;

	if (check_filename(filename) != 0)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	init_map(map);

	//2. get texture paths and floor/ceiling rgb -> if invalid, return 1

	if (get_texture(map, fd) != 0)
	{
		//need to free any allocated texture paths in map
		free_texpath(map);
		printf("texture error\n");
		return (1);
	}

	//3. read map info into temp
	temp = NULL;
	map->size_x = 0;
	map->size_y = 0;
	get_next_line(fd, &line);
	while (line != NULL && ft_strlen(line) == 0)
		x = get_next_line(fd, &line);
	while (x)
	{
		byte_read = ft_strlen(line);
		if (byte_read > map->size_y)
			map->size_y = byte_read;
		(map->size_x)++;
		str_add_back(&temp, ft_strdup(line));
		x = get_next_line(fd, &line);
	}
	close(fd);

	//4. pad temp into map->map
	map->map = (char **)malloc(sizeof(char *) * (map->size_x + 2));
	if (map->map == NULL)
	{
		str_clear(&temp);
		free_texpath(map);
		return (1);
	}
	i = 0;
	cur = temp;
	while (i < map->size_x + 2)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->size_y + 3));
		if (map->map[i] == NULL)
		{
			free_map(map, i);
			free_texpath(map);
		}
		if (i == 0 || i == map->size_x + 1)
		{
			ft_strfill(map->map[i], 0, map->size_y + 2, ' ');
		}
		else
		{
			map->map[i][0] = ' ';
			ft_strcpy(map->map[i] + 1, cur->content);
			ft_strfill(map->map[i], ft_strlen(cur->content) + 1, map->size_y + 2, ' ');
			cur = cur->next;
		}
		i++;
	}
	str_clear(&temp);

	for (int k = 0; k < map->size_x + 2; k++)
		printf("map [%s]\n", map->map[k]);

	//5. check if map is valid -> if invalid, free map, texture paths and return 1
	if (check_valid_map(map) != 0)
	{
		free_texpath(map);
		free_map(map, map->size_x + 2);
		return (1);
	}

	map->size_x +=2;
	map->size_y +=2;
	return (0);
}
