#include "minhee.h"

void    free_texpath(t_map *map)
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

void    free_map(t_map *map, int limit) // double free
{
    int i;

    i = 0;
    while (i < limit)
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    return ;
}

void    free_game_map(t_game *game)
{
    free_texpath(game->map);
    free_map(game->map, game->map->size_x);
    free(game->map);
    return ;
}

void    free_game_mlx(t_game *game)
{
    mlx_destroy_window(game->mlx.mlx, game->mlx.win);
    mlx_destroy_image(game->mlx.mlx, game->mlx.n_img);
    mlx_destroy_image(game->mlx.mlx, game->mlx.s_img);
    mlx_destroy_image(game->mlx.mlx, game->mlx.e_img);
    mlx_destroy_image(game->mlx.mlx, game->mlx.w_img);
}