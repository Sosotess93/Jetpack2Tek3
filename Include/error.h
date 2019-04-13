/*
** error.h for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack/Include
** 
** Made by Arthur Malaise
** Login   <malais_b@epitech.net>
** 
** Started on  Thu Jul 13 15:15:26 2017 Arthur Malaise
** Last update Sat Jul 15 14:04:52 2017 Arthur Malaise
*/

#ifndef ERROR_H_
# define ERROR_H_

# define ERROR_PROTO "Error : getprotobyname()\nFailed to connect to protocol database\n"
# define ERROR_SOCKET "Error : socket()\n"
# define ERROR_BIND "Error : bind()\n"
# define ERROR_LISTEN "Error : listen()\n"
# define ERROR_OPEN "Error : open()\n"
# define ERROR_MALLOC "Error : malloc()\n"
# define ERROR_REALLOC "Error : realloc()\n"

# define ERROR_PARSING "Error : Invalid arguments()\nUsage : ./serverJ2T3 -p <port> -g <gravity> -m <map>\n"
# define ERROR_MAP "Error : Invalid map\n"
# define ERROR_MAP_SIZE "Error : Invalid map size\n"

#endif /* !ERROR_H_ */
