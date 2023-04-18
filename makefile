prog:menu.o main.o texte.o start.o option.o score.o background.o text.o scoreTxt.o
	gcc texte.o menu.o main.o start.o option.o score.o background.o text.o scoreTxt.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

main.o:main.c 
	gcc -c main.c -g
menu.o:menu.c 
	gcc -c menu.c -g
texte.o:texte.c
	gcc -c texte.c -g
start.o:start.c 
	gcc -c start.c -g
option.o:option.c 
	gcc -c option.c -g
text.o:text.c
	gcc -c text.c -g
background.o:background.c
	gcc -c background.c -g
score.o:score.c
	gcc -c score.c -g
scoreTxt.o:scoreTxt.c
	gcc -c scoreTxt.c -g
