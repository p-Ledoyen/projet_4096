/*
 * 		FONCTIONS D'AFFICHAGE :
 * 	  GRILLE, TUILES, BOUTONS...
 * 
 */ 

#include "4096.h"



//void initInterfaces(t_interface *interface1, t_interface *interface2);

void afficheAccueil();

void afficheJeu();

void afficheBoutonHaut(BOOL aide);
void afficheBoutonBas(BOOL a);//a -> aide
void afficheBoutonDroite(BOOL a);
void afficheBoutonGauche(BOOL a);


void afficheBoutonAide(BOOL a);
void afficheBoutonAideOn();
void afficheBoutonAideOff();
void effacerBoutonAide();

void affichePlateau();
void afficheScore(int score); // pas de pointeur

//void afficheGrille();

//void afficheBouton(t_bouton bouton);

