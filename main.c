#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "backgroundd.h"
#include "boutonn.h"
#include "fonctions.h"
#include "enigme.h"

int main(int argc, char** argv) {

    SDL_Surface *ecran;
    SDL_Event event;
    int quitter = 1;
    int detect = 0; 
    int niv,i,j,past,p,nouv;
    int temps_actuel;
    int continuer;
    bouton B[14];
    bouton bv[4];
    background b;
    background bg;
    int volume = SDL_MIX_MAXVOLUME;
    int btPlus = 0;  
    int btMinus = 0;
    int maxVolumePresses = 4;
   
    SDL_Surface *perso;
    SDL_Rect posp;
    int showPerso = 0;
     
    int a=0;

    // Initialisation de SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    TTF_Init();

    // Création de la fenêtre
    ecran = SDL_SetVideoMode(1000, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (ecran == NULL) {
        fprintf(stderr, "Echec de creation de la fenetre de 600*430: %s.\n", SDL_GetError());
        return 1;
    }

    // Initialisation du background et des boutons
    Init_Background(&b);
    initson();
    tab_button(B);
    tab_btnv(bv);
 
    int right=0;
    int left=0;
    int up=0;
    int down=0;
    //input in;
    int running=1;
    int multi_player=0;
   
    perso = IMG_Load("perso.png");
    if (perso == NULL) {
        fprintf(stderr, "Echec de chargement de l'image perso.png.\n");
        return 1;
    }
    posp.x = 100;
    posp.y = 15;
    posp.w = perso->w;
    posp.h = perso->h;
    
   
   
    while (quitter) {
         
        //Lecture de l'événement
        SDL_PollEvent(&event);

        // Selon le type de l'événement
        switch (event.type) {
            // Quitter si la fenêtre est fermée
            case SDL_QUIT:
                quitter = 0;
                break;

            // Gestion des mouvements de la souris
            case SDL_MOUSEMOTION:
                for (int i = 0; i < 14; i++) {
                    if (event.motion.x >= B[i].pos.x && event.motion.x <= B[i].pos.x + B[i].pos.w &&
                        event.motion.y >= B[i].pos.y && event.motion.y <= B[i].pos.y + B[i].pos.h) {
                        B[i].actif = 1;
                        sonbutton();
                    } else {
                        B[i].actif = 0;
                    }
                }
            break;

            // Gestion des clics de la souris
            case SDL_MOUSEBUTTONDOWN:
                for (int i = 0; i < 14; i++) {
                    if (B[i].actif == 1) {
                        niv = i;
                        sonclic();
                         btPlus = 0;  //reinitialisation
        btMinus = 0;
                        break;
                    }
                }
                switch (niv) {
                    case 0:
                        b.niv = 1;  // Background "bg stage.png" pour le bouton play      
                        showPerso = 0;
                        break;
                    case 1:
                        b.niv = 2;  // Background "bgsett.png" pour le bouton settings
                        showPerso = 1;
                        break;
                    case 2:
                        quitter = 0;  // Quitter l'application pour le bouton quit
                        break;
                    // Ajoutez d'autres cas pour les autres boutons si nécessaire
                   
                // bt settings  clavier
                    case 3: // bt +
                        if (btPlus < maxVolumePresses) {
                            btPlus++;
                            volume += 25;
                            j = volume / 25;
                            past = j;

                           // Affiche l'image de btv dans l'ordre croissant
                           if (j >= 0 && j < 4) {
                             bv[j].actif = 1;
                           }
                        }
                        break;
                    case 4: // bt -
                         if (btMinus < maxVolumePresses) {
                              btMinus++;
                              volume -= 25;
                              j = volume / 25;
                              past = j;

                              // Affiche l'image de btv dans l'ordre décroissant
                              if (j >= 0 && j < 4) {
                                  bv[j].actif = 1;
                              }
                         }
                         if (volume == 0) {
                               Mix_PauseMusic();
                          }
                        break;


                   case 5: //bt mus
                       if (Mix_PausedMusic() != 0) {
                            Mix_ResumeMusic();
                       }
                       break;
                   case 6: // bt not mus
                       Mix_PauseMusic();
                       break;
                   

                   case 8:
                      if (b.niv > 0) {
                            b.niv=0;
                      }
                      break;
                  case 7:
                      if (b.niv == 2) {
                            showPerso = 1;
                        }
                    break;
                  case 11:
                     
                        b.niv = 3;  // Background "stage1.png" pour le bouton terre1      
                        Mix_PlayMusic(b.musicst,-1);
                        Mix_AllocateChannels(10);
               Mix_VolumeMusic(b.vol);
                       
                    break;
               
                  case 12:
                        b.niv = 5;  // Background "stage2.png" pour le bouton hwee1      
                        
                    break;
                  case 13:
                        b.niv = 4;  // Background "stage3.png" pour le bouton mee1      
                        
                    break;
                   
                 
                }                
            break;
       
           
           
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_q:
                        quitter = 0;
                        break;
                    case SDLK_ESCAPE:
                        quitter = 0;
                        break;
                    case SDLK_p:
                        b.niv = 1;
                    break;
                    case SDLK_s:
                        b.niv = 2;
                    break;
                    case SDLK_b:
                        if (b.niv > 0) {
                            b.niv=0;
                            showPerso = 0;
                        }
                    break;
                    case SDLK_m:
                        multi_player=1;
                    break;
                    case SDLK_UP:
                        if (b.niv == 0) {
                            for (int i = 0; i < 3; i++) {
                                 B[i].actif = 0;
                             }
                             if (detect == 0) {
                                 detect = 3; // bouton quit sélectionné
                             }
                             else if (detect == 3) {
                                    detect = 2; // bouton settings sélectionné
                             }
                             else if (detect == 2) {
                                    detect = 1; // bouton play sélectionné
                             }
                             else {
                                 detect = 0;
                             }
                             B[detect].actif = 1;
                         }
                   
                        //scrolling(&b,3,20);
                        up=1;
                    break;

                    case SDLK_DOWN:
                       if (b.niv == 0) {
                             for (int i = 0; i < 3; i++) {
                                  B[i].actif = 0;
                              }
                              if (detect == 0) {
                                  detect = 1; // bouton play sélectionné
                               }
                               else if (detect == 1) {
                                     detect = 2; // bouton settings sélectionné
                               }
                               else if (detect == 2) {
                                     detect = 3; // bouton quit sélectionné
                               }
                               else {
                                    detect = 0;
                               }
                               B[detect].actif = 1;
                       }
                      //scrolling(&b,4,20);
                      down=1;
                   break;
                   case SDLK_KP_PLUS:
                        volume += 25;
                        if (volume >= 100)
                            volume = 100;
                        Mix_VolumeMusic(volume);
                    break;

                    case SDLK_KP_MINUS:
                        volume -= 25;
                        if (volume <= 0)
                            volume = 0;
                        Mix_VolumeMusic(volume);
                     break;
                     
                                       
                     case SDLK_f:
                        //SDL_WM_ToggleFullScreen(ecran);
ecran = SDL_SetVideoMode(800, 630, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN );
                        detect = 1;
                        break;

                    case SDLK_n:
                        ecran = SDL_SetVideoMode(1000, 700, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
                        detect = 2;
                        break;
                   case SDLK_LEFT:
                                 //scrolling(&b,2,20);
                         left=1;
                     break;
                   case SDLK_RIGHT:
                                 //scrolling(&b,1,20);
                         right=1;
                     break;
                 
                 
                }
                break;
             
               case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        up = 0;
                        break;
                    case SDLK_DOWN:
                        down=0;
                        break;
                    case SDLK_LEFT:
                        left=0;
                    break;
                    case SDLK_RIGHT:
                        right=0;
                    break;
               }
             break;
        }
       
 //304 ou 043      
      
       
       if (b.niv == 0) {
           
            animation0(&b,ecran);
        }
         if (b.niv==4){
             animation3(&b,ecran);
         }
       if (b.niv==3){
           animation1(&b,ecran);
           if (right==1){
               a++;
               b.vol++;
               Mix_VolumeMusic(b.vol);
           }
       }
      
     
        // Affichage du background
        Aff_Background(b, ecran, showPerso);
    /*   if(multi_player==1 && (b.niv ==3 ||b.niv ==4 ||b.niv ==5 )){
          SDL_Rect left={0,0,ecran->w /2 ,ecran->h /2};
          SDL_Rect left={ecran->w /2,0,ecran->w /2 ,ecran->h /2};
          aff_partage(b,ecran);
       }
       else{
           SDL_Rect full_screen={0,0,ecran->w,ecran->h};
           Aff_Background(b, ecran,&full_screen);
      }*/
      if(multi_player == 1 && (b.niv == 3 || b.niv == 4 || b.niv == 5)) {
    SDL_Rect left = {0, 0, ecran->w / 2, ecran->h / 2};
    SDL_Rect right = {ecran->w / 2, 0, ecran->w / 2, ecran->h / 2};
    // Afficher la partie gauche de l'écran
    aff_partage(b, ecran, left);
    // Afficher la partie droite de l'écran
    aff_partage(b, ecran, right);
} else {
    SDL_Rect full_screen = {0, 0, ecran->w, ecran->h};
    Aff_Background(b, ecran, showPerso);
}
      if(right==1){
         scrolling(&b,1,20);  
      }
      else if(left==1){
         scrolling(&b,2,20);
      }
      else if(up==1){
         scrolling(&b,3,20);
      }
      else if(down==1){
         scrolling(&b,4,20);
      }
          
         
         
          aff_btn(B, ecran, b);
 
       
        aff_btv(bv, ecran, b, volume);
   
       
        if (showPerso && B[7].actif==1) {
          SDL_BlitSurface(perso, NULL, ecran, &posp);
        } 
        if (b.niv==p) {
          nouv=0;
        }
        else
        {
        nouv=1;
        }
        if ((b.camera.x==1150)&&(b.niv == 3 || b.niv == 4 || b.niv == 5)&&(nouv==1))
        {
         
    p=b.niv;
     enigme e;
    genererenigme(&e,"enigme.txt");
    init_enigme(&e);
   
   temps_actuel=0;
   continuer=1;
    while (continuer==1) {
        animerenigme (&e);
        aff_enigme(e,ecran);
        SDL_Flip(ecran);
       
            SDL_Event event;
            SDL_PollEvent(&event);
       temps_actuel=SDL_GetTicks();
       if((15000<temps_actuel)&&(e.etat==0))
       {
          //p->score--;le score diminue
          e.etat=-1;
          aff_enigme(e,ecran);
         
       }
       else if(temps_actuel>20000)
       {
         
          continuer=0;
           
       }
       else
          {
            switch (event.type) {
                case SDL_QUIT:
                    continuer = 0;
                   
                    break;
         
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_a:
                        case SDLK_b:
                        case SDLK_c:
                          if(e.etat==0)
                           {
                            if (event.key.keysym.sym == e.rep_vrai) {
                                e.etat=1;
                             aff_enigme(e,ecran);
                            } else {
                                e.etat=-1;
                                aff_enigme(e,ecran);
                            }
                           
                            }
                            break;
                       
                            case SDLK_ESCAPE:
                              if (e.etat!=0){
                              continuer=0;}
                           
                             break;
                    }
                    break;
            }
       
 
   }
   
 }
    freeEnigme(&e);
        }
   
           
        // Rafraîchissement de l'écran
        SDL_Flip(ecran);
  }
    //freeAnimation(&animbg);

    // Libération de la mémoire
    free_btv(bv);
    free_btn(B);
    Free_Background(&b);
    SDL_FreeSurface(perso);

 
    TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
