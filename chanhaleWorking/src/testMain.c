/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:34 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/10 15:07:34 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./header/RayCasting.h"
#include"./util/do_not_submit/do_not_submit.h"

int main(void)
{
	t_game game;
	int		counter;

	counter = -1;
	game.source = (t_render_source *)malloc(sizeof(t_render_source) * TYPE_HOR_PIX);
	game.map = (t_map *)malloc(sizeof(t_map));
	while(++counter < TYPE_HOR_PIX)
		init_t_render_source(&(game.source[counter]));
	if (TYPE_ANGLE > 170 || TYPE_ANGLE < 10)
		return (0);
	game.map->size_x = 20;
	game.map->size_y = 10;
	game.map->player.vision_theta = TYPE_PI * 1.0 / 4.0;
	game.map->sight_safe_margin = ((double)TYPE_HOR_PIX / 2.0) / tan(((double)TYPE_ANGLE / 360.0) * TYPE_PI);
	game.map->player.pos_x = 2.0;
	game.map->player.pos_y = 2.0;
	game.map->map = (char**)malloc(sizeof(char *)*(game.map->size_y+1));
	counter = -1;
	while(++counter < game.map->size_y)
	{
		if(counter == 0)
			game.map->map[counter] = ft_strdup("1111111111");
			//map.map[counter] = ft_strdup("11111111111111111111");
		else if(counter == game.map->size_y-1)
			game.map->map[counter] = ft_strdup("1111111111");
			//map.map[counter] = ft_strdup("11111111111111111111");
		else if(counter == 3)
			game.map->map[counter] = ft_strdup("1000110001");
		else
			game.map->map[counter] = ft_strdup("1000000001");
			//map.map[counter] = ft_strdup("10000000000100000001");
	}
	counter = -1;
	while(++counter < TYPE_HOR_PIX)
	{
		ray_cast_calc(&(game.source[counter]), game.map, game.mlx, counter);
	}
	print_render_source(game.source);
	print_map(game.map);
	counter = -1;
	while(++counter < game.map->size_y)
	{
		free(game.map->map[counter]);
	}
	free(game.map->map);
	free(game.map);
	free(game.source);
	system("leaks cub3d");
	return (0);
}

// cd chanhaleWorking/src
// gcc *.c ./*/*.c ./*/*/*.c -o test && ./test 