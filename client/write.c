/*
** write.c for  in /home/sofiane/Musique/client/sources/common
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:40:38 2017 sofiane
** Last update Tue Jul 18 12:53:39 2017 sofiane
*/

#include "prototypes.h"

void	fd_write(int fd, char *str, char c) //OK fd_write
{
  write(fd, str, strlen(str));
  if (c)
    write(fd, "\n", 1);
}
