#ifndef BACKGROUNDD_H
#define BACKGROUNDD_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct {
    SDL_Surface *image[9];
    //SDL_Surface *image2[2];
    Mix_Music *musique;
    SDL_Rect pos;
    SDL_Rect pospar;
    int niv;
    SDL_Surface *surfaceTexte;
    SDL_Rect post;
    TTF_Font *font;
    SDL_Color textColor;
    char texte[50];
    Mix_Music *musicst;
    int vol;
    SDL_Rect camera ;
    //anim stage 3    
    int anim3;
    SDL_Surface *anima3[35];
     
     //anim stage 1    
    int anim1;
    SDL_Surface *anima1[29];
   
     //anim menu    
    int anim0;
    SDL_Surface *anima0[50];
    //SDL_Surface *imgg;
    //SDL_Rect camera1 ;
    //SDL_Surface *imgg1;
    //int mouv_perso;
    //int mouv_perso1;

} background;


/*typedef struct
{
int left,right,up,down;
}input;*/


void Init_Background(background *b);

void Aff_Background(background b, SDL_Surface *ecran, int showPerso);


void animation0 (background *b,SDL_Surface * ecran);
void animation1 (background *b,SDL_Surface * ecran);
void animation3 (background *b,SDL_Surface * ecran) ;
void scrolling(background *b,int direction,int pas);
void Free_Background(background *b);
void aff_partage(background b, SDL_Surface *ecran, SDL_Rect pos);



#endif // BACKGROUNDD_H

