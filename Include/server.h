/*
** server.h for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/Include
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Thu Jul 13 11:51:47 2017 Arthur Malaise
** Last update Tue Jul 18 16:24:11 2017 Arthur Malaise
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <netdb.h>

# include "error.h"

/* shared */
# include "get_next_line.h"
# include "print_error.h"
# include "socket.h"

# define OK 0
# define ERROR -1
# define RET_ERR 84

typedef int			SOCKET;
typedef struct sockaddr_in	SOCKADDR_IN;
typedef struct sockaddr		SOCKADDR;
typedef struct in_addr		IN_ADDR;
typedef struct timeval		t_timeval;
typedef struct protoent		t_proto;

# define CLI_UNDECLARED -1
# define CLI_DECLARED 0
# define CLI_READY 1
# define CLI_ALIVE 2
# define CLI_DEAD 3
# define CLI_WIN 4

# define MAX_CLI 255

typedef struct	s_cli
{
  SOCKET	sock;
  float		pos_x;
  float		pos_y;
  int		state;
  int		score;
  float		gravity;
}		t_cli;

typedef struct	s_data
{
  int		port;
  float		gravity;
  char		*path_map;
  int		map_x;
  int		map_y;
  char		*map;
  char		**map_tab;
  t_cli		cli[MAX_CLI];
  t_timeval	tv;
  SOCKET	sock;
  SOCKADDR_IN	sin;
  SOCKADDR_IN	client_sin;
  socklen_t	client_sin_len;
  int		nb_cli;
  int		nb_cli_alive;
}		t_data;

/* serv_init.c */
int	init_serv(t_data *);
int     run_serv(t_data *);

/* parsing_serv.c */
int	parsing_serv(int, char **, t_data *);

/* find_cli.c */
void	find_cli(t_data *);

/* game.c */
int     run_game(t_data *);

/* position.c */
void	send_pos(t_data *);
void    set_pos(t_data *);

/* collision.c */
void	collision(t_data *);

/* hit_box.c */
void	check_coin_hit_box(int, int, int, t_data *);
void	check_elec_hit_box(int, int, int, t_data *);

/* end.c */
void	end(t_data *);

/* close.c */
void	close_game(t_data *);

#endif /* !SERVER_H_ */
