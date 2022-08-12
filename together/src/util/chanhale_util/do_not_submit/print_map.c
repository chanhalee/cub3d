#include "./do_not_submit.h"

void	print_map(t_map *map)
{
	int		counter;

	counter = map->size_y;
	printf("\n==========print_map==========\n");
	while(--counter >= 0)
	{
		printf("[%d] %s\n", counter, map->map[counter]);
	}
	printf("p_pos: %lf, %lf\n", map->player.pos_x,  map->player.pos_x);
	printf("p_theta: %lf\n", map->player.vision_theta / TYPE_PI * 180);
	printf("=============================\n");
}