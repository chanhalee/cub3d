#include"./do_not_submit.h"

void	print_render_source(t_render_source *r_s)
{
	int		counter;

	counter = -1;
	while (++counter < TYPE_HOR_PIX)
	{
		printf("[%d]dis: %lf, ", counter, r_s[counter].distance);
		printf("o_p: %d, ",r_s[counter].object_pos);
		printf("w_p: %d\n",r_s[counter].render_screen_pos);
	}
}