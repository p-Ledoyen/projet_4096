/*
 * 		FONCTIONS D'AFFICHAGE :
 * 	  GRILLE, TUILES, BOUTONS...
 * 
 */ 

#include "4096.h"

void affiche_accueil(modeDifficulte difficulte, modeAffichage affichage, modeFusion fusion);

void affiche_jeu();

void affiche_bouton_Aff0(BOOL actif);
void affiche_bouton_Aff1(BOOL actif);
void affiche_bouton_Facile(BOOL actif);
void affiche_bouton_Difficile(BOOL actif);
void affiche_bouton_Classique(BOOL actif);
void affiche_bouton_Totale(BOOL actif);
void affiche_bouton_Start(BOOL actif);
void affiche_bouton_menu(BOOL actif, POINT P1, POINT P2, char *texte);
void affiche_texte_accueil();

void affiche_bouton_Haut(BOOL aide);
void affiche_bouton_Bas(BOOL a);//a -> aide
void affiche_bouton_Droite(BOOL a);
void affiche_bouton_Gauche(BOOL a);
void affiche_bouton_Aide(BOOL a);
void affiche_bouton_AideOn();
void affiche_bouton_AideOff();
void effacer_bouton_Aide();
void affiche_bouton_propose(choixBouton boutonPropose);
void efface_bouton_propose();
void affiche_bouton_quitter();

void affiche_plateau();
void affiche_score(int score);

void affiche_gagne();
void affiche_perdu();

