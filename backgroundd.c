#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "backgroundd.h"
#include "fonctions.h"

void Init_Background(background *b){
        int x, y, w, h,i;
        b->vol = 1;
         
        b->image[0] = IMG_Load ("pp.png");
        if (b->image[0]== NULL) {
          return ;
         }
        b->image[1] = IMG_Load ("bgpl1.png");
        if (b->image[1]== NULL) {
                     SDL_FreeSurface(b->image[0]);
          return ;
        }
        b->image[2] = IMG_Load ("bgsett.png");
        if (b->image[2]== NULL) {
                    SDL_FreeSurface(b->image[0]);
                    SDL_FreeSurface(b->image[1]);
         return ;
        }
        b->image[3] = IMG_Load ("st terre.png");
        if (b->image[3]== NULL) {
                    SDL_FreeSurface(b->image[0]);
                    SDL_FreeSurface(b->image[1]);
                    SDL_FreeSurface(b->image[2]);
         return ;
        }
        b->image[4] = IMG_Load ("bhar1.png");
        if (b->image[4]== NULL) {
                    SDL_FreeSurface(b->image[0]);
                    SDL_FreeSurface(b->image[1]);
                    SDL_FreeSurface(b->image[2]);
                    SDL_FreeSurface(b->image[3]);
         return ;
        }
      
        b->image[5] = IMG_Load ("nar2.png");
        if (b->image[5]== NULL) {
                    SDL_FreeSurface(b->image[0]);
                    SDL_FreeSurface(b->image[1]);
                    SDL_FreeSurface(b->image[2]);
                    SDL_FreeSurface(b->image[3]);
                    SDL_FreeSurface(b->image[4]);
         return ;
       
         b->image[6] = IMG_Load ("st terre.png");
        if (b->image[6]== NULL) {
                    SDL_FreeSurface(b->image[0]);
                    SDL_FreeSurface(b->image[1]);
                    SDL_FreeSurface(b->image[2]);
                    SDL_FreeSurface(b->image[3]);
                    SDL_FreeSurface(b->image[4]);
                    SDL_FreeSurface(b->image[5]);
         return ;
         
         b->image[7] = IMG_Load ("bhar1.png");
        if (b->image[7]== NULL) {
                    SDL_FreeSurface(b->image[0]);
                    SDL_FreeSurface(b->image[1]);
                    SDL_FreeSurface(b->image[2]);
                    SDL_FreeSurface(b->image[3]);
                    SDL_FreeSurface(b->image[4]);
                    SDL_FreeSurface(b->image[5]);
                    SDL_FreeSurface(b->image[6]);
         return ;

         b->image[8] = IMG_Load ("nar2.png");
        if (b->image[8]== NULL) {
                    SDL_FreeSurface(b->image[0]);
                    SDL_FreeSurface(b->image[1]);
                    SDL_FreeSurface(b->image[2]);
                    SDL_FreeSurface(b->image[3]);
                    SDL_FreeSurface(b->image[4]);
                    SDL_FreeSurface(b->image[5]);
                    SDL_FreeSurface(b->image[6]);
                    SDL_FreeSurface(b->image[5]);
                    SDL_FreeSurface(b->image[7]);
         return ;
        }
       

        b->pos.x=0;
        b->pos.y=0;
        b->pos.w=b->image[0]->w;
        b->pos.h=b->image[0]->h;
       //pos pour le partage d'ecran :
      for(int i = 6; i < 9; i++) {
        b->pospar.x = 500;
        b->pospar.y = 0;
        b->pospar.w = b->image[i]->w;
        b->pospar.h = b->image[i]->h;
    }
   

        b->camera.x=0;
        b->camera.y=0;
        b->camera.w = 1000;
        b->camera.h = 700;

        b->post.x=260;
        b->post.y=130;
     
        b->textColor.r=0;
        b->textColor.g=0;
        b->textColor.b=0;
       
       
        b->font=TTF_OpenFont("arial.ttf",20);
       
        b->musique = Mix_LoadMUS("music.mp3");
        b->niv=0;
        b->surfaceTexte=TTF_RenderText_Blended(b->font,"Bienvenue Dans The Island's Spirit",b->textColor);
       
        Mix_PlayMusic(b->musique,-1);
       //music stage
   
        b->musicst= Mix_LoadMUS("musique.mp3");
         //animation stage 1
        int i;
        char ch1[20];
        for(i=1;i<29;i++){
             sprintf(ch1,"an%d.png",i);
             b->anima1[i] = IMG_Load(ch1);
       
        }
        b->anim1=0;

        //animation stage 3
        int k;
        char ch3[20];
        for(k=1;k<35;k++){
             sprintf(ch3,"fs%d.png",k);
             b->anima3[k] = IMG_Load(ch3);
       
        }
        b->anim3=0;

        //animation menu
        int j;
        char ch0[20];
        for(j=1;j<50;j++){
             sprintf(ch0,"ch%d.png",j);
             b->anima0[j] = IMG_Load(ch0);
       
        }
        b->anim0=0;
        

        
}
void Aff_Background(background b, SDL_Surface *ecran, int showPerso){
    SDL_Surface *perso;
    SDL_Rect posp;
   SDL_Rect pospar;
    // Initialisation de posp
    pospar.x = 100;
    pospar.y = 15;
    SDL_BlitSurface(b.image[b.niv], NULL, ecran, &b.pos);
     
        if(b.niv==0)
                {
               SDL_BlitSurface(b.surfaceTexte,NULL,b.image[0],&b.post);
        }
       if (showPerso && b.niv==2) {
        SDL_BlitSurface(perso, NULL, ecran, &posp);
    }
     
   
    SDL_BlitSurface(b.image[b.niv], &b.camera, ecran, &b.pos);
    if (b.niv==0){
      SDL_BlitSurface(b.anima0[b.anim0],&b.camera,ecran,&b.pos);
    }
    if (b.niv==3){
      SDL_BlitSurface(b.anima1[b.anim1],&b.camera,ecran,&b.pos);
    }
  if (b.niv==4){
      SDL_BlitSurface(b.anima3[b.anim3],&b.camera,ecran,&b.pos);
    }
}

/*void aff_partage(background b,SDL_Surface * ecran){
     for(i=6;i<9;i++){
            SDL_BlitSurface(b.image[i], NULL, ecran, &b.pospar);
     } 
}*/
void aff_partage(background b, SDL_Surface *ecran, SDL_Rect pos) {
    // Correction de la portée de la variable i
    for(int i = 6; i < 9; i++) {
        // Positionner la position de l'image sur l'écran
        b.pospar.x = pos.x;
        b.pospar.y = pos.y;
        b.pospar.w = b.image[i]->w;
        b.pospar.h = b.image[i]->h;
        // Copier l'image sur l'écran à la position spécifiée
        SDL_BlitSurface(b.image[i], NULL, ecran, &b.pospar);
    }
}

void Free_Background(background *b){
     for (int i = 0; i < 9; i++) {
        SDL_FreeSurface(b->image[i]);
    }

    Mix_FreeMusic(b->musique);
    Mix_CloseAudio();
    SDL_FreeSurface(b->surfaceTexte);
    TTF_CloseFont(b->font);
    TTF_Quit();
    SDL_Quit();
  }


void animation1 (background *b,SDL_Surface * ecran) {

     
     if(b->anim1<29){
        b->anim1++;
     }
     else{
        b->anim1=0;
     }
     SDL_Delay(100);

}    

void animation3 (background *b,SDL_Surface * ecran) {

     
     if(b->anim3<35){
        b->anim3++;
     }
     else{
        b->anim3=0;
     }
     SDL_Delay(100);

}    


void animation0 (background *b,SDL_Surface * ecran){
if(b->anim0<50){
        b->anim0++;
     }
     else{
        b->anim0=0;
     }
     SDL_Delay(100);
}

void scrolling(background *b,int direction,int pas)
{
      SDL_Surface *ecran;
     
    int l_ecran= ecran->w;
    int h_ecran = ecran->h;

    // Correction des limites de scrolling en fonction de la direction
    switch (direction) {
        case 1: // Pour faire défiler vers la droite
            b->camera.x += pas;
            if (b->camera.x > b->image[b->niv]->w - l_ecran) {
                b->camera.x = b->image[b->niv]->w - l_ecran;
            }
            break;
        case 2: // Pour faire défiler vers la gauche
            b->camera.x -= pas;
            if (b->camera.x < 0) {
                b->camera.x = 0;
            }
            break;
        case 3: // Pour faire défiler vers le bas
            b->camera.y += pas;
            if (b->camera.y > b->image[b->niv]->h - h_ecran) {
                b->camera.y = b->image[b->niv]->h - h_ecran;
            }
            break;
        case 4: // Pour faire défiler vers le haut
            b->camera.y -= pas;
            if (b->camera.y <= 0) {
                b->camera.y = 0;
            }
            break;
        default:
            break;
    }

}

