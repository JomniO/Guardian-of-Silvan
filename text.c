#include "text.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


void initText(text *A)
{
	A->position.x=0;
	A->position.y=0;

	A->textColor.r=255;
	A->textColor.g=255;
	A->textColor.b=0;

	A->font=TTF_OpenFont("text.ttf",30);
}
void freeText(text A)
{
	SDL_FreeSurface(A.surfaceText);
}
void displayText(text t,SDL_Surface *screen,int a)
{
	char ch[10];
	char ch2[100];
	strcpy(ch2,"score: ");

	sprintf(ch, "%d", a);
	strcat(ch2,ch);
	t.surfaceText=TTF_RenderText_Solid(t.font,ch2,t.textColor);
	SDL_BlitSurface(t.surfaceText,NULL,screen,&t.position);
}
void joueur1(text t,SDL_Surface *screen)
{
	t.surfaceText=TTF_RenderText_Solid(t.font,"joueur1:",t.textColor);
	SDL_BlitSurface(t.surfaceText,NULL,screen,&t.position);
}

