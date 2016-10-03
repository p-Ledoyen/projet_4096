/*
 * 		FONCTIONS DE CALCUL :
 * 	ADDITION DE TUILES, SCORE, AIDE...
 * 
 */ 


#include "4096.h"


void initalise_plateau(int *nombreZeros);

void deplacer_vers(choixBouton boutonChoisi, modeFusion fusion, int *nbZeros, int *score);

int versBas(int *nombreZeros, int *score, BOOL doitJouer);

int versHaut(int *nombreZeros, int *score, BOOL doitJouer);

int versDroite(int *nombreZeros, int *score, BOOL doitJouer);

int versGauche(int *nombreZeros, int *score, BOOL doitJouer);

void generer_nouvelle_tuile(modeDifficulte difficulte, int* nbZeros);

void generer_nouvelle_tuile_difficile(int* nbZeros);

void generer_nouvelle_tuile_facile(int* nbZeros);

choixBouton meilleur_coup();

BOOL a_gagne();

BOOL a_perdu();
