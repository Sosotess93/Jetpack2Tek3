/*
** collision.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Sun Jul 16 17:21:48 2017 Arthur Malaise
** Last update Tue Jul 18 19:12:11 2017 Arthur Malaise
*/

#include "server.h"

static void	check_coin(int i, t_data *data)
{
  int		pos_x;
  int		pos_y;

  pos_x = (data->cli[i].pos_x - (int)data->cli[i].pos_x > 0 ?
	   (int)data->cli[i].pos_x + 1 : (int)data->cli[i].pos_x);
  pos_y = (data->cli[i].pos_y - (int)data->cli[i].pos_y > 0 ?
	   (int)data->cli[i].pos_y + 1 : (int)data->cli[i].pos_y);
  check_coin_hit_box((int)data->cli[i].pos_x, (int)data->cli[i].pos_y , i, data);
  check_coin_hit_box(pos_x, (int)data->cli[i].pos_y , i, data);
  check_coin_hit_box((int)data->cli[i].pos_x, pos_y , i, data);
  check_coin_hit_box(pos_x, pos_y , i, data);
}

static void	check_elec(int i, t_data *data)
{
  int		pos_x;
  int		pos_y;

  pos_x = (data->cli[i].pos_x - (int)data->cli[i].pos_x > 0 ?
	   (int)data->cli[i].pos_x + 1 : (int)data->cli[i].pos_x);
  pos_y = (data->cli[i].pos_y - (int)data->cli[i].pos_y > 0 ?
	   (int)data->cli[i].pos_y + 1 : (int)data->cli[i].pos_y);
  check_elec_hit_box((int)data->cli[i].pos_x, (int)data->cli[i].pos_y , i, data);
  check_elec_hit_box(pos_x, (int)data->cli[i].pos_y , i, data);
  check_elec_hit_box((int)data->cli[i].pos_x, pos_y , i, data);
  check_elec_hit_box(pos_x, pos_y , i, data);
}

static void	check_end(int i, t_data *data)
{
  if (data->cli[i].pos_x >= data->map_x)
    data->cli[i].state = CLI_WIN;
}

void	collision(t_data *data)
{
  int		i;

  i = 0;
  while (i < MAX_CLI)
    {
      if (data->cli[i].state == CLI_ALIVE)
	{
	  check_coin(i, data);
	  check_elec(i, data);
	  check_end(i, data);
	}
      i++;
    }
}
