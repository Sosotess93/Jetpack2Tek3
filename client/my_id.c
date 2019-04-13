/*
** my_id.c for  in /home/sofiane/Musique/client/sources/commands
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:12:49 2017 sofiane
** Last update Tue Jul 18 13:11:37 2017 sofiane
*/

#include "prototypes.h"

int	my_id(int socket, t_game *player) //OK my_id
{
  int	r;
  int	ret;
  char	msg[4096];
  char	**av;

  ret = 0;
  fd_write(socket, "ID\n", 0);
  r = read(socket, msg, 4096);
  if (r > 1)
    {
      msg[r - 1] = '\0';
      av = my_str_to_wordtab(msg, ' ');
      if ((size_of_tab(av) == 2) &&
	  (strncmp("ID", av[0], strlen("ID")) == 0))
	{
	  player->id = atoi(av[1]);
	  ret = 0;
	}
      else
	ret = 1;
      free_my_tab(av);
    }
  return (ret);
}
