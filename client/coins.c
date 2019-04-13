/*
** coins.c for  in /home/sofiane/Musique/client/sources
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:53:30 2017 sofiane
** Last update Tue Jul 18 13:18:16 2017 sofiane
*/

#include "prototypes.h"

void		coins(t_game *player, int socket, char **cmd) //OK coins();
{
  float		_x;
  float		_y;
  int		offset;

  (void)socket;
  if (size_of_tab(cmd) == 3)
    {
      _x = atof(cmd[1]);
      _y = atof(cmd[2]);
      offset = (int)_x + (((ADJUST_Y(player->map_h,(int)_y)) - 1)
			     *player->map_w);
      player->map[offset] = '_';
    }
}
