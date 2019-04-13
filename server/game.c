/*
** game.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Sun Jul 16 11:52:35 2017 Arthur Malaise
** Last update Tue Jul 18 19:28:54 2017 Arthur Malaise
*/

#include "server.h"

static void	set_cli(t_data *data)
{
  int		i;

  i = 0;
  while (i < MAX_CLI)
    {
      if (data->cli[i].state == CLI_READY)
	{
	  data->cli[i].state = CLI_ALIVE;
	  data->cli[i].pos_y = data->map_y / 2;
	  data->cli[i].gravity = data->gravity;
	  sock_send(data->cli[i].sock, "START\n");
	}
      i++;
    }
}

void	read_fire(t_data *data)
{
  char	buff[7];
  int	i;

  i = 0;
  while (i < MAX_CLI)
    {
      if (data->cli[i].state == CLI_ALIVE)
	if (sock_recv(data->cli[i].sock, buff, 7, NON_BLOCK) == OK)
	  if ((!strncmp(buff, "FIRE 0", 6) || !strncmp(buff, "FIRE 1", 6)))
	    data->cli[i].gravity *= -1;
      i++;
    }
}

static int	check_cli_alive(t_data *data)
{
  int		nb_cli_alive;
  int		i;

  i = 0;
  nb_cli_alive = 0;
  while (i < MAX_CLI)
    {
      if (data->cli[i].state == CLI_ALIVE)
	nb_cli_alive++;
      i++;
    }
  return (nb_cli_alive);
}

int	run_game(t_data *data)
{
  set_cli(data);
  data->nb_cli_alive = check_cli_alive(data);
  while (data->nb_cli_alive == check_cli_alive(data))
    {
      collision(data);
      read_fire(data);
      send_pos(data);
      set_pos(data);
      usleep(40000);
    }
  end(data);
  return (OK);
}
