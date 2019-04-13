/*
** loops.c for  in /home/sofiane/Musique/client/sources/game
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:23:02 2017 sofiane
** Last update Wed Jul 19 12:18:48 2017 sofiane
*/

#include "prototypes.h"

void		*loops(void *data, int socket) // OK loops()
{
  int		r;
  char		buf[4096];
  char		**tab;
  t_game	*infos;
  fd_set	readset;

  infos = (t_game*)data;
  FD_ZERO(&readset);
  FD_SET(socket, &readset);;
  while (infos->finish != 1)
    {
      if (select(socket + 1, &readset, NULL, NULL, NULL) > 0)
	{
	  r = read(infos->s_fd, buf, 4096);
	  if (r > 1)
	    {
              buf[r - 1] = '\0';
	      tab = my_str_to_wordtab(buf, '\n');
	      lines_count(infos, tab);
              bzero(buf, 4096); // prefère memset à bzero.
	      free_my_tab(tab);
	    }
	  else if (r == (-1))
	    {
	      infos->game_over = 1;
              close(infos->s_fd);
	      return (void *)1;
            }
	}
      else
	return (void *)1;
    }
  return (void *)1;
}

int		ready_for_play(int socket) //OK ready_for_play()
{
  t_game        game;
  // pthread_t     disp_th;
  //  pthread_t     network_th;

  init(&game, socket);
  if ((my_id(socket, &game) == 1) ||
      (my_map(socket, &game) == 1))
    {
      close(socket);
      return (1);
    }
  if ((game.id != 0) && (game.map))
    {
      fd_write(socket, "READY\n", 0);
      /* pthread_mutex_lock(&game.display_mutex); */
      /* pthread_create(&network_th, NULL, loops, (void *)&game); */
      /* pthread_join(network_th, NULL); */
      loops(&game, socket);
      return (0);
    }
  return (0);
}
