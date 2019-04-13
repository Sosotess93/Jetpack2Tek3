/*
** my_map.c for  in /home/sofiane/Musique/client/sources/commands
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:14:21 2017 sofiane
** Last update Tue Jul 18 17:51:56 2017 sofiane
*/

#include "prototypes.h"

int	my_map(int socket, t_game *player) //OK my_map
{
  char	msg[4096];
  char	**av;
  int	ret;
  int	r;

  ret = 0;
  fd_write(socket, "MAP\n", 0);
  r = read(socket, msg, 4096);
  if (r > 1)
    {
      msg[r - 1] = '\0';
      av = my_str_to_wordtab(msg, ' ');
      if ((size_of_tab(av) == 4) &&
	  (strncmp("MAP", av[0], strlen("MAP")) == 0))
	{
          player->map_w = atoi(av[1]);
          player->map_h = atoi(av[2]);
	  if(player->map)
            free(player->map);
	  player->map = strdup(av[3]);
	  ret = 0;
        }
      else
	ret = 1;
      free_my_tab(av);
    }
  pthread_create(&player->display, NULL, map_charge, (void *)player);
  //  pthread_join(player->display, NULL);
  return (ret);
}
