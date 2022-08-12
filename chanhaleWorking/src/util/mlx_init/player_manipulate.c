
#include "../../header/RayCasting.h"

int	_(t_game *game)
{
	//W press
	game->map->player.pos_y += TYPE_MAN_PLAYER_POS;
	//A press
	game->map->player.pos_x -= TYPE_MAN_PLAYER_POS;
	//S press
	game->map->player.pos_y -= TYPE_MAN_PLAYER_POS;
	//D press
	game->map->player.pos_x += TYPE_MAN_PLAYER_POS;
	//left press
	game->map->player.vision_theta += TYPE_MAN_PLAYER_ANGLE;
	//right press
	game->map->player.vision_theta -= TYPE_MAN_PLAYER_ANGLE;
}
//w press
//