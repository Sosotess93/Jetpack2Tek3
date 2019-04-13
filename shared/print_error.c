/*
** print_error.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/shared
**
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
**
** Started on  Thu Jul 13 15:19:54 2017 Arthur Malaise
** Last update Wed Jul 19 11:15:08 2017 sofiane
*/

#include "print_error.h"

int	print_error(char *err)
{
  fprintf(stderr, "%s", err);
  return (ERROR);
}
