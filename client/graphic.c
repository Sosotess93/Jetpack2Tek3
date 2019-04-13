/*
** graphic.c for  in /home/sofiane/Musique/client/sources/graph
**
** Made by sofiane
** Login   <sofiane@epitech.net>
**
** Started on  Tue Jul 18 04:30:08 2017 sofiane
** Last update Wed Jul 19 16:45:44 2017 sofiane
*/

#include "prototypes.h"

static void	init_graphique(t_game **item) //init_graphique()
{
  t_game	*player;

  player = *item;
  player->finish = 0;

  player->backpos.x = 0;
  player->backpos.y = 0;

  player->coinpos.x = 0;
  player->coinpos.y = 0;

  player->blocpos.x = 0;
  player->blocpos.y = 0;

  player->playerpos.x = 0;
  player->playerpos.y = 180;

  /* player->player2pos.x = 0; */
  /* player->player2pos.y = 0; */

  if (!(player->background = IMG_Load("assets/fond.jpg")))
    exit(0);
  if (!(player->coin = IMG_Load("assets/coin.png")))
    exit(0);
  if (!(player->bloc = IMG_Load("assets/bloc3.png")))
    exit(0);
  if (!(player->player = IMG_Load("assets/gotenks.gif")))
    exit(0);
  if (!(player->player2 = IMG_Load("assets/buu.png")))
    exit(0);
}

static void	refresh(t_game *player)
{
  player->finish = 0;

  player->backpos.x = 0;
  player->backpos.y = 0;

  player->coinpos.x = 0;
  player->coinpos.y = 0;

  player->blocpos.x = 0;
  player->blocpos.y = 0;

  player->playerpos.x = player->x * 24;
  player->playerpos.y = (int)(ADJUST_Y(player->map_h, player->y));

  player->player2pos.x = player->other_x * 24;
  player->player2pos.y = (int)(ADJUST_Y(player->map_h, player->other_y));
}

static void	draw_map(t_game *player) // OK draw_map()
{
  int		x;
  int		y;

  x = -1;
  SDL_BlitSurface(player->background, NULL, player->screen, &player->backpos);
  while (player->map_d[++x] != NULL)
    {
      y = -1;
      while (player->map_d[x][++y] != '\0')
	{
	  if (player->map_d[x][y] == 'c')
	    SDL_BlitSurface(player->coin, NULL, player->screen, &player->coinpos);
	  else if (player->map_d[x][y] == 'e')
	    SDL_BlitSurface(player->bloc, NULL, player->screen, &player->blocpos);
	  player->coinpos.x = player->coinpos.x + 25;
	  player->blocpos.x = player->blocpos.x + 25;
	}
      player->coinpos.x = 0;
      player->coinpos.y = player->coinpos.y + 24;
      player->blocpos.x = 0;
      player->blocpos.y = player->blocpos.y + 24;
    }
  SDL_Flip(player->screen);
}

int	check_event(SDL_Event *event, t_game *player)
{

  if (event->key.keysym.sym == SDLK_SPACE)
      fire(player);
  else if (event->key.keysym.sym == SDLK_ESCAPE)
    {
      close(player->s_fd);
      exit(0);
    }
  return (0);
}

static void	reload(t_game **player) //OK reload()
{
  SDL_Event	event;

  printf("MAP_W -> %d\n", (*player)->map_w);
  printf("MAP_H -> %d\n", (*player)->map_h);
  printf("POS EN X -> %f\n", (*player)->x);
  printf("PLY EN X -> %f\n", (float)(*player)->playerpos.x);
  printf("POS EN Y -> %f\n", (*player)->y);
  printf("PLY EN Y -> %f\n", (float)(*player)->playerpos.y);
  while (1)
    {
      draw_map(*player);
           refresh(*player);
      (*player)->playerpos.x = (*player)->x * 68;
      //(*player)->playerpos.y = /* (*player)->map_w -  */(*player)->y;
      (*player)->playerpos.y = 220 - ((*player)->player->w - (*player)->y);


      /* printf("POS EN X -> %f\n", (*player)->x); */
      /* printf("PLY EN X -> %f\n", (float)(*player)->playerpos.x); */
      /* printf("POS EN Y -> %f\n", (*player)->y); */
      /* printf("PLY EN Y -> %f\n", (float)(*player)->playerpos.y); */

      /* printf("OTHER EN X -> %f\n", (float)(*player)->other_x); */
      /* printf("OTHER EN Y -> %f\n", (float)(*player)->other_y); */


      /* (*player)->player2pos.x = (float)(*player)->other_x * 68; */
      /* (*player)->player2pos.y = (float)(*player)->other_y * 5; */

      /* (*player)->player2pos.x = (*player)->other_x * 68; */
      /* (*player)->player2pos.y = (*player)->map_h * 10; */

      SDL_BlitSurface((*player)->player, NULL, (*player)->screen, &(*player)->playerpos);
      //      SDL_BlitSurface((*player)->player2, NULL, (*player)->screen, &(*player)->player2pos);
      SDL_Flip((*player)->screen);
      while (SDL_PollEvent(&event))
	{
	  switch(event.type)
	    {
	    case SDL_KEYDOWN:
	      check_event(&event, *player);
	      break;
	    case SDL_QUIT:
	      exit(0);
	    case SDLK_ESCAPE:
	      exit(0);
	      break;
	    }
	}
    }
}




static t_game	*load_assets(t_game **player) //OK load_assets()
{
  int		i;
  int		x;
  int		y;
  int		count;

  i = 0;
  x = -1;
  y = 0;
  count = 0;
  //printf("MAP:\n%s\n", (*player)->map);
  if (!((*player)->map_d = malloc(sizeof(char *) * (strlen((*player)->map + 1)))))
    exit(0);
  while ((*player)->map[i] != '\0')
    {
      if (!((*player)->map_d[++x] = malloc(sizeof(char) * (strlen((*player)->map + 1)))))
	exit(0);
      while (count++ < (*player)->map_w)
	(*player)->map_d[x][y++] = (*player)->map[i++];
      (*player)->map_d[x][y] = '\0';
      count = 0;
      y = 0;
    }
  (*player)->map_d[x] = NULL;
  return (*player);
}

void		*map_charge(void *inf)
{
  t_game	*player;

  player = (t_game *)inf;

  init_graphique(&player);

  player->screen = SDL_SetVideoMode(1850, 220, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("- JetPack2Tek3 -", NULL);

  player = load_assets(&player);
  SDL_Init(SDL_INIT_VIDEO);
  while (player->finish != 1)
    {
      reload(&player);
      printf("FINISH : %d\n", player->finish);
    }
  SDL_Quit();
  return (NULL);
}
