#ifndef MINHEE_H
#define MINHEE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef	struct	s_str
{
	char	*content;
	struct s_str	*next;
}	t_str;

typedef	struct	s_map
{
	int	row;
	int	col;
	char	**map;
}	t_map;

int	parse_map(t_map *map, char *filename);

int						get_next_line(int fd, char **line);
int						cat_buf(char **line, char *buf, int bytes_read);
int						save_leftover(char *buf, char **saved);
int						return_stat(int status, char **line, char *buf);
int						set_stat(int *status, char **line, int fd);
int						gnl_malloc(char **buf);
int						malloc_cat_saved(char **line, char **saved);
int						cat_saved(char **line, char **saved);
int						is_newline(char *buf);
int						ft_strlen(char *str);
void					ft_strcat(char *str1, char *str2, int start);
char					*ft_strdup(char *str);
int						get_len(char *str);

t_str	*str_add_back(t_str **str, char *content);
int	str_clear(t_str **list);

void	ft_strfill(char *buf, int start, int end, char c);
void	ft_strcpy(char *dest, char *src);
#endif
