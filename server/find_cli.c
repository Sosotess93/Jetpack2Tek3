/*
** find_cli.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Thu Jul 13 17:19:24 2017 Arthur Malaise
** Last update Tue Jul 18 11:49:48 2017 Arthur Malaise
*/

#include "server.h"

static void	check_buff(int i, char *buff, t_data *data)
{
  char		send[4096];

  if (!strncmp(buff, "ID", 2))
    {
      snprintf(send, 256, "ID %d\n", data->cli[i].sock);
      sock_send(data->cli[i].sock, send);
    }
  if ((strlen(buff) > 3 &&
       !strncmp(buff + 3, "MAP", 3)) || !strncmp(buff, "MAP", 3))
    {
      snprintf(send, 4096, "MAP %d %d %s\n",
	       data->map_x, data->map_y, data->map);
      sock_send(data->cli[i].sock, send);
    }
  else if (!strncmp(buff, "READY", 5))
    data->cli[i].state = CLI_READY;
}

static void    check_cli(t_data *data)
{
  char		buff[256];
  int		i;

  i = 0;
  while (i < MAX_CLI)
    {
      if (data->cli[i].state == CLI_DECLARED
	  && sock_recv(data->cli[i].sock, buff, 256, NON_BLOCK) == OK)
	check_buff(i, buff, data);
      i++;
    }
}

static int	check_cli_ready(t_data *data)
{
  int		nb_cli_ready;
  int		i;

  i = 0;
  nb_cli_ready = 0;
  while (i < MAX_CLI)
    {
      if (data->cli[i].state == CLI_READY)
	nb_cli_ready++;
      i++;
    }
  return (nb_cli_ready);
}

void	find_cli(t_data *data)
{
  while (data->nb_cli < 2 || check_cli_ready(data) < 2)
    {
      if ((data->cli[data->nb_cli].sock = sock_accept(data->sock)) != ERROR)
	data->cli[data->nb_cli++].state = CLI_DECLARED;
      check_cli(data);
    }
}
