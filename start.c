#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include"background.h"
#include "text.h"

void startt(SDL_Surface *ecran)
{
	Background B, Back [20];
	char ch[10];
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen=NULL;
	TTF_Init();
	text t;
	screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode: %s /n",SDL_GetError());
	}
	int running =1;
	input in;
	initBackground(&B);
	initText(&t);
	int a=0;
	
	while (running)
	{	 
		animation(&B,screen);
		afficherBack (B,screen);
		getinput(&in,running);
		scrolling(&B,&in);
		if (in.right==1)
		{
			a++;
			B.vol++;
			Mix_VolumeMusic(B.vol);
		}
		ajouter_meilleur_score(a);
		displayText(t,screen,a);
		B.meilleure=obtenir_max_fichier();
		save_score(B.meilleure);
		SDL_Flip(screen);
	}
	
}









