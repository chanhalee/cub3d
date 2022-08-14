/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:16:48 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/14 22:33:45 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	move_w(t_game *game)
{
	t_vector	*player;

	player = &(game->map->player);
	player->pos_x += TYPE_MAN_PLAYER_POS * cos(player->vision_theta);
	player->pos_y += TYPE_MAN_PLAYER_POS * sin(player->vision_theta);
	return ;
}

void	move_a(t_game *game)
{
	t_vector	*player;

	player = &(game->map->player);
	player->pos_x -= TYPE_MAN_PLAYER_POS * sin(player->vision_theta);
	player->pos_y += TYPE_MAN_PLAYER_POS * cos(player->vision_theta);
	return ;
}

void	move_s(t_game *game)
{
	t_vector	*player;

	player = &(game->map->player);
	player->pos_x -= TYPE_MAN_PLAYER_POS * cos(player->vision_theta);
	player->pos_y -= TYPE_MAN_PLAYER_POS * sin(player->vision_theta);
	return ;
}

void	move_d(t_game *game)
{
	t_vector	*player;

	player = &(game->map->player);
	player->pos_x += TYPE_MAN_PLAYER_POS * sin(player->vision_theta);
	player->pos_y -= TYPE_MAN_PLAYER_POS * cos(player->vision_theta);
	return ;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_w(game);
	else if (keycode == KEY_S)
		move_s(game);
	else if (keycode == KEY_A)
		move_a(game);
	else if (keycode == KEY_D)
		move_d(game);
	else if (keycode == KEY_LEFT)
		game->map->player.vision_theta += TYPE_MAN_PLAYER_ANGLE;
	else if (keycode == KEY_RIGHT)
		game->map->player.vision_theta -= TYPE_MAN_PLAYER_ANGLE;
	else if (keycode == KEY_ESC)
		exit_game(game);
	keep_distance_with_wall(game->map);
	if (render(game) == 1)
		;//render fail shall we exit_game? -chanhale added-
	return (0);
}
