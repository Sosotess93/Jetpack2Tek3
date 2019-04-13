/*
** init.c for  in /home/sofiane/Musique/client/sources/app
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:04:47 2017 sofiane
** Last update Tue Jul 18 12:47:37 2017 sofiane
*/

#include "prototypes.h"

t_com	g_com[4];

void	init(t_game *game, int socket) // OK init()
{
  //  pthread_mutex_init(&game->display, NULL);
  /* pthread_mutex_init(&game->coms_mutex, NULL); */
  game->s_fd = socket;
  game->id = 0;
  game->x = 0.0;
  game->y = 0.0;
  game->jetpack = 0;
  game->is_dead = 0;
  game->game_over = 0;
  game->game_started = 0;
  game->other_x = 0;
  game->other_y = 0;
  game->map = NULL;
  game->map_w = 0;
  game->map_h = 0;
}

void	ptr_init(t_com *cmd, char *name,
                    void (*func)(t_game*, int, char **)) // OK ptr_init
{
  cmd->command = strdup(name);
  cmd->func = func;
}

void	cmd_init() //OK cmd_init
{
  ptr_init(&(g_com[0]), "START", &lunch_game);
  ptr_init(&(g_com[1]), "PLAYER", &my_player);
  ptr_init(&(g_com[2]), "COIN", &coins);
  ptr_init(&(g_com[3]), "FINISH", &game_finish);
}

void	my_client(t_game *game, int socket, char **cmd) // my_client
{
  int	i;

  i = 0;
  cmd_init();
  while (i != 4)
    {
      if (strcmp(cmd[0], g_com[i].command) == 0)
	{
	  g_com[i].func(game, socket, &(cmd[1]));
	  return;
	}
      ++i;
    }
}
