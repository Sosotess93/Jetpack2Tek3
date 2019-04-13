/*
** my_str_to_wordtab.c for  in /home/sofiane/Bureau/jetpack2Tek3/client/src1
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Wed Jul 13 09:54:32 2016 sofiane
** Last update Wed Jul 13 09:59:54 2016 sofiane
*/

#include <stdlib.h>
#include <stdio.h>


int	word_count(char *str, char sep)
{
  int	i;
  int	ctr;

  i = 0;
  ctr = 0;
  while (str[i] != '\0')
    {
      if ((i == 0 && str[i] != sep) ||
	  (str[i] == sep && str[i + 1] != sep && str[i + 1] != '\0'))
	ctr++;
      i++;
    }
  return (ctr);
}


char            *my_parser(char *str, int *i, char sep)
{
  int           ctr1;
  int           ctr2;
  char          *result;

  ctr2 = 0;
  while (str[*i] == sep)
    (*i)++;
  ctr1 = (*i);
  while(str[ctr1] != sep && str[ctr1] != '\0')
    ctr1++;
  if ((result = malloc((ctr1 - (*i)) + 1)) == NULL)
    return (NULL);
  while ((*i) != ctr1)
    result[ctr2++] = str[(*i)++];
  result[ctr2] = '\0';
  while (str[*i] == sep)
    (*i)++;
  return (result);
}

char		**my_str_to_wordtab(char *str, char sep)
{
  char		**tab;
  int		wordcount;
  int		i;
  int		s;

  i = 0;
  s = 0;
  wordcount = word_count(str, sep);
  if ((tab = malloc(sizeof(char *) * (wordcount + 1))) == NULL)
    return (NULL);
  tab[wordcount] = '\0';
  while (i != wordcount)
    {
      tab[i] = my_parser(str, &s, sep);
      i++;
    }
  return (tab);
}
