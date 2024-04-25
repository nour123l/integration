#include "entite.h"
#define W 100
#define H 120

void initEnty(entite *e){

	int x,y,h,w;
	int i=0,j=0;

	e->img[0][0]=IMG_Load("ghost ytir 3la 3sa.png");
	e->img[0][1]=IMG_Load("ghost ytir 3la 3sa.png");
	e->img[1][0]=IMG_Load("ghost ytir 3la 3sa ama shira lo5ra.png");
	e->img[1][1]=IMG_Load("ghost ytir 3la 3sa ama shira lo5ra.png");
	e->direction=0;
	e->pos.x=0;
	e->pos.y=150;
	e->pos.w = e->img[i][j]->w;
	e->pos.h = e->img[i][j]->h;
	e->anim=0;

	
}

void afficherEnnemi(entite e,SDL_Surface* screen){
	
	if (e.direction==1 && e.pos.x<4000){
        SDL_BlitSurface(e.img[1][0], NULL, screen, &e.pos);}
	else{
	if(e.direction==0 && e.pos.x<=4000)
	SDL_BlitSurface(e.img[0][0], NULL, screen, &e.pos);
	}
	//SDL_BlitSurface(e.img[e.direction][e.anim], NULL, screen, &e.pos);

}



void animerEntity(entite *e){
	int n;
	if (e->anim==2){
		e->anim=0;
		
	}
	else{
		e->anim++;
		
	}
	SDL_Delay(4);
}

int collisionTri(entite e,SDL_Rect pos){

	int x1,x2,y1,y2;
	int R1,R2;
	int d;

	//coordonnée de l'image du perso
	x1=pos.x+W;//w=w/2=100
	y1=pos.y+H;//h=h/2=120
	R1=(W*W+H*H);
	//coordonnée de l'image de l'entité
	x2=e.pos.x+e.pos.w/2;
	y2=e.pos.y+e.pos.h/2;
	R2 = ((e.pos.w / 2)*(e.pos.w / 2) +(e.pos.h / 2)*(e.pos.h / 2));
	d=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

	if (d*d>(R1+R2)*(R1+R2)){

		return 0;
	}else{
		if (d*d<(R1+R2)*(R1+R2)){

			return 1;
		}
	}
	
}

void move(entite *e){

	int posMax=4000,posMin=0;

	if (e->pos.x> posMax){
		e->direction=1;
	}
	if (e->pos.x<posMin){
		e->direction=0;
	}
	if (e->direction==0){
		e->pos.x++ ;
	}
	else{
		e->pos.x-- ;
}
	}

int collisionBB(entite e,SDL_Rect pos){

	if(e.pos.x<pos.x+pos.w || e.pos.x+e.pos.w>pos.x || e.pos.y<pos.y+pos.h || e.pos.y+e.pos.h>pos.y)
		return 0;
	else
		return 1;
}


void initEnty2(entite *e2){

	int x,y,h,w;
	int i=0,j=0;

  
	e2->img[0][0]=IMG_Load("dabouza tath7ek.png");
	e2->img[0][1]=IMG_Load("dabouza tath7ek.png");
	e2->direction=0;
	e2->pos.x=0;
	e2->pos.y=350;
	e2->pos.w = e2->img[0][0]->w;
	e2->pos.h = e2->img[0][0]->h;
	e2->anim=0;
        e2->mus=Mix_LoadMUS("tha7ka.mp3");
	Mix_PlayMusic(e2->mus,-1);
	
}
void afficherEnnemi2(entite e2,SDL_Surface* screen){
	
        if (e2.direction==1 && e2.pos.x< 4000){
        SDL_BlitSurface(e2.img[0][0], NULL, screen, &e2.pos);}
	else{
	if(e2.direction==0 && e2.pos.x<= 4000)
	SDL_BlitSurface(e2.img[0][0], NULL, screen, &e2.pos);
	}
	//SDL_BlitSurface(e.img[e.direction][e.anim], NULL, screen, &e.pos);

}
void move2(entite *e2){

	int posMax=1000,posMin=0;

	if (e2->pos.x> posMax){
		e2->direction=1;
	}
	if (e2->pos.x<posMin){
		e2->direction=0;
	}
	if (e2->direction==0){
		e2->pos.x++ ;
	}
	else{
		e2->pos.x-- ;
}
	}
void animerEntity2(entite *e2){
	int n;
	if (e2->anim==2){
		e2->anim=0;
		
	}
	else{
		e2->anim++;
		
	}
	 SDL_Delay(28);
}
