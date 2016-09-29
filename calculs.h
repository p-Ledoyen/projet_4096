/*
 * 		FONCTIONS DE CALCUL :
 * 	ADDITION DE TUILES, SCORE, AIDE...
 * 
 */ 


#include "4096.h"


void initPlateau();

void ajouterTuile(int puiss, int i, int j);

void initJeu(t_bouton* clavier);

int pop2F(int *nombreZeros);

int versBas(int *nombreZeros);

int versHaut(int *nombreZeros);


int versDroite(int *nombreZeros);

int versGauche(int *nombreZeros);

//void majScore(int *score, int ptsGagnes);

