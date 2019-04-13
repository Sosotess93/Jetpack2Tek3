/*
** client.h for  in /home/sofiane/Musique/client/include
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:01:56 2017 sofiane
** Last update Tue Jul 18 04:01:57 2017 sofiane
*/

#ifndef CLIENT_H_

# define CLIENT_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_thread.h>

# define INVALIDARG ("Erreur : Les arguments sont invalides.\n")
# define ERRORMSG ("Erreur ! \n")
# define MAPERROR ("Erreur : La map est invalide.\n")
# define ADJUST_Y(ymax, y) (ymax - y)


typedef struct sockaddr* sock;

typedef	struct	s_server
{
  struct protoent	*prot;
  int			server_fd;
  struct sockaddr_in	sock_in;
}		t_server;

typedef struct		s_game
{
  pthread_mutex_t	display_mutex;
  pthread_t		display;
  int			s_fd;
  int			id;
  float			x;
  float			y;
  int			score;
  char			jetpack;
  char			is_dead;
  int			socket;
  char			game_started;
  char			game_over;
  float			other_x;
  float			other_y;
  int			other_score;
  char			*map;
  int			map_w;
  int			map_h;
  int			finish;
  SDL_Surface		*screen;
  SDL_Surface		*background;
  SDL_Surface		*coin;
  SDL_Surface		*bloc;
  SDL_Surface		*player;
  SDL_Surface		*player2;
  SDL_Rect		backpos;
  SDL_Rect		coinpos;
  SDL_Rect		blocpos;
  SDL_Rect		playerpos;
  SDL_Rect		player2pos;
  char			**map_d;
}			t_game;

typedef struct	s_com
{
  char		*command;
  void		(*func)(t_game *info, int socket, char **cmd);

}		t_com;

#endif /* !CLIENT_H_ */
