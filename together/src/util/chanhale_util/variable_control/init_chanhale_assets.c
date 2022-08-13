/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_chanhale_assets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:34:51 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/13 13:15:11 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

int	init_chanhale_assets(t_game *game)
{
	int	counter;

	game->source = (t_render_source *)malloc(sizeof(t_render_source)
			* TYPE_HOR_PIX);
	if (game->source == NULL)
	{
		printf("source not allocated: malloc fail error\n");
		return (1);
	}
	counter = -1;
	while (++counter < TYPE_HOR_PIX)
		init_t_render_source(&(game->source[counter]));
	game->map->sight_safe_margin = ((double)TYPE_HOR_PIX / 2.0)
		/ tan(((double)TYPE_ANGLE / 360.0) * TYPE_PI);
	return (0);
}
