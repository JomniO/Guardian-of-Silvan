#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
	SDL_Surface *BgImg; 
	SDL_Rect PositionBg;
	SDL_Rect camera;
	Mix_Music *music; 
	int anim;
	SDL_Surface *anima[50]; 
	SDL_Rect posanim ;
	int vol;
	int meilleure;
}Background;

typedef struct 
{
	int left,right,up,down;
}input;


void initBackground(Background *B);
void afficherBack(Background B, SDL_Surface * screen);
void animation (Background *B,SDL_Surface * screen) ;
void getinput(input *in,int run);
void scrolling(Background *B, input *in);
void freeBackground(Background *B);
void ajouter_meilleur_score(int a);
int obtenir_max_fichier();
void save_score(int score);

#endif
