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

void initTxt(Text *t);
void initTitle(Text *t);
void freeTxt(Text A);
char* lire_fichier(char* nom_fichier);
void displayTxt(Text t,SDL_Surface *screen);
void displayTitle(Text t,SDL_Surface *screen);

#endif
