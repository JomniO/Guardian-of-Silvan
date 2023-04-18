#include "menu.h"
void init_start1(image *start1)
{
	start1->img=IMG_Load("images/buttons/00.png");
 	start1->pos.x=560;
 	start1->pos.y=150;
}
void init_start2(image *start2)
{
	start2->img=IMG_Load("images/buttons/01.png");
 	start2->pos.x=560;
 	start2->pos.y=150;
}
void init_setting1(image *setting1)
{
	setting1->img=IMG_Load("images/buttons/10.png");
 	setting1->pos.x=560;
 	setting1->pos.y=300;
}
void init_setting2(image *setting2)
{
	setting2->img=IMG_Load("images/buttons/11.png");
 	setting2->pos.x=560;
 	setting2->pos.y=300;
}
void init_exit1(image *exit1)
{
	exit1->img=IMG_Load("images/buttons/20.png");
 	exit1->pos.x=560;
 	exit1->pos.y=450;
}
void init_exit2(image *exit2)
{
	exit2->img=IMG_Load("images/buttons/21.png");
 	exit2->pos.x=560;
 	exit2->pos.y=450;
}
void liberer(image *p)
{
	SDL_FreeSurface(p->img);
}


void init_start(image *back)
{
    back->img = IMG_Load("images/background/6.jpg");
    back->pos.x = 0;
    back->pos.y = 0;
    back->pos.w = 1200;
    back->pos.h = 600;
}
void init_option(image *back)
{
    back->img = IMG_Load("images/background/option.jpg");
    back->pos.x = 0;
    back->pos.y = 0;
    back->pos.w = 1200;
    back->pos.h = 600;
}
void afficher(image p ,SDL_Surface *ecran)
 {	
 	SDL_BlitSurface(p.img,NULL,ecran,&p.pos);
 }

void init_backk(image *back)
{
	    back->img = IMG_Load("images/buttons/back.png");
	    back->pos.x = 10;
	    back->pos.y = 10;

}
void init_score(image *back)
{
	    back->img = IMG_Load("images/buttons/score.png");
	    back->pos.x = 10;
	    back->pos.y = 10;

}
void init_full1(image *back)
{
    back->img = IMG_Load("images/buttons/fullno.png");
    back->pos.x = 525;
    back->pos.y = 265;
}
void init_full2(image *back)
{
    back->img = IMG_Load("images/buttons/fullyes.png");
    back->pos.x = 525;
    back->pos.y = 265;
}
void init_son(image *back)
{
    back->img = IMG_Load("images/buttons/sound.png");
    back->pos.x = 525;
    back->pos.y = 330;
}
void init_plus(image *back)
{
    back->img = IMG_Load("images/buttons/plus1.png");
    back->pos.x = 737;
    back->pos.y = 350;
}
void init_plus1(image *back)
{
    back->img = IMG_Load("images/buttons/plus2.png");
    back->pos.x = 737;
    back->pos.y = 350;
}
void init_moin(image *back)
{
    back->img = IMG_Load("images/buttons/moin1.png");
    back->pos.x = 450;
    back->pos.y = 365;
}
void init_moin1(image *back)
{
    back->img = IMG_Load("images/buttons/moin2.png");
    back->pos.x = 450;
    back->pos.y = 365;
}

void init_anim(image menu[],char anim[])
{
	int i;
	for (i=0; i<40; i++)
	{
	sprintf(anim,"images/background/b%d.jpg",i);
	menu[i].img=IMG_Load(anim);  
	menu[i].pos.x=0;
	menu[i].pos.y=0;			
	}
}
void afficher_animation(image menu[],SDL_Surface *screen,int i)
{
	SDL_BlitSurface(menu[i].img,NULL,screen,&menu[i].pos);
	SDL_Delay(80);
}





































