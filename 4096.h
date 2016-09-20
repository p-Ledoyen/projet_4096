#define L_FENETRE 1200
#define H_FENETRE 900
#define T_GRILLE 8
#define T_NOMBRE 20 //Taille d'affichage des nombres dans les tuiles

typedef struct
{
	char* texte; //Texte à afficher sur le bouton
	
	COULEUR clr_fond;
	COULEUR clr_texte;
}t_bouton;

typedef struct
{
	unsigned int valeur;
	COULEUR 
}t_case; //Type case

typedef struct
{
	unsigned int epaisseur; //Epaisseur des traits de la grille
	//police
	COULEUR clr_grille;
	COULEUR palette[13][2]; //Ensemble des couleurs correspondant aux tuiles et à leurs valeurs
}t_interface; //Mode d'affichage du plateau de jeu


typedef enum
{
	HAUT, BAS, GAUCHE, DROITE, AIDE, QUITTER, START, MODE_AFF_1, MODE_AFF_2, FACILE, DIFFICILE, FU_CLASSIQUE, FU_TOTALE
}bouton

typedef enum
{
	CLASSIQUE, TOTALE
}modeFusion;

int plateau[T_GRILLE][T_GRILLE];


