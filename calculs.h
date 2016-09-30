/*
 * 		FONCTIONS DE CALCUL :
 * 	ADDITION DE TUILES, SCORE, AIDE...
 * 
 */ 


#include "4096.h"


void initPlateau(int *nombreZeros);

//void initJeu(t_bouton* clavier);

int pop2F(int *nombreZeros);


int versBas(int *nombreZeros, int *score, BOOL doitJouer);

int versHaut(int *nombreZeros, int *score, BOOL doitJouer);

int versDroite(int *nombreZeros, int *score, BOOL doitJouer);

int versGauche(int *nombreZeros, int *score, BOOL doitJouer);

void generer_2(modeDifficulte difficulte, int* nbZeros);

void generer_nouvelle_tuile_difficile(int* nbZeros);

void generer_nouvelle_tuile_facile(int* nbZeros);

choixBouton meilleurCoup();
