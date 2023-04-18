#include <SDL/SDL.h>
#include "texte.h"
#include <SDL/SDL_image.h>

void initTexte (Text *A)
{
	A->position.x=375;
	A->position.y=90;
	//
	A->textColor.r=215;
	A->textColor.g=190;
	A->textColor.b=105;
	A->font = TTF_OpenFont( "Mfont.ttf", 50 );
}
void freeTexte(Text A)
{
	SDL_FreeSurface(A.surfaceTexte);
}
void displayTexte (Text t, SDL_Surface *screen)
{
	t.surfaceTexte = TTF_RenderText_Solid (t.font, "Guardian Of Silvanuis", t.textColor );
	SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position);
}

