/*
** player.c for  in /home/sofiane/Musique/client/sources/player
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:49:27 2017 sofiane
** Last update Tue Jul 18 13:04:28 2017 sofiane
*/

#include "prototypes.h"

void		my_player(t_game *info, int socket, char **cmd) //OK my_player
{
  char		*id_buf;
  float		x_buf;
  float		y_buf;
  int		score_buf;

  (void)socket;
  if (size_of_tab(cmd) == 4)
    {
      id_buf = my_malloc(info->id);
      x_buf = atof(cmd[1]);
      y_buf = atof(cmd[2]);
      score_buf = atoi(cmd[3]);
      if (strncmp(id_buf, cmd[0], strlen(id_buf)) == 0)
	{
	  info->x = x_buf;
	  info->y = y_buf;
	  info->score = score_buf;
	}
      else
	{
	  info->other_x = x_buf;
	  info->other_y = y_buf;
	  info->other_score = score_buf;
	}
      free(id_buf);
    }
}
