#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

void initBackground(Background *B)
{
	
	B->PositionBg.x=0;
	B->PositionBg.y=0;
	B->camera.x=0;
	B->camera.y=200;
	B->camera.w = 1200;
	B->camera.h = 600;
	B->BgImg= IMG_Load("backg.jpg");
	B->vol = 1;
	
	
	int i;
	char ch[20];
	for(i=0;i<12;i++)
	{
		sprintf(ch,"%d.jpg",i);
		B->anima[i] = IMG_Load(ch);
	}

	if(SDL_Init(SDL_INIT_AUDIO)==-1)
	{
		printf("SDL_Init: %s\n", SDL_GetError());
	}
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
	}
	B->music=Mix_LoadMUS("musique.mp3");
	Mix_PlayMusic(B->music, -1);
	Mix_AllocateChannels(10);
	Mix_VolumeMusic(B->vol);

}

void afficherBack (Background B,SDL_Surface *screen)
{
	SDL_BlitSurface(B.BgImg,&(B.camera),screen,&(B.PositionBg));
	SDL_BlitSurface(B.anima[B.anim],&B.camera,screen,&(B.PositionBg));
}

void animation(Background *B, SDL_Surface * screen) 
{
	B->anim++;
	if(B->anim==12) 
	{
		B->anim=0;
	}
	SDL_Delay(200);

}

void getinput(input *in, int run)
{
	run =1;
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{	case SDL_QUIT:
		run =0;
                exit(0);
           	 break;
		case SDL_KEYDOWN:
		switch(event.key.keysym.sym)
		{
			case SDLK_ESCAPE: 
			run =0;
                        exit(0);
                    	break;
                    	case SDLK_UP:
			in->up=1;
			break;
			case SDLK_DOWN:
			in->down=1;
			break;
			case SDLK_LEFT:
			in->left=1;
			break;
			case SDLK_RIGHT:
			in->right=1;
			break;
			default:
			break;
									
		}
		break;
		case SDL_KEYUP:
		switch(event.key.keysym.sym)
		{
			case SDLK_LEFT:
			in->left=0;
			break;
			case SDLK_UP:
			in->up=0;
			break;
			case SDLK_DOWN:
			in->down=0;
			break;
			case SDLK_RIGHT:
			in->right=0;
			break;
			default:
			break;						
		}
		break;
	}
}

void scrolling(Background *B, input *in)
{
	if(in->right==1)
	{
		B->vol++;
		B->camera.x+=20;
		if(B->camera.x >=8800)
		{
			B->camera.x=8800;
		}
	}
	else if(in->left==1)
	{
		B->camera.x-=20;
		if (B->camera.x<= 0) 
		{
			B->camera.x=0;
		}
	}
	if(in->up==1)
	{	B->camera.y-=20;
		if (B-> camera.y <= 0)
		{
			B->camera.y=0;
		}
	}
	else if(in->down==1)
	{
		B->camera.y+=20;
		if (B-> camera.y >= 200)
		{
			B->camera.y=200;
		}
	}
}

void save_score(int score) 
{
    FILE *fptr;
    int i, j;
    int scores[3];

    fptr = fopen("scores.txt", "r");

    if (fptr != NULL) 
    {
        for (i = 0; i < 3; i++) 
        {
            if (fscanf(fptr, "%d", &scores[i]) != 1) 
            {
                scores[i] = 0;
            }
        }
        fclose(fptr);
    }

    scores[3-1] = score;

    for (i = 0; i < 3-1; i++) 
    {
        for (j = i+1; j < 3; j++) 
        {
            if (scores[j] > scores[i]) 
            {
                int temp = scores[j];
                scores[j] = scores[i];
                scores[i] = temp;
            }
        }
    }

    fptr = fopen("scores.txt", "w");
    if (fptr != NULL) 
    {
        for (i = 0; i < 3; i++) 
        {
            fprintf(fptr, "%d\n", scores[i]);
        }
        fclose(fptr);
    }
}

void ajouter_meilleur_score(int a) 
{
   FILE *fichier = fopen("Meilleurs Scores.txt", "a");

   if (fichier != NULL) 
   {
      fprintf(fichier, "%d\n", a); 
      fclose(fichier); 
   } 
   else 
   {
      printf("Erreur lors de l'ouverture du fichier.\n");
   }
}

int obtenir_max_fichier() 
{
   FILE *fichier = fopen("Meilleurs Scores.txt", "r"); 
   if (fichier == NULL) 
   {
      printf("Erreur lors de l'ouverture du fichier.\n");
      exit(1); 
   }

   int max = 0;

   int valeur_actuelle;
   while (fscanf(fichier, "%d", &valeur_actuelle) == 1) 
   {
      if (valeur_actuelle > max) 
      {
         max = valeur_actuelle;
      }
   }

   fclose(fichier);

   return max;
}

void freeBackground(Background *B)
{
	SDL_FreeSurface(B->BgImg);
	Mix_FreeMusic (B->music);
}
