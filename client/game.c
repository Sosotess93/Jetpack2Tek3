/*
** game.c for  in /home/sofiane/Musique/client/sources
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:56:38 2017 sofiane
** Last update Tue Jul 18 13:18:36 2017 sofiane
*/

#include "prototypes.h"

void		lunch_game(t_game *player, int socket, char **cmd) //OK lunch_game
{
  (void)cmd;
  (void)socket;
  player->game_started = 1;
}

void            game_finish(t_game *player, int socket, char **cmd) //OK game_finish
{
  char         *id_buf;

  (void)socket;
  id_buf = my_malloc(player->id);
  if (strncmp(id_buf, cmd[0], strlen(id_buf)) == 0)
    printf("You win\n");
  else if (strncmp(cmd[0], "-1", strlen("-1")) == 0)
    printf("Nobody wins\n");
  else
    printf("You lose\n");
  free(id_buf);
  player->game_over = 1;
  exit(0);
}
