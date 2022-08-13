/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:40:47 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/13 12:46:52 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

void	init_game(t_game *game)
{
	game->keys = NULL;
	game->map = NULL;
	game->mlx.n_img = NULL;
	game->mlx.w_img = NULL;
	game->mlx.s_img = NULL;
	game->mlx.e_img = NULL;
	game->mlx.img_hor_size = 0;
	game->mlx.img_ver_size = 0;
	game->mlx.mlx = NULL;
	game->mlx.win = NULL;
	game->source = NULL;
}
