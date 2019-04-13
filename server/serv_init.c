/*
** serv_init.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Thu Jul 13 12:06:40 2017 Arthur Malaise
** Last update Fri Jul 14 14:25:58 2017 Arthur Malaise
*/

#include "server.h"

int		init_serv(t_data *data)
{
  data->sock = sock_listen(data->port, 10, "TCP");
  return (OK);
}

int		run_serv(t_data *data)
{
  find_cli(data);
  return (OK);
}
