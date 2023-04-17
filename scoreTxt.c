#include <SDL/SDL.h>
#include "scoreTxt.h"
#include <SDL/SDL_image.h>

void initTxt (Text *A)
{
	A->position.x=475;
	A->position.y=150;
	//
	A->textColor.r=215;
	A->textColor.g=190;
	A->textColor.b=105;
	A->font = TTF_OpenFont( "Mfont.ttf", 50 );
}
void initTitle (Text *A)
{
	A->position.x=475;
	A->position.y=90;
	//
	A->textColor.r=215;
	A->textColor.g=190;
	A->textColor.b=105;
	A->font = TTF_OpenFont( "Mfont.ttf", 50 );
}
void freeTxt(Text A)
{
	SDL_FreeSurface(A.surfaceTexte);
}


char* lire_fichier(char* nom_fichier) 
{
    FILE* fichier = NULL;
    long taille_fichier;
    char* contenu = NULL;

    fichier = fopen(nom_fichier, "r");

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier);
        exit(1);
    }

    
    fseek(fichier, 0L, SEEK_END);
    taille_fichier = ftell(fichier);
    rewind(fichier);

 
    contenu = (char*)malloc(sizeof(char) * (taille_fichier + 1));

    if (contenu == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(1);
    }

    
    fread(contenu, sizeof(char), taille_fichier, fichier);
    contenu[taille_fichier] = '\0';

   
    fclose(fichier);

    return contenu;
}

void displayTxt (Text t, SDL_Surface *screen)
{
	char *ch = lire_fichier("scores.txt");
	char *txt=("Meilleure Scores : \n %s ", ch);
	t.surfaceTexte = TTF_RenderText_Solid (t.font, txt , t.textColor );
	SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position);
	free(txt);
	
	
	
}
void displayTitle(Text t,SDL_Surface *screen)
{
	t.surfaceTexte = TTF_RenderText_Solid (t.font, "Top Scores", t.textColor );
	SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position);
}



