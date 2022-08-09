/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RayCasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:26:10 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/10 00:35:46 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define TYPE_ANGLE 90.0
# define TYPE_MIN_DIS 25
# define TYPE_HOR_PIX 200
# define TYPE_VER_PIX 100
# define TYPE_PIX_PER_OBJ 50
# define TYPE_PI 3.14159265359

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
	double			sight_safe_margin;
} t_map;

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

void	init_t_render_source(t_render_source *source);
double	get_distance(double from_x, double from_y, double to_x, double to_y);
char	*ft_strdup(const char *src);
void	ray_cast_calc(t_render_source *s , t_map *m, int px);


#endif