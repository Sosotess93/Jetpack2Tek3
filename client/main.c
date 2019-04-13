/*
** main.c for  in /home/sofiane/Musique/client
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 05:20:59 2017 sofiane
** Last update Tue Jul 18 13:03:54 2017 sofiane
*/

#include "prototypes.h"

int	check_args(int ac, char **av)
{
  int	i;

  i = 0;
  while (i != ac)
    {
      if ((strncmp("-h", av[i], strlen("-h")) == 0) &&
	  (((i + 1) == ac ) ||
	   (strncmp("-p", av[i + 1], strlen("-p")) == 0)))
	return (1);
      i++;
    }
  return (0);
}


int	main(int ac, char **av)
{
  if (ac == 5)
    {
      if (check_args(ac, av))
	{
	  fprintf(stderr, "%s", INVALIDARG);
	  return (1);
	}
      if (my_connexion(ac, av) == 1)
        {
	  fprintf(stderr, "%s", ERRORMSG);
	  return (1);
	}
      return (0);
    }
  pthread_exit(NULL);
  fprintf(stderr, "%s", INVALIDARG);
  return (1);
}
