/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:16:48 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/14 22:41:08 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	exit_game(t_game *game)
{
	free_game_map(game);
	free_game_mlx(game);
	free_chanhale_assets(game);
	exit(0);
	return (0);
}

int	exit_hook(t_game *game)
{
	return (exit_game(game));
}
