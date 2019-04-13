/*
** get_next_line.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/shared
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Fri Jul 14 17:36:54 2017 Arthur Malaise
** Last update Fri Jul 14 18:43:23 2017 Arthur Malaise
*/

#include "get_next_line.h"

static char	*add_char(char *str, const char c)
{
  char		*new_str;
  int		i;

  i = 0;
  if ((new_str = malloc(sizeof (char) * (strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = c;
  new_str[i + 1] = '\0';
  free(str);
  return (new_str);
}

char	*get_next_line(const int fd)
{
  char	buff;
  char	*str;

  if ((str = malloc(sizeof (char))) == NULL)
    return (NULL);
  str[0] = '\0';
  while (read(fd, &buff, 1) > 0)
    {
      if (buff == '\n' || buff == '\0')
        return (str);
      if ((str = add_char(str, buff)) == NULL)
	{
	  free(str);
	  return (NULL);
	}
    }
  free(str);
  return (NULL);
}
