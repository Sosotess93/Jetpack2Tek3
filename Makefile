##
## Makefile for jetpack2tek3 in /home/malais_b/rendu/TEK2_re/Piscine_synthese/jetpack
## 
## Made by Arthur Malaise
## Login   <malais_b@epitech.net>
## 
## Started on  Thu Jul 13 11:44:42 2017 Arthur Malaise
## Last update Tue Jul 25 17:22:15 2017 sofiane
##

CC		= gcc -g3

RM		= rm -f

NAME_SERV	= serverJ2T3
NAME_CLIENT	= clientJ2T3

SRCS_CLIENT	= client/main.c \
		client/init.c \
		client/my_id.c \
		client/my_map.c \
		client/fire.c \
		client/common.c \
		client/my_str_to_wordtab.c \
		client/write.c \
		client/coins.c \
		client/game.c \
		client/loops.c \
		client/graphic.c \
		client/player.c \
		client/connect.c \


SRCS_SERV	= server/server.c \
		server/serv_init.c \
		server/parsing_serv.c \
		server/find_cli.c \
		server/game.c \
		server/position.c \
		server/collision.c \
		server/hit_box.c \
		server/end.c \
		server/close.c


SRCS_SHARED	= shared/print_error.c \
		shared/socket.c \
		shared/get_next_line.c

CFLAGS		+= -I./Include
CFLAGS		+= -W -Wall -Wextra
SDL_FLAGS	= -lpthread -lSDL -lSDLmain -lSDL_image -lSDL_ttf

OBJS_SERV	= $(SRCS_SERV:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)
OBJS_SHARED	= $(SRCS_SHARED:.c=.o)

all: client server

server: $(NAME_SERV)

client: $(NAME_CLIENT)

$(NAME_SERV): $(OBJS_SERV) $(OBJS_SHARED)
	$(CC) -o $(NAME_SERV) $(OBJS_SERV) $(OBJS_SHARED) $(CFLAGS)

$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS_SHARED)
	$(CC) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(OBJS_SHARED) $(CFLAGS) $(SDL_FLAGS)

clean:
	$(RM) $(OBJS_SERV)
	$(RM) $(OBJS_CLIENT)
	$(RM) $(OBJS_SHARED)

clean_server:
	$(RM) $(OBJS_SERV)

clean_client:
	$(RM) $(OBJS_CLIENT)

clean_shared:
	$(RM) $(OBJS_SHARED)

fclean: clean
	$(RM) $(NAME_SERV)
	$(RM) $(NAME_CLIENT)

fclean_server: clean_server
	$(RM) $(NAME_SERV)

fclean_client: clean_client
	$(RM) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean clean_server clean_client fclean fclean_server fclean_client re 
