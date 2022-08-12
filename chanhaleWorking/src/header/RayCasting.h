/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RayCasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:26:10 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/12 11:26:30 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
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
	t_mlx *mlx;
	t_render_source	*source;
} t_game;

void	init_t_render_source(t_render_source *source);
double	get_distance(double from_x, double from_y, double to_x, double to_y);
char	*ft_strdup(const char *src);
void	ray_cast_calc(t_render_source *s , t_map *m, t_mlx *mlx, int px);
int		mlx_img_init(t_mlx *mlx);
int 	render(t_game *game);

#endif