/*
** server.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Thu Jul 13 11:50:36 2017 Arthur Malaise
** Last update Tue Jul 18 20:13:33 2017 Arthur Malaise
*/

#include "server.h"

static void	init_cli(t_data *data)
{
  int		i;

  i = 0;
  while (i < MAX_CLI)
    {
      data->cli[i].sock = 0;
      data->cli[i].pos_x = 0;
      data->cli[i].pos_y = 0;
      data->cli[i].state = CLI_UNDECLARED;
      data->cli[i].score = 0;
      i++;
    }
}

static void	init_data(t_data *data)
{
  data->port = 0;
  data->gravity = 0;
  data->path_map = NULL;
  data->map_x = 0;
  data->map_y = 0;
  data->map = NULL;
  data->sock = 0;
  data->nb_cli = 0;
  data->tv.tv_sec = 0;
  data->tv.tv_usec = 10;
  init_cli(data);
}

int		main(int ac, char *av[])
{
  t_data	data;
  int		ret_vl;

  init_data(&data);
  ret_vl = OK;
  if (parsing_serv(ac, av, &data) == ERROR
      || init_serv(&data) == ERROR
      || run_serv(&data) == ERROR
      || run_game(&data) == ERROR)
    ret_vl = RET_ERR;
  close_game(&data);
  return (ret_vl);
}
