#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "minhee.h"
//used printf: replace with a custom error writing function

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE	3
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

void	key_press(int keycode, t_keys *keys)
{
	if (keycode == KEY_W)
		keys->w = 1;
	else if (keycode == KEY_S)
		keys->s = 1;
	else if (keycode == KEY_A)
		keys->a = 1;
	else if (keycode == KEY_D)
		keys->d = 1;
	else if (keycode == KEY_LEFT)
		keys->left = 1;
	else if (keycode == KEY_RIGHT)
		keys->right = 1;
	else if (keycode == KEY_ESC)
		exit_game();
}

void	key_release(int keycode, t_keys *keys)
{
	if (keycode == KEY_W)
		keys->w = 0;
	else if (keycode == KEY_S)
		keys->s = 0;
	else if (keycode == KEY_A)
		keys->a = 0;
	else if (keycode == KEY_D)
		keys->d = 0;
	else if (keycode == KEY_LEFT)
		keys->left = 0;
	else if (keycode == KEY_RIGHT)
		keys->right = 0;
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
	t_keys	keys;

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
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &keys);
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_release, &keys);
	mlx_hook(win, X_EVENT_EXIT, 0, &exit_hook, NULL);
	mlx_loop(mlx);

	return (0);
}
