/*
 * 		FONCTIONS DE CALCUL :
 * 	ADDITION DE TUILES, SCORE, AIDE...
 * 
 */ 


#include "4096.h"


void initPlateau(int* nbZeros);


//BOOL fusion(modeFusion fusion, choixBouton direction, int* nbZeros, int* score, BOOL doitJouer);

BOOL fusion_classique(choixBouton direction, int* nbZeros, int* score, BOOL doitJouer);

//BOOL fusion_totale(choixBouton direction, int* nbZeros, int* score, BOOL doitJouer);

BOOL fusion_classique_bas(int *nombreZeros, int *score, BOOL doitJouer);

BOOL fusion_classique_haut(int *nombreZeros, int *score, BOOL doitJouer);

BOOL fusion_classique_droite(int *nombreZeros, int *score, BOOL doitJouer);

BOOL fusion_classique_gauche(int *nombreZeros, int *score, BOOL doitJouer);


void generer_nouvelle_tuile(modeDifficulte difficulte, int* nbZeros);

void generer_nouvelle_tuile_difficile(int* nbZeros);

void generer_nouvelle_tuile_facile(int* nbZeros);

choixBouton meilleurCoup();
