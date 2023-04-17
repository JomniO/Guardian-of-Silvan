#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"menu.h"
void optionn(SDL_Surface *ecran)
{
image p,son,full1,full2,plus,plus1,moin,moin1;
int i,continuer=1,taper=0,s=0,curseur,vol =0;
SDL_Event event;
init_option(&p);
init_full1(&full1);
init_full2(&full2);
init_son(&son);
init_plus(&plus);
init_plus1(&plus1);
init_moin(&moin);
init_moin1(&moin1);
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    // API Mixer Initialization
    {
        printf("%s", Mix_GetError());
    }
    Mix_Chunk *clickmusic;
    Mix_Music *music;             // Construct Mix_Music pointer
    music = Mix_LoadMUS("music.mp3"); // load the music
    Mix_PlayMusic(music, -1);     // play music
    clickmusic=Mix_LoadWAV("son.wav");
    Mix_VolumeMusic(vol);
while(continuer)
{
afficher(p,ecran);
afficher(son,ecran);
afficher(full1,ecran);
afficher(plus1,ecran);
afficher(moin1,ecran);
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
				case SDLK_f:
	    				SDL_WM_ToggleFullScreen(ecran);
	    			break;
			}
			break;
			case SDL_MOUSEMOTION:
			    if (event.motion.x >= 525 && event.motion.x <= 676 && event.motion.y >= 265 && event.motion.y <= 332)
			    {
				curseur=1;
			    }
			    else if (event.motion.x >= 737 && event.motion.x <= 770 && event.motion.y >= 350 && event.motion.y <= 383)
			    {
				curseur=2;
			    }
			    else if (event.motion.x >= 450 && event.motion.x <= 483 && event.motion.y >= 365 && event.motion.y <= 398)
			    {
				curseur=3;
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
					if(SDL_WM_ToggleFullScreen(ecran))
					{
						afficher(full2,ecran);
					}
				 break;
				case 2:
					if(vol<99) vol=vol+33;
					Mix_VolumeMusic(vol);
					afficher(plus,ecran);
				 break;
				case 3:
					if(vol>0) vol=vol-33;
					Mix_VolumeMusic(vol);
					afficher(moin,ecran);
				 break;
				}
			    }
			break;
		}
		
		/*if (i==1)
		{

		afficher(full,ecran);
		}
		if (i==2)
		{

		afficher(setting2,screen);
		Mix_PlayChannel(1,clickmusic,0);
		}
		if(i==3)
		{
		afficher(exit2,screen);
		Mix_PlayChannel(1,clickmusic,0);
		}*/
		SDL_Flip(ecran);
}


SDL_Flip(ecran);
}

}


