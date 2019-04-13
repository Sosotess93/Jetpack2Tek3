/*
** socket.c for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/server
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Thu Jul 13 17:36:20 2017 Arthur Malaise
** Last update Fri Jul 14 14:56:05 2017 Arthur Malaise
*/

#include "socket.h"

int		sock_connect(char const *ip, int const port, char const *prototype)
{
  t_proto	*proto;
  SOCKET	sock;
  SOCKADDR_IN	sin;

  if ((proto = getprotobyname(prototype)) == OK
      || (sock = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == ERROR)
    {
      fprintf(stderr, ERROR_SOCKET);
      return (ERROR);
    }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(ip);
  if (connect(sock, (SOCKADDR *)&sin, sizeof(sin)) == ERROR)
    {
      close(sock);
      fprintf(stderr, ERROR_CONNECT);
      return (ERROR);
    }
  return (sock);
}

int		sock_listen(int const port, int const max, char const *prototype)
{
  t_proto	*proto;
  SOCKET	sock;
  SOCKADDR_IN	sin;

  if ((proto = getprotobyname(prototype)) == OK
      || (sock = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == ERROR)
    {
      fprintf(stderr, ERROR_SOCKET);
      return (ERROR);
    }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(sock, (SOCKADDR *)&sin, sizeof(sin)) == ERROR)
    {
      close(sock);
      fprintf(stderr, ERROR_BIND);
      return (ERROR);
    }
  if (listen(sock, max) != ERROR)
    return (sock);
  close(sock);
  fprintf(stderr, ERROR_LISTEN);
  return (ERROR);
}

int		sock_accept(SOCKET sock)
{
  fd_set	readfds;
  SOCKADDR_IN	sin;
  int		len;
  t_timeval	tv;

  FD_ZERO(&readfds);
  FD_SET(sock, &readfds);
  tv.tv_sec = 0;
  tv.tv_usec = 10;
  len = sizeof(sin);
  if (select(sock + 1, &readfds, 0, 0, &tv) == ERROR)
    {
      fprintf(stderr, ERROR_SELECT);      
      return (ERROR);
    }
  if (FD_ISSET(sock, &readfds))
    return (accept(sock, (SOCKADDR *)&sin, (socklen_t *)&len));
  return (ERROR);
}

int	sock_send(SOCKET sock, char const *buff)
{
  return (send(sock, buff, strlen(buff), 0) >= 0);
}

int	sock_recv(SOCKET sock, char *buff, size_t size, int const block)
{
  int	len;

  memset(buff, 0, size);
  if ((len = recv(sock, (void *)buff, size - 1,
		  (block == BLOCK ? 0 : MSG_DONTWAIT))) <= 0)
    return (ERROR);
  buff[len] = 0;
  return (OK);
}
