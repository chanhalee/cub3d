/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:23:23 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/13 13:12:23 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include "../header/cub3d.h"

typedef struct s_ray_cast_inner_vars
{
	double	theta;
	int		bias_x;
	int		bias_y;
	double	near_x;
	double	near_y;
}	t_ray_cast_inner_vars;

void			ray_cast_calc(t_render_source *s, t_map *m, t_mlx *mlx, int px);
unsigned int	*simple_mlx_get_data_addr(void *img_ptr);
void			render_inner_seq(t_game *game, unsigned int *img, int counter,
					unsigned int *screen);
int				ray_cast_calc_inner_seq_top_bottom_wall(
					t_ray_cast_inner_vars *vars, t_mlx *mlx,
					t_render_source *s, t_map *m);
int				ray_cast_calc_inner_seq_left_right_wall(
					t_ray_cast_inner_vars *vars, t_mlx *mlx,
					t_render_source *s, t_map *m);

#endif