/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_distance_with_wall.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:54:32 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/13 11:57:49 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	keep_distance_with_wall(t_map *m)
{
	double	exp_x;
	double	exp_y;
	int		int_x;
	int		int_y;

	int_x = (int)floor(m->player.pos_x);
	int_y = (int)floor(m->player.pos_y);
	exp_x = m->player.pos_x - int_x;
	exp_y = m->player.pos_y - int_y;
	if (m->map[int_y][int_x -1] == '1')
		if (exp_x < TYPE_SAFE_DISTANCE)
			m->player.pos_x = int_x + TYPE_SAFE_DISTANCE;
	if (m->map[int_y - 1][int_x] == '1')
		if (exp_y < TYPE_SAFE_DISTANCE)
			m->player.pos_y = int_y + TYPE_SAFE_DISTANCE;
	if (m->map[int_y][int_x + 1] == '1')
		if (exp_x > (1.0 - TYPE_SAFE_DISTANCE))
			m->player.pos_x = int_x + 1 - TYPE_SAFE_DISTANCE;
	if (m->map[int_y + 1][int_x] == '1')
		if (exp_y > (1.0 - TYPE_SAFE_DISTANCE))
			m->player.pos_y = int_y + 1 - TYPE_SAFE_DISTANCE;
	if (m->player.vision_theta < 0)
		m->player.vision_theta += 2 * TYPE_PI;
	if (m->player.vision_theta > 2 * TYPE_PI)
		m->player.vision_theta -= 2 * TYPE_PI;
}
