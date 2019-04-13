/*
1;2802;0c** prototypes.h for  in /home/sofiane/Musique/client/include
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 03:48:49 2017 sofiane
** Last update Wed Jul 19 06:54:10 2017 sofiane
*/

#ifndef	PROTOTYPES_H_
# define PROTOTYPES_H_

# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 800
# define SCREEN_BPP 32
# define BLOCK_SIZE 20
# define GROUND 0x171B99
# define PLAYER1 0xDD2D2D
# define PLAYER2 0x2DBDFC
# define COIN 0xEBF218
# define TRAP 0x32F218
# define TRUE 0
# define FALSE 1



#include "client.h"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/time.h>
#include <pthread.h>
#include <ctype.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_thread.h>


/* INIT */
void	init(t_game *player, int socket);
void	ptr_init(t_com *cmd, char *name, void (*func)(t_game*, int, char**));
void	cmd_init();
void	my_client(t_game *, int socket, char **cmd);


/* COMMANDS */
int	my_id(int socket, t_game *player);
int	my_map(int socket, t_game *player);
void	fire(t_game *player);

/* COMMON */
/* int	args_checks(int ac, char **av); */
 int	size_of_tab(char **t);
void	lines_count(t_game *player, char **l);
char	*my_malloc(int nb);
void	free_my_tab(char **tab);
int	word_count(char *str, char sep);
char	*my_parser(char *str, int *i, char sep);
char	**my_str_to_wordtab(char *str, char sep);
void	fd_write(int fd, char *str, char c);

/* GAME */
void	coins(t_game *player, int socket, char **cmd);
void	lunch_game(t_game *player, int socket, char **cmd);
void	game_finish(t_game *player, int socket, char **cmd);
void	*loops(void *data, int socket);
int	ready_for_play(int socket);

/* GRAPHIQUE */
/* static  void	init_graphique(t_game **play); */
/* static  void	draw_map(t_game *player); */
/* static  void	reload(t_game *player); */
/* static  t_game *load_assets(t_game *player); */
void		*map_charge(void *inf);

/* PLAYER */
void	my_player(t_game *player, int socket, char **cmd);

/* SOCKET */
void	my_client_connect(int ac, char **av, t_server *server);
int	my_connexion(int ac, char **av);

#endif /* !PROTOTYPES_H_ */
