#ifndef BOUTONN_H
#define BOUTONN_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct {
    SDL_Surface *img[2];
    SDL_Rect pos;
    Mix_Chunk *son1, *son2;
    int actif;
} bouton;

bouton init_btn(int x, int y, char *im1, char *im2);
void tab_button(bouton B[]);
void aff_btn(bouton B[], SDL_Surface *ecran, background bg);
void free_btn(bouton B[]);
bouton init_btv(char *im1);
void tab_btnv(bouton bv[]);
void aff_btv(bouton bv[], SDL_Surface *ecran, background bg, int volume);
void free_btv(bouton bv[]);
#endif // BOUTONN_H
