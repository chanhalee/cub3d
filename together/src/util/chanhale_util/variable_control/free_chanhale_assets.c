/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chanhale_assets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:21:59 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/13 13:15:22 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

void	free_chanhale_assets(t_game *game)
{
	if (game->source != NULL)
		free(game->source);
	game->source = NULL;
}
