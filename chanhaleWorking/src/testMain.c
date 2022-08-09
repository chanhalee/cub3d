/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:34 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/10 02:03:33 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./header/RayCasting.h"
#include"./util/do_not_submit/do_not_submit.h"

int main(void)
{
	t_render_source	source[TYPE_HOR_PIX];
	t_map	map;
	int		counter;

	counter = -1;
	while(++counter < TYPE_HOR_PIX)
		init_t_render_source(&(source[counter]));
	if (TYPE_ANGLE > 170 || TYPE_ANGLE < 10)
		return (0);
	map.size_x = 20;
	map.size_y = 10;
	map.player.vision_theta = TYPE_PI * 1.0 / 4.0;
	map.sight_safe_margin = ((double)TYPE_HOR_PIX / 2.0) / tan(((double)TYPE_ANGLE / 360.0) * TYPE_PI);
	printf("%lf\n", map.sight_safe_margin);
	map.player.pos_x = 2.0;
	map.player.pos_y = 2.0;
	map.map = (char**)malloc(sizeof(char *)*(map.size_y+1));
	counter = -1;
	while(++counter < map.size_y)
	{
		if(counter == 0)
			map.map[counter] = ft_strdup("1111111111");
			//map.map[counter] = ft_strdup("11111111111111111111");
		else if(counter == map.size_y-1)
			map.map[counter] = ft_strdup("1111111111");
			//map.map[counter] = ft_strdup("11111111111111111111");
		else
			map.map[counter] = ft_strdup("1000000001");
			//map.map[counter] = ft_strdup("10000000000000000001");
	}
	counter = -1;
	while(++counter < TYPE_HOR_PIX)
	{
		ray_cast_calc(&(source[counter]), &map, counter);
	}
	print_render_source(source);
	print_map(&map);
	counter = -1;
	while(++counter < map.size_y)
	{
		free(map.map[counter]);
	}
	free(map.map);
}