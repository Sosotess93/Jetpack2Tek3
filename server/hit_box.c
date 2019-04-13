/*
** hit_box.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Mon Jul 17 16:06:05 2017 Arthur Malaise
** Last update Tue Jul 18 16:04:25 2017 Arthur Malaise
*/

#include "server.h"

void	check_coin_hit_box(int pos_x, int pos_y, int i, t_data *data)
{
  char	buff[256];
  int	j;

  j = 0;
  if (data->map[(data->map_y - pos_y - 1) * data->map_x + pos_x] == 'c')
    {
      snprintf(buff, 256, "COIN %d %d %d\n", data->cli[i].sock, pos_x, pos_y);
      while (j < MAX_CLI)
	{
	  if (data->cli[j].state == CLI_ALIVE)
	    sock_send(data->cli[j].sock, buff);
	  j++;
	}
      data->cli[i].score++;
      data->map[(data->map_y - pos_y - 1) * data->map_x + pos_x] = '_';
    }
}

void	check_elec_hit_box(int pos_x, int pos_y, int i, t_data *data)
{
  if (data->map[(data->map_y - pos_y - 1) * data->map_x + pos_x] == 'e')
    data->cli[i].state = CLI_DEAD;
}
