/*
** socket.h for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Thu Jul 13 18:33:10 2017 Arthur Malaise
** Last update Fri Jul 14 10:42:09 2017 Arthur Malaise
*/

#ifndef SOCKET_H_
# define SOCKET_H_

# include <sys/socket.h>
# include <sys/select.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <string.h>
# include <netdb.h>
# include <fcntl.h>
# include <stdio.h>

# define ERROR_SOCKET "Error : socket()\n"
# define ERROR_CONNECT "Error : connect()\n"
# define ERROR_BIND "Error : bind()\n"
# define ERROR_LISTEN "Error : listen()\n"
# define ERROR_SELECT "Error : select()\n"

# define OK 0
# define ERROR -1

# define BLOCK 0
# define NON_BLOCK 1

typedef int                     SOCKET;
typedef struct sockaddr_in      SOCKADDR_IN;
typedef struct sockaddr         SOCKADDR;
typedef struct timeval		t_timeval;
typedef struct protoent		t_proto;

int	sock_connect(char const *, int const, char const *);
int	sock_listen(int const, int const, char const *);
int	sock_accept(SOCKET);
int	sock_send(SOCKET, char const *);
int	sock_recv(SOCKET, char *, size_t, int const);

#endif /* !SOCKET_H_ */
