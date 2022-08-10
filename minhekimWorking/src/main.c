#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "minhee.h"
//used printf: replace with a custom error writing function

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_EXIT		17

#define	KEY_ESC	53
#define KEY_W	13
#define KEY_A	0
#define	KEY_S	1
#define	KEY_D	2
#define KEY_LEFT	123
#define	KEY_RIGHT	124

void	exit_game(void) // <- need to free all heap memory: pass struct!
{
	printf("bye!\n");
	exit(0);
}

void	key_press(int keycode)
{
	if (keycode == KEY_W)
		printf("move up\n");
	else if (keycode == KEY_S)
		printf("move down\n");
	else if (keycode == KEY_A)
		printf("move left\n");
	else if (keycode == KEY_D)
		printf("move right\n");
	else if (keycode == KEY_LEFT)
		printf("rotate left\n");
	else if (keycode == KEY_RIGHT)
		printf("rotate right\n");
	else if (keycode == KEY_ESC)
		exit_game();
}

void	exit_hook(void)
{
	return exit_game();
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_map	map;

	// parse map & check
	if (argc != 2)
	{
		printf("wrong number of arguments\n");
		return (0);
	}
	if (parse_map(&map, argv[1]))
	{
		printf("map error\n");
		return (0);
	}
	// creating window
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "cub3d");

	// need to pass arg(struct pointer) in place of null
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(win, X_EVENT_EXIT, 0, &exit_hook, NULL);
	mlx_loop(mlx);

	return (0);
}
