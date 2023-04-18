#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include "menu.h"
#include "scoreTxt.h"

void score(SDL_Surface *ecran)
{
image s;
TTF_Init();
int i,ev =0,continuer=1,curseur;
init_start(&s);
SDL_Event event;
image single1,multi1,single,multi,back,backg;
Text a,a1;
initTxt(&a);
initTitle(&a1);
init_backk(&back);


while(continuer)
{
	afficher(s,ecran);
	afficher(back,ecran);
	displayTxt(a,ecran);
	displayTitle(a1,ecran);
	while(SDL_PollEvent(&event))
	{
			switch (event.type)
			{
				case SDL_KEYDOWN:
			    	switch (event.key.keysym.sym)
			    	{
			    		case SDLK_ESCAPE:
						continuer = 0;
					break;
				}
				break;
				case SDL_MOUSEMOTION:
				    if (event.motion.x >= 10 && event.motion.x <= 90 && event.motion.y >= 10 && event.motion.y <= 90)
				    {
					curseur=1;
				    }
				break;
				case SDL_QUIT:
			    			continuer = 0;
			    	break;
				
				case SDL_MOUSEBUTTONDOWN:
				    if (event.button.button == SDL_BUTTON_LEFT)
				    {
					switch (curseur)
					{
					 case 1:
							continuer = 0;
					 break;
					}
				    }
				break;
			}

		SDL_Flip(ecran);	
	}
		
}
TTF_CloseFont(a.font);
TTF_Quit();
}









