#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct {
    SDL_Surface *image[8];  // Vous avez 8 images pour l'animation
    int nextimg;
    SDL_Rect pos;
} Animation;


void initAnimation(Animation *animbg);
void updateAnimation(Animation *animbg);
void drawAnimation(Animation *animbg, SDL_Surface *ecran);
void freeAnimation(Animation *animbg);

//son bt
void initson();
void sonbutton();
void sonclic();

#endif // FONCTIONS_H
