/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:26:10 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/12 11:26:30 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../../mlx/mlx.h"

# define TYPE_ANGLE 90.0
# define TYPE_MAN_PLAYER_ANGLE 0.1
# define TYPE_MAN_PLAYER_POS 0.1
# define TYPE_MIN_DIS 25
# define TYPE_HOR_PIX 800
# define TYPE_VER_PIX 400
# define TYPE_PIX_PER_OBJ 50
# define TYPE_OBJ_VER_PIX 50
# define TYPE_PI 3.1415926535897932384626433

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

typedef struct s_render_source
{
	void		*object;
	int			object_pos;
	double		distance;
	int			render_screen_pos;
	double		theta;
	double		ob_x;
	double		ob_y;
} t_render_source;

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
	int				floor_rgb;
	int				ceil_rgb;
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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*n_img;
	void	*s_img;
	void	*w_img;
	void	*e_img;
	int		img_ver_size;
	int		img_hor_size;
} t_mlx;

typedef struct s_game
{
	t_map *map;
	t_keys *keys;
	t_mlx	mlx;
	t_render_source	*source;
} t_game;

void	init_t_render_source(t_render_source *source);
double	get_distance(double from_x, double from_y, double to_x, double to_y);
int		mlx_img_init(t_mlx *mlx);
int 	render(t_game *game);
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

int	parse_map(t_map *map, char *filename);
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
//free.c
void    free_texpath(t_map *map);
void    free_map(t_map *map, int limit);
void    free_game_map(t_game *game);
void	free_game_mlx(t_game *game);

#endif