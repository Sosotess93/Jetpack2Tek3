/*
** common.c for  in /home/sofiane/Musique/client/sources/common
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:43:07 2017 sofiane
** Last update Tue Jul 18 06:12:57 2017 sofiane
*/

#include "prototypes.h"

int	size_of_tab(char **tab) // OK size_of_tab
{
  int	nb;

  nb = 0;
  while (tab[nb])
    ++nb;
  return (nb);
}

char	*my_malloc(int nb) // OK my_malloc
{
  char	*str;

  str = malloc(8 * sizeof(nb));
  sprintf(str, "%d", nb);
  return (str);
}

void	lines_count(t_game *info, char **lines) // OK lines_count
{
  int	i;
  char	**tab;

  i = 0;
  while (lines[i])
    {
      printf("%s\n", lines[i]);
      tab = my_str_to_wordtab(lines[i], ' ');
      my_client(info, info->s_fd, tab); // my_client
      free(tab);
      i++;
    }
}

void	free_my_tab(char **tab) // free_my_tab
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
