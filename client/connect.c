/*
** connect.c for  in /home/sofiane/Musique/client/sources/socket
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:17:18 2017 sofiane
** Last update Tue Jul 18 06:36:57 2017 sofiane
*/

#include "prototypes.h"

void		my_client_connect(int ac, char **av, t_server *game)
{
  int		i;
  char		*ip;
  char		*port;

  i = 0;
  while (i != ac)
    {
      if (strncmp("-h", av[i], strlen("-h")) == 0)
	ip = av[i + 1];
      if (strncmp("-p", av[i], strlen("-p")) == 0)
	port = av[i + 1];
      i++;
    }
  game->sock_in.sin_family = AF_INET;
  game->sock_in.sin_port = htons(atoi(port));
  game->sock_in.sin_addr.s_addr = inet_addr(ip);
}

int		my_connexion(int ac, char **av)
{
  t_server	game;

  my_client_connect(ac, av, &game);
  if (!(game.prot = getprotobyname("TCP")))
    return (1);
  if (((game.server_fd = socket
        (AF_INET,SOCK_STREAM,game.prot->p_proto)) == -1))
    {
      close(game.server_fd);
      return (1);
    }
  if (connect(game.server_fd, (sock)&game.sock_in, sizeof(game.sock_in)) == -1)
    {
      close(game.server_fd);
      return (1);
    }
  return (ready_for_play(game.server_fd));
}
