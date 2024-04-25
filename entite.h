#ifndef entite_H_INCLUDED
#define entite_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct{
    SDL_Surface *img[2][2];
    int direction;
    SDL_Rect pos;
    int anim;
    Mix_Music *mus;
}entite;

/*typedef struct{
    int mu;
    int md;
    int ml;
    int mr;
} direction;*/


void initEnty(entite *e);
void initEnty2(entite *e2);
void afficherEnnemi(entite e,SDL_Surface* screen);
void afficherEnnemi2(entite e2,SDL_Surface* screen);
void animerEntity(entite *e);
void animerEntity2(entite *e2);
int collisionTri(entite e,SDL_Rect pos);
void move(entite *e);
void move2(entite *e2);
int collisionBB(entite e,SDL_Rect pos);
//void moveIA(entite *e);  


#endif
