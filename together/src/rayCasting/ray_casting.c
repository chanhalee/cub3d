/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:44:23 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/13 13:51:12 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray_casting.h"

int	render(t_game *game)
{
	int				counter;
	void			*mlx_screen;
	unsigned int	*screen;
	unsigned int	*img;

	counter = -1;
	while (++counter < TYPE_HOR_PIX)
		ray_cast_calc(&(game->source[counter]), game->map, &(game->mlx),
			counter);
	mlx_screen = mlx_new_image(game->mlx.mlx, TYPE_HOR_PIX, TYPE_VER_PIX);
	if (mlx_screen == NULL)
		return (1);
	screen = simple_mlx_get_data_addr(mlx_screen);
	counter = -1;
	while (++counter < TYPE_HOR_PIX)
	{
		img = simple_mlx_get_data_addr(game->source[counter].object);
		render_inner_seq(game, img, counter, screen);
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, mlx_screen, 0, 0);
	mlx_destroy_image(game->mlx.mlx, mlx_screen);
	return (0);
}

void	ray_cast_calc(t_render_source *s, t_map *m, t_mlx *mlx, int px)
{
	t_ray_cast_inner_vars	vars;

	s->render_screen_pos = px;
	vars.theta = atan2((double)TYPE_HOR_PIX / 2.0 - (double)px,
			m->sight_safe_margin) + m->player.vision_theta + 2 * TYPE_PI;
	while (vars.theta > 2 * TYPE_PI)
		vars.theta -= 2 * TYPE_PI;
	vars.bias_x = 0;
	if (vars.theta < TYPE_PI * 1.5 && vars.theta > TYPE_PI * 0.5)
		vars.bias_x = -1;
	vars.bias_y = 0;
	if (vars.theta > TYPE_PI)
		vars.bias_y = -1;
	vars.near_x = (ceil(m->player.pos_x) - m->player.pos_x + vars.bias_x);
	vars.near_y = (ceil(m->player.pos_y) - m->player.pos_y + vars.bias_y);
	while (1)
	{
		if (fabs(vars.near_x * tan(vars.theta)) <= fabs(vars.near_y))
		{
			if (ray_cast_calc_inner_seq_top_bottom_wall(&vars, mlx, s, m))
				return ;
		}
		else if (ray_cast_calc_inner_seq_left_right_wall(&vars, mlx, s, m))
			return ;
	}
}

void	render_inner_seq(t_game *game, unsigned int *img, int counter,
			unsigned int *screen)
{
	int		idx_y;
	double	pix_multi;

	pix_multi = game->map->sight_safe_margin / (game->source[counter].distance
			* TYPE_PIX_PER_OBJ);
	idx_y = -1;
	while (++idx_y < (TYPE_VER_PIX + 1) / 2)
	{
		screen[counter + TYPE_HOR_PIX * idx_y] = game->map->ceil_rgb;
		screen[counter + TYPE_HOR_PIX * (TYPE_VER_PIX -1 - idx_y)]
			= game->map->floor_rgb;
		if (TYPE_PIX_PER_OBJ * pix_multi + idx_y * 2 >= TYPE_VER_PIX)
		{
			screen[counter + TYPE_HOR_PIX * idx_y] = img[(int)(((idx_y - 0.5 * \
	(TYPE_VER_PIX - TYPE_PIX_PER_OBJ * pix_multi)) / pix_multi) * game->mlx.\
	img_ver_size / TYPE_OBJ_VER_PIX) *(game->mlx.img_hor_size) + \
	game->source[counter].object_pos];
			screen[counter + TYPE_HOR_PIX * (TYPE_VER_PIX -1 - idx_y)] = img[\
	(game->mlx.img_ver_size - (int)(((idx_y - (TYPE_VER_PIX - TYPE_PIX_PER_OBJ \
	* pix_multi) / 2) / pix_multi * game->mlx.img_ver_size / TYPE_OBJ_VER_PIX)) \
	-1) * game->mlx.img_hor_size + game->source[counter].object_pos];
		}
	}
}

int	ray_cast_calc_inner_seq_top_bottom_wall(t_ray_cast_inner_vars *vars,
		t_mlx *mlx, t_render_source *s, t_map *m)
{
	if (m->map[(int)(m->player.pos_y + vars->near_y) - vars->bias_y - 1]
			[(int)(m->player.pos_x + vars->near_x) + vars->bias_x] == '1')
	{
		s->distance = fabs((vars->near_x / cos(vars->theta)) * sin(vars->theta
					+ TYPE_PI / 2.0 - m->player.vision_theta));
		s->object_pos = fabs((double)mlx->img_hor_size * ((vars->near_y
						- vars->near_x * tan(vars->theta) - vars->bias_y)));
		if (vars->bias_x == -1)
			s->object_pos *= -1;
		s->object_pos += mlx->img_hor_size * -(vars->bias_x);
		s->object = mlx->w_img;
		if (vars->bias_x == -1)
			s->object = mlx->e_img;
		s->object_pos %= TYPE_PIX_PER_OBJ;
		return (1);
	}
	vars->near_x += 1 + vars->bias_x * 2;
	return (0);
}

int	ray_cast_calc_inner_seq_left_right_wall(t_ray_cast_inner_vars *vars,
		t_mlx *mlx, t_render_source *s, t_map *m)
{
	if (m->map[(int)(m->player.pos_y + vars->near_y) + vars->bias_y]
			[(int)(m->player.pos_x + vars->near_x) - vars->bias_x - 1] == '1')
	{
		s->distance = fabs((vars->near_y / sin(vars->theta)) * sin(vars->theta
					+ TYPE_PI / 2.0 - m->player.vision_theta));
		s->object_pos = fabs((double)mlx->img_hor_size * ((vars->near_x
						- vars->near_y / tan(vars->theta) - vars->bias_x)));
		if (vars->bias_y != -1)
			s->object_pos *= -1;
		s->object_pos += mlx->img_hor_size * (1 + vars->bias_y);
		s->object = mlx->s_img;
		if (vars->bias_y == -1)
			s->object = mlx->n_img;
		s->object_pos %= TYPE_PIX_PER_OBJ;
		return (1);
	}
	vars->near_y += 1 + vars->bias_y * 2;
	return (0);
}
