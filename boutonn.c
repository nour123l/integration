 #include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "backgroundd.h"
#include "boutonn.h"
bouton init_btn(int x,int y,char *im1,char *im2){

bouton bt;
bt.img[0]=IMG_Load(im1);
bt.img[1]=IMG_Load(im2);
bt.pos.x=x;
bt.pos.y=y;
bt.pos.w=bt.img[0]->w;
bt.pos.h=bt.img[0]->h;

bt.actif=0;
return bt;
}
void tab_button(bouton B[]){
int x,y;
B[0]=init_btn(400, 190, "play0.png", "play1.png");
B[1]=init_btn(400,250, "set0.png", "set1.png");
B[2]=init_btn(400,310, "quit0.png", "quit1.png");
B[4]=init_btn(320,200,"bt-0.png","bt-1.png");
B[3]=init_btn(580,200, "bt+0.png", "bt+1.png");
B[5]=init_btn(350,350,"btmus0.png","btmus1.png");
B[6]=init_btn(450,350,"btnotmus0.png","btnotmus1.png");
B[7]=init_btn(550,350,"perso0.png","perso1.png");
B[8]=init_btn(20,30, "back0.png", "back1.png");
B[9]=init_btn(340,280,"normal0.png","normal1.png");
B[10]=init_btn(490,280,"fullscreen0.png","fullscreen1.png");
B[11]=init_btn(100,220,"terre0.png","terre1.png");
B[12]=init_btn(415,80,"hwee0.png","hwee1.png");
B[13]=init_btn(720,210,"mee0.png","mee1.png");
}
void aff_btn(bouton B[], SDL_Surface *ecran, background bg) {
    int i;
    if (bg.niv == 0) {
        for (i = 0; i < 3; i++) {
            if (B[i].actif) {
                SDL_BlitSurface(B[i].img[1], NULL, ecran, &B[i].pos);
            } else {
                SDL_BlitSurface(B[i].img[0], NULL, ecran, &B[i].pos);
            }
       }
    }

    if (bg.niv == 1) {
        for (i = 11; i < 14; i++) {
            if (B[i].actif) {
                SDL_BlitSurface(B[i].img[1], NULL, ecran, &B[i].pos);
            } else {
                SDL_BlitSurface(B[i].img[0], NULL, ecran, &B[i].pos);
            }
        }
    }

    if (bg.niv ==2) {
        for (i = 3; i < 11; i++) {
            if (B[i].actif) {
                SDL_BlitSurface(B[i].img[1], NULL, ecran, &B[i].pos);
            } else {
                SDL_BlitSurface(B[i].img[0], NULL, ecran, &B[i].pos);
            }
        }
    }
}

void free_btn(bouton B[]) {
    int i;
    for (i = 0; i < 14; i++) {
        SDL_FreeSurface(B[i].img[0]);
        SDL_FreeSurface(B[i].img[1]);
        //Mix_FreeChunk(B[i].son);
    }
}

bouton init_btv(char *im1){
bouton bt;
bt.img[0]=IMG_Load(im1);
bt.pos.x=405;
bt.pos.y=210;
bt.pos.w=bt.img[0]->w;
bt.pos.h=bt.img[0]->h;
bt.actif=0;
return bt;
}
void tab_btnv(bouton bv[]){

bv[0]=init_btv("v+.png");
bv[1]=init_btv("v++.png");
bv[2]=init_btv("v+++.png");
bv[3]=init_btv("vmax.png");

}
void aff_btv(bouton bv[], SDL_Surface *ecran, background bg, int volume) {
    int i;

    if (bg.niv == 2) {
        for (i = 0; i < 4; i++) {
            if (i < (volume / 25)) {
                SDL_BlitSurface(bv[i].img[0], NULL, ecran, &bv[i].pos);
            }
        }
    }
}
void free_btv(bouton bv[]) {
    int i;
    for (i = 0; i < 4; i++) {
        SDL_FreeSurface(bv[i].img[0]);
       
    }
}
