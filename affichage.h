/*
 * 		FONCTIONS D'AFFICHAGE :
 * 	  GRILLE, TUILES, BOUTONS...
 * 
 */ 

#include "4096.h"



//void initInterfaces(t_interface *interface1, t_interface *interface2);

void afficheAccueil(modeDifficulte difficulte, modeAffichage affichage, modeFusion fusion);

void afficheJeu();

void afficheBoutonAff0(BOOL actif);
void afficheBoutonAff1(BOOL actif);
void afficheBoutonFacile(BOOL actif);
void afficheBoutonDifficile(BOOL actif);
void afficheBoutonClassique(BOOL actif);
void afficheBoutonTotale(BOOL actif);
void afficheTexteAccueil();

void afficheBoutonHaut(BOOL aide);
void afficheBoutonBas(BOOL a);//a -> aide
void afficheBoutonDroite(BOOL a);
void afficheBoutonGauche(BOOL a);


void afficheBoutonAide(BOOL a);
void afficheBoutonAideOn();
void afficheBoutonAideOff();
void effacerBoutonAide();

void affichePlateau();
void affichePlateau2();
void afficheScore(int score); // pas de pointeur

//void afficheGrille();

//void afficheBouton(t_bouton bouton);

