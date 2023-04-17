#ifndef text_H
#define texte_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface  * surfaceText;
	SDL_Color textColor;
	char texte[20];
}text;

void initText(text *t);
void freeText(text A);
void displayText(text t,SDL_Surface *screen,int a);
void joueur1(text t,SDL_Surface *screen);

#endif
