#ifndef MINHEE_H
#define MINHEE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

# define TYPE_PI 3.14159265359

typedef	struct	s_str
{
	char	*content;
	struct s_str	*next;
}	t_str;

typedef struct s_vector
{
	double	pos_x;
	double	pos_y;
	double	vision_theta;
}	t_vector;

typedef struct s_map
{
	struct s_vector	player;
	int				size_x;
	int				size_y;
	char			**map;
	char			*s_path;
	char			*n_path;
	char			*w_path;
	char			*e_path;
	unsigned int	floor_rgb;
	unsigned int	ceil_rgb;
	double			sight_safe_margin;
} t_map;

typedef	struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int right;
} t_keys;


int	parse_map(t_map *map, char *filename);

//get next line
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

//ft_split
char					**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t nmemb, size_t size);
unsigned int	word_cnt(char const *s, char c);
void	*ft_memset(void *dest, int c, size_t n);

#endif
