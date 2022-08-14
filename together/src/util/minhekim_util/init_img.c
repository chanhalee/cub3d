/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:11:31 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/14 22:37:49 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	init_img(t_game *game)
{
	t_mlx	*m;
	void	*mlx;
	char	*temp;
	int		img_w;
	int		img_h;

	mlx = game->mlx.mlx;
	temp = game->map->n_path;
	game->mlx.n_img = mlx_xpm_file_to_image(mlx, temp, &img_w, &img_h);
	temp = game->map->s_path;
	game->mlx.s_img = mlx_xpm_file_to_image(mlx, temp, &img_w, &img_h);
	temp = game->map->w_path;
	game->mlx.w_img = mlx_xpm_file_to_image(mlx, temp, &img_w, &img_h);
	temp = game->map->e_path;
	game->mlx.e_img = mlx_xpm_file_to_image(mlx, temp, &img_w, &img_h);
	game->mlx.img_hor_size = img_w;
	game->mlx.img_ver_size = img_h;
	m = &(game->mlx);
	if (m->n_img && m->s_img && m->w_img && m->e_img)
		return (0);
	free_game_map(game);
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	return (1);
}
