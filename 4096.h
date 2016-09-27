#ifndef H_4096
#define H_4096

#include "graphics.h"

#define L_FENETRE 1200
#define H_FENETRE 900
#define T_GRILLE 8
#define T_NOMBRE 20 //Taille d'affichage des nombres dans les tuiles


int plateau[T_GRILLE][T_GRILLE];

typedef enum
{
	HAUT, BAS, GAUCHE, DROITE, AIDE_ON, AIDE_OFF, QUITTER//, START, MODE_AFF_1, MODE_AFF_2, FACILE, DIFFICILE, FU_CLASSIQUE, FU_TOTALE
}choixBouton;

typedef struct
{
	char* texte; //Texte à afficher sur le bouton
	choixBouton nom;
	POINT pt_hg, pt_bd;
	COULEUR clr_fond;
	COULEUR clr_texte;
	int t_texte;
}t_bouton;



typedef enum
{
	CLASSIQUE, TOTALE
}modeFusion;



//const COULEUR palette[2][13]={{gris,gris,gris,gris,gris,gris,gris,gris,gris,gris,gris,gris,gris,},{gris,gris,gris,gris,gris,gris,gris,gris,gris,gris,gris,gris,gris,}};

/*
int i;
palette[0][0]=(COULEUR) gris;
palette[1][0]=(COULEUR) blanc;
for(i=1; i<13; i++)
{
	
	palette[0][i]=(COULEUR) blanc;
	palette[1][i]=(COULEUR) green;
		
}

*/



#endif
