/*
 * 		FONCTIONS DE CALCUL :
 * 	ADDITION DE TUILES, SCORE, AIDE...
 * 
 */ 


#include "4096.h"


void initPlateau();

void initJeu(t_bouton* clavier);

int pop2F(int *nombreZeros);


int versBas(int *nombreZeros, int *score, BOOL doitJouer);

int versHaut(int *nombreZeros, int *score, BOOL doitJouer);

int versDroite(int *nombreZeros, int *score, BOOL doitJouer);

int versGauche(int *nombreZeros, int *score, BOOL doitJouer);



choixBouton meilleurCoup();
