#include "menu.h"
#include "texte.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Surface *screen = NULL;
    int done = 0, i = 0 ,ev, n=0,g, cursor , curseur;
    char anim[50];
    image backg,start, start1, start2, setting1,setting2,exit1,exit2,score1, menu[50];
    screen=SDL_SetVideoMode(1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
	if(screen==NULL)
	{
	printf("unable to upload img %s",SDL_GetError());
	}
    init_start1(&start1);
    init_start2(&start2);
    init_setting1(&setting1);
    init_setting2(&setting2);
    init_exit1(&exit1);
    init_exit2(&exit2);
    init_anim(menu,anim);
    init_score(&score1);
    Mix_Chunk *clickmusic;
     Text a;
    initTexte(&a);
    SDL_Event event;
    atexit(SDL_Quit);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    
    {
        printf("%s", Mix_GetError());
    }

    Mix_Music *music;             
    music = Mix_LoadMUS("music.mp3"); 
    Mix_PlayMusic(music, -1);    
    clickmusic=Mix_LoadWAV("son.wav");
    
    while (!done)
    {
       
		if (n==40)
		{
		n=1;
		}
		afficher_animation(menu,screen,n);
		n++;
		afficher(start1 ,screen);
		afficher(setting1 ,screen);
		afficher(exit1 ,screen);
		afficher(score1, screen);
		displayTexte(a,screen);
		switch (cursor)
		{
			case 1:
				if(g==1)
				Mix_PlayChannel(-1,clickmusic,0);
				g=0;
				afficher(start2,screen);
			break;
			case 2:
				if(g==1)
				Mix_PlayChannel(-1,clickmusic,0);
				g=0;
				afficher(setting2,screen);
			break;
			case 3:
				if(g==1)
				Mix_PlayChannel(-1,clickmusic,0);
				g=0;
				afficher(exit2,screen);
			break;
		}
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
		    	switch (event.key.keysym.sym)
		    	{
		    		case SDLK_ESCAPE:
		        		done = 1;
		        	break;
				case SDLK_f:
	    				SDL_WM_ToggleFullScreen(screen);
	    			break;
				case SDLK_p:
					startt(screen);
	    			break;
	    			case SDLK_s:
					score(screen);
	    			break;
				case SDLK_UP:
					if (i==1)
						i=3;
					else
						{i--;
						Mix_PlayChannel(1,clickmusic,0);}
				break;
				case SDLK_DOWN:
					if(i==3)
		      				i=1;
					else
		      				 { i++;
		        			Mix_PlayChannel(1,clickmusic,0);}
				break;
				
				case SDLK_RETURN:
					if(i==1)
					{
					startt(screen);
					Mix_PlayChannel(1,clickmusic,0);
					}
					else if (i==2)
					{
                                        optionn(screen);
					Mix_PlayChannel(1,clickmusic,0);
					}
					else if(i==3)
					{
					done=1;
					Mix_PlayChannel(1,clickmusic,0);
					}

				break;
			}
			break;
			case SDL_MOUSEMOTION:
			    if (event.motion.x >= 500 && event.motion.x <= 600)
			    {
				if (event.motion.y >= 150 && event.motion.y <= 250)
				{
					curseur =1;
					cursor=1;
					i=0;
					Mix_PlayChannel(1,clickmusic,0);
				}

				else if (event.motion.y >= 250 && event.motion.y <= 350)
				{
					curseur =2;
					cursor=2;
					i=0;
					Mix_PlayChannel(1,clickmusic,0);
				}

				else if (event.motion.y >= 350 && event.motion.y <= 450)
				{
					curseur =3;
					cursor=3;
					i=0;
					Mix_PlayChannel(1,clickmusic,0);
				}
			    }
			    else if (event.motion.x >= 10 && event.motion.x <= 110 &&  event.motion.y >= 10 && event.motion.y <= 110)
			    {
			    	curseur =4;
			    	Mix_PlayChannel(1,clickmusic,0);
			    }
			break;
			case SDL_QUIT:
		    			done = 1;
		    	break;
			
			case SDL_MOUSEBUTTONDOWN:
			    if (event.button.button == SDL_BUTTON_LEFT)
			    {
				switch (curseur)
				{
				 case 1:
					startt(screen);
				 break;
				case 2:
					optionn(screen);
				 break;
				case 3:
					done=1;
				 break;
				 case 4:
					score(screen);
				 break;
				}
			    }
			break;

		}
		if (i==1)
		{

		afficher(start2,screen);
		Mix_PlayChannel(1,clickmusic,0);
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
		}
		SDL_Flip(screen);
}
}
		liberer(&start);
		liberer(&start1);
		liberer(&setting1);
		liberer(&exit1);
		Mix_FreeMusic(music);
		SDL_FreeSurface(screen) ;
		TTF_CloseFont(a.font);
		TTF_Quit();
	    return 0;
}
