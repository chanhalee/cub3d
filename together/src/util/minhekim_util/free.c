/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:00:40 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/15 01:51:02 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	free_texpath(t_map *map)
{
	if (map->s_path != NULL)
		free(map->s_path);
	if (map->n_path != NULL)
		free(map->n_path);
	if (map->w_path != NULL)
		free(map->w_path);
	if (map->e_path != NULL)
		free(map->e_path);
	return ;
}

void	free_map(t_map *map, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	return ;
}

void	free_map_all(t_map *map, int limit)
{
	free_map(map, limit);
	free_texpath(map);
	return ;
}

void	free_game_map(t_game *game)
{
	free_texpath(game->map);
	free_map(game->map, game->map->size_x);
	free(game->map);
	return ;
}

void	free_game_mlx(t_game *game)
{
	if (game->mlx.win != NULL)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.n_img != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.n_img);
	if (game->mlx.s_img != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.s_img);
	if (game->mlx.e_img != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.e_img);
	if (game->mlx.w_img != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.w_img);
}
