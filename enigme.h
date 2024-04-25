#ifndef ENIGME_H
#define ENIGME_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct 
{  
   SDL_Surface *bc;
   SDL_Rect pos_bc;
   SDL_Surface *im[2];
   SDL_Rect pos_im;
   SDL_Surface *ques;
   SDL_Surface *rep;
   SDL_Rect pos_rep;
   SDL_Rect pos_qs;
   SDL_Rect pos_vrai;
   SDL_Surface *animer[5];
   SDL_Rect pos_animer;
   char qs[10];
   char nomrep[10];
   char rep_vrai;
   int etat;
   int choix;

}enigme;
void aff_enigme(enigme e,SDL_Surface *ecran);
void init_enigme(enigme *e);
void animerenigme (enigme *e);
void freeEnigme(enigme *e);
void genererenigme(enigme *p,char *nomfichier);
#endif
