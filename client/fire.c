/*
** fire.c for  in /home/sofiane/Musique/backup/sources
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Wed Jul 19 04:52:18 2017 sofiane
** Last update Wed Jul 19 05:01:26 2017 sofiane
*/

#include "prototypes.h"

void	fire(t_game *player)
{
  if (player->jetpack)
    {
      player->jetpack = 0;
      fd_write(player->s_fd, "FIRE 0\n", 0);
    }
  else
    {
      player->jetpack = 1;
      fd_write(player->s_fd, "FIRE 1\n", 0);
    }
}
