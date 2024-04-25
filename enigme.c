#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include"enigme.h"
#include <SDL/SDL_image.h>
#include<time.h>
void aff_enigme(enigme e,SDL_Surface *ecran)
{ 
   if (e.etat==0)
      { 
         SDL_BlitSurface(e.bc,NULL,ecran,&e.pos_bc);
         SDL_BlitSurface(e.ques,NULL,ecran,&e.pos_qs);
         SDL_BlitSurface(e.rep,NULL,ecran,&e.pos_rep);
         
      }
   if (e.etat==1)
      { 
         SDL_BlitSurface(e.im[0],NULL,ecran,&e.pos_bc);
         SDL_Delay(3000);
      }
   if (e.etat==-1)
      { 
         SDL_BlitSurface(e.im[1],NULL,ecran,&e.pos_bc);
         SDL_Delay(3000);
      }
   SDL_Flip(ecran);
}
void init_enigme(enigme *e)
{ 
   int j;
   e->etat=0;
   e->bc=IMG_Load ("bk.png");
   e->pos_bc.y=(600-e->bc->w)/2;
   e->pos_bc.x=(430-e->bc->h)/2;
   e->pos_im.y=e->pos_bc.y;
   e->pos_im.x=e->pos_bc.x;
  e->im[0]=IMG_Load ("win.png");
  e->im[1]=IMG_Load ("lost.png");
   e->ques=IMG_Load (e->qs);
   e->rep=IMG_Load (e->nomrep);

   /*e->animer[0]=IMG_Load ("");
   e->animer[1]=IMG_Load ("");
   e->animer[2]=IMG_Load ("");
   e->animer[3]=IMG_Load ("");
   e->animer[4]=IMG_Load ("");*/
   e->pos_rep.y=e->pos_bc.y+80;
   e->pos_rep.x=e->pos_bc.x+30;
   e->pos_qs.y=e->pos_bc.y+30;
   e->pos_qs.x=e->pos_bc.x+20;
   //e->pos_animer.y=;
  // e->pos_animer.x=;
 
 }  

/*void animerenigme (enigme *e)
{
    Uint32 startTime = SDL_GetTicks();
    Uint32 animationInterval = 1000; 

        Uint32 currentTime = SDL_GetTicks();
        int currentFrame = (currentTime - startTime) / animationInterval %5;

        SDL_BlitSurface( e->animer[currentFrame],NULL,ecran,&e->pos_animer);

        // Mettre à jour l'écran
        SDL_Flip(screen);

        // Limiter la vitesse de l'animation
        SDL_Delay(50);
    }
}*/

void freeEnigme(enigme *e) 
{
   /* for (int i = 0; i < 2; ++i) 
    {
        SDL_FreeSurface(e->im[i]);
    }*/
    
        SDL_FreeSurface(e->ques);
    
        SDL_FreeSurface(e->rep);
   
      /*  for (int i = 0; i < 5; ++i) 
    {
        SDL_FreeSurface(e->animer[i]);
    }*/
    SDL_FreeSurface(e->bc);
}
void genererenigme(enigme *p,char *nomfichier)
{
  int i=0,j=0,trouve=0;
  FILE *f=NULL;
  f=fopen(nomfichier,"r");
  while(!feof)
    {
       fscanf(f,"%s %s %c",p->qs,p->nomrep,&p->rep_vrai);
       i++;
    }
  srand(time(NULL));
  p->choix=rand()%i+1;
  rewind(f);
  while((!feof)&&(trouve!=1))
   { j++;
     fscanf(f,"%s %s %c",p->qs,p->nomrep,&p->rep_vrai);
     if(j==p->choix)
     trouve=1;
   }
  rewind(f);
  
  fclose(f);

}











   
