#ifndef Texte_h
#define Texte_h
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
typedef struct Text{
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char texte [50];
} Text;

void initTexte(Text *t);
void freeTexte(Text A);
void displayTexte(Text t,SDL_Surface *screen);

#endif
