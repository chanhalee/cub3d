#include "minhee.h"

int	check_edges(t_map *map)
{
	int	i;

	i = 1;
	while (i <= map->col)
	{
		if (!(map->map[1][i] == ' ' || map->map[1][i] == '1')
				|| !(map->map[map->row][i] == ' ' || map->map[map->row][i] == '1'))
			return (0);
		i++;
	}
	i = 1;
	while (i <= map->row)
	{
		if (!(map->map[i][1] == ' ' || map->map[i][1] == '1')
				|| !(map->map[i][map->col] == ' ' || map->map[i][map->col] == '1'))
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_map(t_map *map)
{
	int	i;
	int	j;

	if (check_edges(map) == 0)
		return (0);
	i = 1;
	while (i <= map->row)
	{
		j = 1;
		while (j <= map->col)
		{
			if (map->map[i][j] == ' ')
			{
				if (!(map->map[i + 1][j - 1] == ' ' || map->map[i + 1][j - 1] == '1')
						|| !(map->map[i + 1][j] == ' ' || map->map[i + 1][j] == '1')
						|| !(map->map[i + 1][j + 1] == ' ' || map->map[i + 1][j + 1] == '1')
						|| !(map->map[i - 1][j - 1] == ' ' || map->map[i - 1][j - 1] == '1')
						|| !(map->map[i - 1][j] == ' ' || map->map[i - 1][j] == '1')
						|| !(map->map[i - 1][j + 1] == ' ' || map->map[i - 1][j + 1] == '1')
						|| !(map->map[i][j + 1] == ' ' || map->map[i][j + 1] == '1')
						|| !(map->map[i][j - 1] == ' ' || map->map[i][j - 1] == '1'))
				{
					printf("invalid map map[%d][%d]\n", i, j);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_map(t_map *map, char *filename)
{
	int		fd;
	int		byte_read;
	t_str	*temp;
	t_str	*cur;
	char	*line;
	int		i;
	printf("inside parse map\n");

	//1. if filename doesn't end with .cub -> return 1
	//open file
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	//2. get texture paths and floor/ceiling rgb -> if invalid, return 1

	//3. read map info into temp -> get row col info
	temp = NULL;
	map->row = 0;
	map->col = 0;
	while (get_next_line(fd, &line))
	{
		byte_read = ft_strlen(line);
		if (byte_read > map->col) // fix this line to count number of elements with ft_split
			map->col = byte_read;
		(map->row)++;
		str_add_back(&temp, ft_strdup(line));
	}
	close(fd);

	//4. pad temp into map->map
	map->map = (char **)malloc(sizeof(char *) * (map->row + 2));
	if (!map->map)
	{
		str_clear(&temp);
		return (1);
	}
	i = 0;
	cur = temp;
	while (i < map->row + 2)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->col + 3));
		if (i == 0 || i == map->row + 1)
		{
			ft_strfill(map->map[i], 0, map->col + 2, ' ');
		}
		else
		{
			map->map[i][0] = ' ';
			ft_strcpy(map->map[i] + 1, cur->content); // switch this part to parse_line
			ft_strfill(map->map[i], ft_strlen(cur->content) + 1, map->col + 2, ' ');
			cur = cur->next;
		}
		i++;
	}
	str_clear(&temp);

	for (int k = 0; k < map->row + 2; k++)
		printf("map [%s]\n", map->map[k]);

	//5. check if map is valid -> if invalid, free map, texture paths and return 1
	if (!check_valid_map(map))
	{
		i = 0;
		while (i < map->row + 2)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		return (1);
	}
	return (0);
}
