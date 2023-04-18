#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "text.h"


typedef struct image
{
	SDL_Surface *img;	
	SDL_Rect pos;
}image;


void init_start1(image *start1);
void init_start2(image *start2);
void init_setting1(image *setting1);
void init_setting2(image *setting2);
void init_exit1(image *exit1);
void init_exit2(image *exit2);
void init_backk(image *back);
void init_score(image *back);
void liberer(image *p);
void afficher(image p ,SDL_Surface *ecran);
void init_start(image *back);
void init_option(image *back);
void init_anim(image menu[],char anim[]);
void afficher_animation(image menu[],SDL_Surface *screen,int i);
void init_full1(image *back);
void init_full2(image *back);
void init_son(image *back);
void init_plus(image *back);
void init_plus1(image *back);
void init_moin(image *back);
void init_moin1(image *back);
void startt(SDL_Surface *ecran);
void optionn(SDL_Surface *ecran);
void score(SDL_Surface *ecran);
