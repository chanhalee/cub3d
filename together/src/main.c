/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:34:16 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/14 22:40:51 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "./header/cub3d.h"

void	leakscheck(void)
{
	system("leaks cub3d");
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit(leakscheck);
	init_game(&game);
	if (argc != 2)
		return (0);
	game.map = (t_map *)malloc(sizeof(t_map));
	if (game.map == NULL)
		return (1);
	if (parse_map(game.map, argv[1]))
	{
		free(game.map);
		return (0);
	}
	game.mlx.mlx = mlx_init();
	game.mlx.win = mlx_new_window(game.mlx.mlx, TYPE_HOR_PIX, TYPE_VER_PIX, "cub3d");
	if (init_img(&game) != 0)
		return (1);
	if (init_chanhale_assets(&game))
		exit_game(&game);
	render(&game);
	mlx_hook(game.mlx.win, X_EVENT_KEY_PRESS, 0, key_press, &game);
	mlx_hook(game.mlx.win, X_EVENT_EXIT, 0, exit_hook, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
