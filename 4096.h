#ifndef H_4096
#define H_4096

#include "graphics.h"

#define L_FENETRE 1200
#define H_FENETRE 900
#define T_GRILLE 8
#define T_NOMBRE 20 //Taille d'affichage des nombres dans les tuiles

typedef struct
{
	char* texte; //Texte à afficher sur le bouton
	char* nom;
	COULEUR clr_fond;
	COULEUR clr_texte;
}t_bouton;

typedef struct
{
	int exposant;
	POINT pt_hg, pt_bd;
	COULEUR clr_fond;
	COULEUR clr_texte;
	
}t_tuile; //Type tuile

typedef struct
{
	unsigned int epaisseur; //Epaisseur des traits de la grille
	//police
	COULEUR clr_grille;
	COULEUR palette[2][13]; //Ensemble des couleurs correspondant aux tuiles et à leurs valeurs
}t_interface; //Mode d'affichage du plateau de jeu


typedef enum
{
	HAUT, BAS, GAUCHE, DROITE, AIDE, QUITTER, START, MODE_AFF_1, MODE_AFF_2, FACILE, DIFFICILE, FU_CLASSIQUE, FU_TOTALE
}bouton;

typedef enum
{
	CLASSIQUE, TOTALE
}modeFusion;

t_tuile plateau[T_GRILLE][T_GRILLE];








#endif
