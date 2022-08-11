/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:44:23 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/12 00:45:14 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RayCasting.h"

int render(t_game *game)
{
	int		counter;
	int		idx_y;
	double	pix_multi;
	void	*mlx_screen;
	unsigned int	*screen;
	unsigned int	*img;
	int	a;
	int b;
	int c;

	mlx_screen = mlx_new_image(game->mlx->mlx, TYPE_HOR_PIX, TYPE_VER_PIX);
	screen = (unsigned int *)mlx_get_data_addr(mlx_screen, &a, &b, &c);
	counter = -1;
	while (++counter < TYPE_HOR_PIX)
	{
		img = (unsigned int *)mlx_get_data_addr(game->source[counter].object, &a, &b, &c);
		pix_multi = game->map->sight_safe_margin / (game->source[counter].distance * TYPE_PIX_PER_OBJ);
		idx_y = -1;
		while (++idx_y < (TYPE_VER_PIX + 1) / 2)
		{
			if (TYPE_PIX_PER_OBJ * pix_multi / 2 + idx_y >= TYPE_VER_PIX / 2)
			{
				screen[counter + TYPE_HOR_PIX * idx_y] = img[
					(int)((((double)idx_y - (TYPE_VER_PIX - TYPE_PIX_PER_OBJ * pix_multi) / 2) / pix_multi) * (double)game->mlx->img_ver_size / (double)TYPE_OBJ_VER_PIX) * game->mlx->img_hor_size
					+ game->source[counter].object_pos
					];
				screen[counter + TYPE_HOR_PIX * (TYPE_VER_PIX - 1 - idx_y)] = img[
					(game->mlx->img_ver_size - (int)((((double)idx_y - (TYPE_VER_PIX - TYPE_PIX_PER_OBJ * pix_multi) / 2) / pix_multi * (double)game->mlx->img_ver_size / (double)TYPE_OBJ_VER_PIX))) * game->mlx->img_hor_size // y축 
					+ game->source[counter].object_pos // x 축
					];
			}
			else
			{
				screen[counter + TYPE_HOR_PIX * idx_y] = game->map->ceil_rgb;
				screen[counter + TYPE_HOR_PIX * (TYPE_VER_PIX - idx_y)] = game->map->floor_rgb;
			}
		}
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, mlx_screen, 0, 0);
}

void ray_cast_calc(t_render_source *s , t_map *m, t_mlx *mlx, int px)
{
	double	theta;
	int		bias_x;
	int		bias_y;
	double	near_x;
	double	near_y;

	s->render_screen_pos = px;
	theta = atan2((double)TYPE_HOR_PIX / 2.0 - (double)px, m->sight_safe_margin) + m->player.vision_theta;
	s->theta = theta;
	while (theta > 2 * TYPE_PI)
		theta -= 2 * TYPE_PI;
	while (theta < 0)
		theta += 2 * TYPE_PI;
	bias_x = 0;
	if (theta < TYPE_PI * 1.5 && theta >  TYPE_PI * 0.5)
		bias_x = -1; // x 축 음의 방향으로 ray 가 발사될 경우
	bias_y = 0;
	if (theta >  TYPE_PI)
		bias_y = -1; // y축 음의 방향으로 ray 가 발사될 경우
	near_x = (ceil(m->player.pos_x) - m->player.pos_x + bias_x);
	near_y = (ceil(m->player.pos_y) - m->player.pos_y + bias_y);
	while (1)
	{
		if (fabs(near_x * tan(theta)) <= fabs(near_y))
		{
			if (m->map[(int)(m->player.pos_y + near_y) - bias_y - 1][(int)(m->player.pos_x + near_x) + bias_x] == '1')
			{
				s->distance = fabs(near_x / cos(theta));
				s->object_pos = (double)mlx->img_hor_size * ((near_y - fabs(near_x * tan(theta)) - bias_y));
				if (bias_x != bias_y)
					s->object_pos *= -1;
				s->object_pos += mlx->img_hor_size * -bias_x;
				s->ob_x = m->player.pos_x + near_x;
				s->ob_y = m->player.pos_y + near_x * tan(theta);
				s->object = mlx->w_img;
				if (bias_x == -1)
					s->object = mlx->e_img;
				return ;
			}
			near_x += 1 + bias_x * 2;
		}
		else
		{
			if (m->map[(int)(m->player.pos_y + near_y) + bias_y][(int)(m->player.pos_x + near_x) - bias_x - 1] == '1')
			{
				s->distance = fabs(near_y / sin(theta));
				s->object_pos = (double)mlx->img_hor_size * ((near_x - fabs(near_y / tan(theta)) - bias_x));
				if (bias_x == bias_y)
					s->object_pos *= -1;
				s->object_pos += mlx->img_hor_size * (1 + bias_y);
				s->ob_y = m->player.pos_y + near_y;
				s->ob_x = m->player.pos_x + near_y / tan(theta);
				s->object = mlx->s_img;
				if (bias_y == -1)
					s->object = mlx->n_img;
				return ;
			}
			near_y += 1 + bias_y * 2;
		}
	}
}