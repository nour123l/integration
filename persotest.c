#include "persotest.h"
//#include <SDL/SDL_keyboard.h> // Ajoutez cette ligne pour inclure l'en-tête nécessaire



// Initialisation du personnage
void initPerso(perso *p)
{ 
    p->spritesheet=IMG_Load("fedi.png");
    p->position.x=0;
    p->position.y=0;
    p->direction=0;//(2: gauche, 1: droite, 0: immobile)
    p->acceleration=0;
    p->vitesse=0;
    p->vitesseV=0;
    p->pos_sprite.x= 0; // Position horizontale du sprite dans le spritesheet
    p->pos_sprite.y= 0;// Position verticale du sprite dans le spritesheet
    p->pos_sprite.h=  p->spritesheet->h/5;// Hauteur du sprite/nbligne
    p->pos_sprite.w= p->spritesheet->w/5 ; // Largeur du sprite/nbcol
    p->up=0; //(up=1:el fouk      up=0:ellouta)
p->upp=0; //(upp=1:el fouk      upp=0:ellouta)
}



// Affichage du personnage
void afficherPerso(perso p, SDL_Surface *screen)
{

    SDL_BlitSurface(p.spritesheet, &p.pos_sprite, screen, &p.position); // Afficher la partie sélectionnée de l'image sur l'écran
    //SDL_BlitSurface(p.spritesheet, &srcRect, screen, &p.position); // Affichage du sprite du personnage sur l'écran
}


// Déplacement du personnage


void movePerso(perso *p, int dt)
{
    //p->dx = 0 * p->acceleration * dt * dt + p->vitesse * dt;

    Uint8 *keystate = SDL_GetKeyState(NULL);

    if (keystate[SDLK_RIGHT] && p->position.x <1522 )
    {
        p->position.x += 5;
p->direction = 2;
    }
    else if (keystate[SDLK_LEFT] && p->position.x >0 )
    {
//p->position.y=p->spritesheet->h/2;
//p->pos_sprite.x= 527; // Position horizontale du sprite dans le spritesheet
    //p->pos_sprite.y=  p->spritesheet->h/2;       
p->position.x -= 5;
p->direction =1;
 

    }
}

// Animation du personnage
void animerPerso(perso *p)
{
int spriteHeight=1783; // Hauteur totale de la feuille de sprite
int numLines=5; // Nombre de lignes dans le sprite

// Calculer la hauteur de chaque ligne
int lineHeight = spriteHeight / numLines;

// Coordonnées pour la première ligne
int l1 = 0; // La première ligne commence à l'indice 0
int l2 = lineHeight; // La deuxième ligne commence après la première ligne
int l3= 2 * lineHeight; // La troisième ligne commence après la deuxième ligne
int l4 = 3 * lineHeight; // La quatrième ligne commence après la troisième ligne
int l5 = 4 * lineHeight; // La cinquième ligne commence après la quatrième ligne
    p->pos_sprite.x += p->pos_sprite.w; // Déplacement horizontal du sprite dans le spritesheet

    // Si la position horizontale dépasse la largeur du spritesheet, réinitialisez-la à zéro
    if (p->pos_sprite.x >= p->spritesheet->w - p->pos_sprite.w)
       { //zedtou
	p->pos_sprite.x = 0;

    // Mise à jour de la position verticale du sprite en fonction de la direction
    // Supposons que la direction 0 représente le bas, 1 représente la gauche, 2 représente la droite, 3 représente le haut
    switch (p->direction)
    {
        case 0: // Bas
            p->pos_sprite.y = 0; // Affiche la première ligne du spritesheet
            break;
        case 1: // Gauche
            p->pos_sprite.y = l2; // Affiche la deuxième ligne du spritesheet
p->pos_sprite.x=p->pos_sprite.x+p->pos_sprite.x;
            break;
        case 2: // Droite
            p->pos_sprite.y = l3; // Affiche la troisième ligne du spritesheet
p->pos_sprite.x=p->pos_sprite.x+p->pos_sprite.x;
            break;
        case 3: // Haut
            p->pos_sprite.y =l1; // Affiche la quatrième ligne du spritesheet
            break;
case 5: //yasbah lel ysar
            p->pos_sprite.y = l4; 
p->pos_sprite.x=p->pos_sprite.x+p->pos_sprite.x;
            break;
case 6: //yasbah lel ymin
            p->pos_sprite.y = l5; 
p->pos_sprite.x=p->pos_sprite.x+p->pos_sprite.x;
            break;
        
    }
}//zedtou
}


//saut du personnage
void saut(perso *p, Uint32 dt, int posx_absolu, int posy_absolu , int up) //posx w posy houma les positions taa perso
{
   
        double dx, dy;
        double a0 = 0.04; // Accélération verticale
        double v0 = 0;     // Vitesse initiale

        // Calcul du déplacement horizontal
        dx = 0.5 * a0 * dt * dt + v0 * dt;

        // Calcul du déplacement vertical
        dy = a0 * dx * dx + 100; // 100 est la hauteur initiale du saut

 if (up == 0){

        // Si la touche "UP" est relâchée, arrêter le saut et ramener le personnage au sol
        //p->up = 0;
        p->position.y = posy_absolu; // Ramener le personnage au sol bech yraja3lou y leblasetha
        }
        // Ajout de condition pour déterminer la direction du saut
        else if (up == 1 ) 
{
if(p->direction=2){
            // Si le personnage fait face à droite, il saute vers la droite
            p->position.x += 3 * dx; // Augmentation de la position horizontale vers la droite
}
else if(p->direction=1){
            // Sinon, il saute vers la gauche

            p->position.x -= 3 * dx; // Augmentation de la position horizontale vers la gauche
        }
}
        p->position.y = posy_absolu - dy;
    
       
}

void sautvert(perso* p , int upp) 
{
    int a = p->position.y;

    if (upp == 1)
    {
        p->vitesseV = -30; // Définir la vitesse verticale pour initier le saut
        p->position.y += p->vitesseV; // Mettre à jour la position verticale pendant le saut
    }
    else if (upp == 0)
    {
	   p->position.y -= p->vitesseV;
            p->position.y = a; // Réinitialiser la position verticale à sa valeur initiale
        
    }
}


void initialiser_score(vie *v)
{
    v->vie1=IMG_Load("health.png");
    v->valeur_vie=100;
    v->pos.x=0;
    v->pos.y=0;
    v->pos_spr.x=0;
    v->pos_spr.y=10;
    v->pos_spr.h=50;
    v->pos_spr.w=200;
}


void update_score(vie *v)
{
    v->pos_spr.y=((100-v->valeur_vie)/25)*50;
}


void afficher_vie(vie *v,SDL_Surface *screen)
{
    SDL_BlitSurface(v->vie1,&v->pos_spr,screen,&v->pos);
}

void liberer_vie(vie *v)
{
SDL_FreeSurface(v->vie1);
}
// Libération de la mémoire allouée pour le personnage
void liberer_perso(perso *p)
{
    SDL_FreeSurface(p->spritesheet); // Libération de la surface du personnage
}








