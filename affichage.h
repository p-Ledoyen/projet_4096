/*
 * 		FONCTIONS D'AFFICHAGE :
 * 	  GRILLE, TUILES, BOUTONS...
 * 
 */ 

#include "4096.h"

static COULEUR palette[2][13]={{0xC7B591,blanc,jaune, coral, orange, darkorange, crimson, rouge, firebrick, vert, bleu, blueviolet, azure},{noir, noir, noir, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc}};


//void initInterfaces(t_interface *interface1, t_interface *interface2);

void afficheAccueil();

void afficheJeu();

void affichePlateau();

void afficheGrille();

void afficheBouton(t_bouton bouton);

