#ifndef H_4096
#define H_4096

#include "graphics.h"


#define T_GRILLE 8
#define L_FENETRE 400+100*T_GRILLE
#define H_FENETRE 100+100*T_GRILLE
#define T_NOMBRE 20 //Taille d'affichage des nombres dans les tuiles


int plateau[T_GRILLE][T_GRILLE];

typedef enum
{
	HAUT, BAS, GAUCHE, DROITE, AIDE, QUITTER//, START, MODE_AFF_1, MODE_AFF_2, FACILE, DIFFICILE, FU_CLASSIQUE, FU_TOTALE
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




#endif
