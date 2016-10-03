/*
 * 		FONCTIONS DE CONTROLE :
 * 	       BOUTONS, ...
 * 
 */ 


#include "4096.h"


choixBouton attendre_selection();

choixBouton attendre_parametres();

void changer_parametres(choixBouton boutonChoisi, modeDifficulte *difficulte, modeAffichage *affichage, modeFusion *fusion);

BOOL a_clique_dans_bouton_haut(POINT P);
BOOL a_clique_dans_bouton_bas(POINT P);
BOOL a_clique_dans_bouton_gauche(POINT P);
BOOL a_clique_dans_bouton_droite(POINT P);
BOOL a_clique_dans_bouton_aide(POINT P);
BOOL a_clique_dans_bouton_quitter(POINT P);


BOOL a_clique_dans_bouton_aff0(POINT P);
BOOL a_clique_dans_bouton_aff1(POINT P);
BOOL a_clique_dans_bouton_facile(POINT P);
BOOL a_clique_dans_bouton_difficile(POINT P);
BOOL a_clique_dans_bouton_classique(POINT P);
BOOL a_clique_dans_bouton_totale(POINT P);

BOOL a_clique_dans_bouton_start(POINT P);
