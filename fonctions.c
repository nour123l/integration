#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "fonctions.h"

void initAnimation(Animation *animbg) {
    // Initialiser la première image et la position
    animbg->image[0] = IMG_Load("bg1.png");
    animbg->pos.x = 0;
    animbg->pos.y = 0;
    animbg->nextimg = 0;

    // Charger les autres images
    for (int i = 1; i < 8; ++i) {
        char imgName[20];
        sprintf(imgName, "bg%d.png", i + 1);
        animbg->image[i] = IMG_Load(imgName);
   
    }
}

void updateAnimation(Animation *animbg) {
    // Mettre à jour la frame actuelle
    static Uint32 dernier_update = 0;
    Uint32 tmp_courant = SDL_GetTicks();
    // Vérifier si le temps écoulé est suffisant pour passer à la prochaine image
    if (tmp_courant - dernier_update >= 200) {
        animbg->nextimg = (animbg->nextimg + 1) % 8;
        dernier_update = tmp_courant;
    }

}

void drawAnimation(Animation *animbg, SDL_Surface *ecran) {
    SDL_BlitSurface(animbg->image[animbg->nextimg], NULL, ecran, &animbg->pos);
}

void freeAnimation(Animation *animbg) {
    // Libérer les surfaces d'image
    for (int i = 0; i < 8; ++i) {
        SDL_FreeSurface(animbg->image[i]);
    }
}



Mix_Chunk *son1;
Mix_Chunk *son2;

void initson() {
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);// Initialiser SDL_mixer
    // Charger les effets sonores
    son1=Mix_LoadWAV("boutton song.wav");
    son2=Mix_LoadWAV("mus.wav");
    if ( son1 == NULL || son2== NULL) {
        printf("Erreur lors du chargement des fichiers audio : %s\n", Mix_GetError());
    }
}

void sonbutton() {
    Mix_PlayChannel(-1, son2, 0);// Jouer l'effet sonore pour le bouton
}

void sonclic() {
    Mix_PlayChannel(-1, son1, 0);// Jouer l'effet sonore pour le clic
}
