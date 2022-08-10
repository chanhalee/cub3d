/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:44:23 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/10 15:10:35 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RayCasting.h"

int Render(t_map *map)
{
	
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
				s->object_pos = (double)TYPE_PIX_PER_OBJ * ((near_y - fabs(near_x * tan(theta)) - bias_y));
				if (bias_x != bias_y)
					s->object_pos *= -1;
				s->object_pos += TYPE_PIX_PER_OBJ * -bias_x;
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
				s->object_pos = (double)TYPE_PIX_PER_OBJ * ((near_x - fabs(near_y / tan(theta)) - bias_x));
				if (bias_x == bias_y)
					s->object_pos *= -1;
				s->object_pos += TYPE_PIX_PER_OBJ * (1 + bias_y);
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