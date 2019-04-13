/*
** position.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Sun Jul 16 16:03:05 2017 Arthur Malaise
** Last update Tue Jul 18 19:09:36 2017 Arthur Malaise
*/

#include "server.h"

void	send_pos(t_data *data)
{
  char	buff[256];
  int	i;
  int	j;
  
  i = 0;
  while (i < MAX_CLI)
    {
      if (data->cli[i].state == CLI_ALIVE)
	{
	  j = 0;
	  while (j < MAX_CLI)
	    {
	      if (data->cli[j].state == CLI_ALIVE)
		{
		  snprintf(buff, 256, "PLAYER %d %f %f %d\n",
			   data->cli[j].sock, data->cli[j].pos_x,
			   data->cli[j].pos_y, data->cli[j].score);
		  sock_send(data->cli[i].sock, buff);
		}
	      j++;
	    }
	}
      i++;
    }
}

void	set_pos(t_data *data)
{
  float	pos_y;
  int	i;

  i = 0;
  pos_y = 0;
  while (i < MAX_CLI)
    {
      if (data->cli[i].state == CLI_ALIVE)
	{
	  data->cli[i].pos_x += 0.2;
	  pos_y = data->cli[i].pos_y + data->cli[i].gravity / 5.;
	  data->cli[i].pos_y = (pos_y <= 0 ? 0 :
				(pos_y >= data->map_y - 1 ?
				 data->map_y - 1 : pos_y));
	}
      i++;
    }
}
