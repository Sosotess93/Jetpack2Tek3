/*
** end.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Tue Jul 18 16:23:04 2017 Arthur Malaise
** Last update Tue Jul 18 19:10:55 2017 Arthur Malaise
*/

#include "server.h"

int	find_cli_max_score(t_data *data)
{
  int	max_score;
  int	cli;
  int	i;

  i = 0;
  cli = 0;
  max_score = 0;
  while (i < MAX_CLI)
    {
      if ((data->cli[i].state == CLI_ALIVE
	  || data->cli[i].state == CLI_WIN)
	  && max_score < data->cli[i].score)
	{
	  max_score = data->cli[i].score;
	  cli = i;
	}
      i++;
    }
  return (data->cli[cli].sock);
}

void	end_elec(t_data *data)
{
  int	nb_cli_dead;
  char	buff[256];
  int	i;
  
  i = 0;
  nb_cli_dead = 0;
  while (i < MAX_CLI)
    if (data->cli[i++].state == CLI_DEAD)
      nb_cli_dead++;
  i = 0;
  if (nb_cli_dead == data->nb_cli)
    while (i < MAX_CLI)
      {
	if (data->cli[i].state == CLI_DEAD)
	  {
	    snprintf(buff, 256, "FINISH -1\n");
	    sock_send(data->cli[i].sock, buff);
	  }
	i++;
      }
  else
    while (i < MAX_CLI)
      {
	if (data->cli[i].state == CLI_DEAD || data->cli[i].state == CLI_ALIVE)
	  {
	    snprintf(buff, 256, "FINISH %d\n", find_cli_max_score(data));
	    sock_send(data->cli[i].sock, buff);
	  }
	i++;
      }
}

void	end_map(t_data *data)
{
  char	buff[256];
  int	i;

  i = 0;
  if (find_cli_max_score(data) == data->cli[0].sock
      && data->cli[0].score == 0)
    while (i < MAX_CLI)
      {
	if (data->cli[i].state == CLI_WIN)
	  {
	    snprintf(buff, 256, "FINISH -1\n");
	    sock_send(data->cli[i].sock, buff);
	  }
	i++;
      }
  else
    while (i < MAX_CLI)
      {
	if (data->cli[i].state == CLI_WIN)
	  {
	    snprintf(buff, 256, "FINISH %d\n", find_cli_max_score(data));
	    sock_send(data->cli[i].sock, buff);
	  }
	i++;
      }
}

void	end(t_data *data)
{
  int	i;

  i = 0;
  while (i < MAX_CLI)
    {
      if (data->cli[i].state == CLI_DEAD)
	{
	  end_elec(data);
	  return ;
	}
      else if (data->cli[i].state == CLI_WIN)
	{
	  end_map(data);
	  return ;
	}
      i++;
    }
}
