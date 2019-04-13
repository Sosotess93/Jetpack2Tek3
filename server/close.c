/*
** close.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Sun Jul 16 17:02:30 2017 Arthur Malaise
** Last update Sun Jul 16 17:07:19 2017 Arthur Malaise
*/

#include "server.h"

void	close_game(t_data *data)
{
  int		i;

  i = 0;
  while (i < MAX_CLI)
    {
      if (data->cli[i].state != CLI_UNDECLARED)
	close(data->cli[i].sock);
      i++;
    }
  close(data->sock);
  free(data->map);
}
