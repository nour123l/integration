#include <stdio.h>
#include <stdlib.h>
#include "xo.h"
#define TEXT_MAX_SIZE 140

void initialisation(tic * t)
{
    int i;
    for(i=0;i<9;i++)
       t-> tabsuivi[i]=0;
    t->image1=SDL_LoadBMP("fond.bmp");
    t->image2=SDL_LoadBMP("croix.bmp");
    t->image3=SDL_LoadBMP("rond.bmp");
    t->image4=SDL_LoadBMP("fond2.bmp");	
    t->image5=SDL_LoadBMP("fond1.bmp");	
	 t->image6=SDL_LoadBMP("fond3.bmp");	
    t->joueur=1;
    t->tour=0;
    t->comic=TTF_OpenFont("arial.ttf",40);
    t->couleur.r=0;
    t->couleur.g=0;
    t->couleur.b=0;
    t->posMSG.x=0;
    t->posMSG.y=0;
}
void zoomText(SDL_Surface* screen) {
    TTF_Font* font = NULL; // Initialisez la police à NULL
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); // Utilisez NULL pour remplir toute la surface
    SDL_Color color = {0, 0, 0};
	
    int fontSize = 30;
    SDL_Surface* textSurface = NULL;
    SDL_Rect textPos;
    int done = 0;
    
    // Chargez la police à la taille de départ
    font = TTF_OpenFont("arial.ttf", fontSize);
    if (font == NULL) {
        printf("Unable to load font: %s\n", TTF_GetError());
        return;
    }
    
    while (!done) {
        if (fontSize < TEXT_MAX_SIZE) {
            // Fermez la police précédente avant de charger une nouvelle taille
            TTF_CloseFont(font);
            font = TTF_OpenFont("arial.ttf", fontSize++);
            if (font == NULL) {
                printf("Unable to load font: %s\n", TTF_GetError());
                return;
            }
            
            // Rendre le texte avec la nouvelle taille de police
            textSurface = TTF_RenderText_Solid(font, "VICTOIRE!", color);
            if (textSurface == NULL) {
                printf("Unable to render text surface: %s\n", TTF_GetError());
                return;
            }
        }
        
        // Calculer la position du texte au centre de l'écran
        textPos.x = screen->w / 2 - textSurface->w / 2;
        textPos.y = screen->h / 2 - textSurface->h / 2;
        
        // Afficher le texte
        SDL_BlitSurface(textSurface, NULL, screen, &textPos);
        SDL_Flip(screen);
        
        // Gérer les événements
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = 1;
            }
        }
        SDL_Delay(50);
    }
    
    // Libérer la mémoire de la surface du texte en dehors de la boucle
    SDL_FreeSurface(textSurface);
    
    // Fermer la police après utilisation
    TTF_CloseFont(font);
}

void affichage(tic t,SDL_Surface *ecran ) 
{
    int i;
	SDL_Rect pos;
pos.w=1000;

switch (t.frame){
case 0:SDL_BlitSurface(t.image5,NULL,ecran,&pos);
break;
case 1:SDL_BlitSurface(t.image4,NULL,ecran,NULL);
break;
case 2: SDL_BlitSurface(t.image6,NULL,ecran,NULL);
break;}

    SDL_BlitSurface(t.image1,NULL,ecran,NULL);
    for(i=0;i<9;i++)
   {
		t.pos.x=190*(i%3); //calculer la position d'affichgage de chaque petit carreau exemple
		t.pos.y=190*(i/3);
        	switch(t.tabsuivi[i])// selon 
        	{
            		case 1:
                		SDL_BlitSurface(t.image2,NULL,ecran,&t.pos);	
            		break;
            		case -1:
                		SDL_BlitSurface(t.image3,NULL,ecran,&t.pos);
            		break;
        	}
	
    }
    
}
//////////////////////////////////////////////////////////////////////////////////////////////


void rotationtext(SDL_Surface* screen) {
    
SDL_Surface* textSurface;
    TTF_Font *font;
    SDL_Event event;

    SDL_Color color = {0, 0, 0};
    font = TTF_OpenFont("arial.ttf", 30);
    textSurface = TTF_RenderText_Solid(font, "HARD LUCK!", color);
    double angle = 0.0;
    Uint32 startTime = SDL_GetTicks(); // Store the start time
int done=0;
    while (!done) {
	
     
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

        
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - startTime > 0) { 
            angle += 360.0 *0.001 * ((currentTime - startTime) / 1000.0); 
        }

       
        SDL_Surface* rotatedTextSurface = rotozoomSurface(textSurface, angle, 1.0, 1);
        SDL_Rect textPos = {screen->w / 2 - rotatedTextSurface->w / 2, screen->h / 2 - rotatedTextSurface->h / 2, 0, 0};
        SDL_BlitSurface(rotatedTextSurface, NULL, screen, &textPos);

       
        SDL_Flip(screen);

 while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                done = 1;
		
            }
        }

        // Free resources
        SDL_FreeSurface(rotatedTextSurface);

        // Delay to control rotation speed
        SDL_Delay(10);
    }
}

void Resultat (tic t,SDL_Surface* ecran)
{
SDL_Rect pos;
char msg[20];

    SDL_FillRect(ecran,0,SDL_MapRGB(ecran->format,255,255,255));
    pos.x=0;
    pos.y=0;
affichage(t,ecran);
    switch(atilganer(t.tabsuivi))
    {
        case 0:
            strcpy(msg, "NUL");
        break;
        case 1:
		
            rotationtext( ecran); 
		
        break;
        case -1:  
            zoomText(ecran);
    }

 SDL_BlitSurface(TTF_RenderText_Solid(t.comic,msg,t.couleur),NULL,ecran,&t.posMSG);
 SDL_Flip(ecran);
    SDL_Delay(4028);
    
}

void liberationmemoire(tic t)
{
    SDL_FreeSurface(t.image1);
    SDL_FreeSurface(t.image2);
    SDL_FreeSurface(t.image3);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

int atilganer(int tabsuivi[])
{

    int lignes_gagnantes[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i=0;i<8;++i)
        if(tabsuivi[lignes_gagnantes[i][0]]!=0&&
           tabsuivi[lignes_gagnantes[i][0]]==tabsuivi[lignes_gagnantes[i][1]]&&
           tabsuivi[lignes_gagnantes[i][0]]==tabsuivi[lignes_gagnantes[i][2]])
                return tabsuivi[lignes_gagnantes[i][2]];
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int minimax(int tabsuivi[],int joueur)
{
    int gagnant=atilganer(tabsuivi);
    if(gagnant!=0)
        return gagnant*joueur;
    int coup=-1;
    int score=-2;
    int i;
    for(i=0;i<9;++i)
    {
        if(tabsuivi[i]==0)
        {
            tabsuivi[i]=joueur;
            int mmscore=-minimax(tabsuivi,joueur*-1);
            if(mmscore>score)
            {
                score=mmscore;
                coup=i;
            }
            tabsuivi[i]=0;
        }
    }
    if(coup==-1)
        return 0;
    return score;
}
//////////////////////////////////////////////////////////////////////////////////
void calcul_coup(int tabsuivi[])
{
    int coup=-1;
    int score=-2;
    int i;
    for(i=0;i<9;++i)
    {
        if(tabsuivi[i]==0)
        {
            tabsuivi[i]=1;
            int mmscore=-minimax(tabsuivi,-1);
            tabsuivi[i]=0;
            if(mmscore>score)
            {
                score=mmscore;
                coup=i;
            }
        }
    }
    tabsuivi[coup]=1;
}
/////////////////////////////////////////////////////////////////////////////////
