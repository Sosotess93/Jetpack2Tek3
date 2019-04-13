/*
** wordtab.h for  in /home/charra_s/Minishell1
** 
** Made by Sofiane Charrad
** Login   <charra_s@epitech.net>
** 
** Started on  Tue Feb 24 13:42:18 2015 Sofiane Charrad
** Last update Tue Feb 24 16:28:26 2015 Sofiane Charrad
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


#ifndef _WORDTAB_H_
# define _WORDTAB_H_

typedef	struct	s_init
{
  int		a;
  int		b;
  int		c;
}		t_init;

typedef	struct	s_var
{
  char		**arg;
  char		buff[4096];
  int		fe;
}		t_var;

#endif /* !WORDTAB_H_ */
