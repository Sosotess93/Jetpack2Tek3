/*
** parsing_serv.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Thu Jul 13 15:59:48 2017 Arthur Malaise
** Last update Tue Jul 18 20:15:41 2017 Arthur Malaise
*/

#include "server.h"

static int	check_map(t_data *data)
{
  int		map_size;
  int		i;

  i = 0;
  map_size = data->map_x * data->map_y;
  while (i < map_size)
    {
      if (data->map[i] && data->map[i] != '_'
	  && data->map[i] != 'c' && data->map[i] != 'e')
      	return (ERROR);
      i++;
    }
  return (OK);
}

static int	map_line(t_data *data, char *tmp)
{
  int		i;
  int		j;

  i = 0;
  if (data->map == NULL)
    {
      if ((data->map = malloc(sizeof(char) * (strlen(tmp) + 1))) == NULL)
	return (print_error(ERROR_MALLOC));
      while (i < (int)strlen(tmp))
	{
	  data->map[i] = tmp[i];
	  i++;
	}
      data->map[i] = '\0';
    }
  else
    {
      j = strlen(data->map);
      if ((data->map = realloc(data->map, sizeof(char) * (strlen(data->map) + strlen(tmp) + 1))) == NULL)
	return (print_error(ERROR_REALLOC));
      while (i < (int)strlen(tmp))
	data->map[j++] = tmp[i++];
      data->map[j] = '\0';
    }
  return (OK);
}

static int	parsing_map(t_data *data)
{
  int		nb_line;
  int		nb_col;
  char		*tmp;
  int		fd;

  nb_col = 0;
  nb_line = 0;
  if ((fd = open(data->path_map, O_RDONLY)) == ERROR)
    return (print_error(ERROR_OPEN));
  while ((tmp = get_next_line(fd)))
    {
      if (strlen(tmp) > 0 && nb_col == 0)
	nb_col = strlen(tmp);
      if (nb_col > 0 && nb_col != (int)strlen(tmp))
        return (print_error(ERROR_MAP_SIZE));
      if (map_line(data, tmp) == ERROR)
	return (ERROR);
      nb_line++;
      free(tmp);
    }
  data->map_x = nb_col;
  data->map_y = nb_line;
  if (check_map(data) == ERROR)
    return (ERROR);
  return (OK);
}

int	parsing_serv(int ac, char *av[], t_data *data)
{
  int	key;
  int	i;

  i = 1;
  key = 0;
  while (i != ac)
    {
      if (!strcmp(av[i], "-p") && (data->port = atoi(av[i + 1])) != 0
	  && (key % 10) == 0)
	key += 1;
      else if (!strcmp(av[i], "-g") && (data->gravity = atof(av[i + 1])) != 0
	       && (key / 10 % 10) == 0)
	key += 10;
      else if (!strcmp(av[i], "-m") && (data->path_map = av[i + 1])
	       && (key / 100 % 10) == 0)
	key += 100;
      else
	return (print_error(ERROR_PARSING));
      i += 2;
    }
  if (key != 111 || ac != 7)
    return (print_error(ERROR_PARSING));
  if (parsing_map(data) == ERROR)
    return (print_error(ERROR_MAP));
  return (OK);
}
