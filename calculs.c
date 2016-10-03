#include "calculs.h"


void initPlateau(int* nbZeros)
{
	unsigned int i,j;
	
	for(i = 0; i < T_GRILLE; i++)
	{
		for(j = 0; j < T_GRILLE; j++)
		{
			plateau[i][j] = 0; //Chaque case est vide...
		}
	}
	generer_nouvelle_tuile(FACILE, nbZeros); //... sauf pour 2 d'entre-elles
	generer_nouvelle_tuile(FACILE, nbZeros);
	
	return;
}


BOOL fusion(modeFusion fusion, choixBouton direction, int* nbZeros, int* score, BOOL doitJouer)
{
	BOOL plateauModifie = FALSE;

	if(fusion == CLASSIQUE)
	{
		plateauModifie = fusion_classique(direction, nbZeros, score, doitJouer);
	}
	else if(fusion == TOTALE)
	{
		//plateauModifie = fusion_totale(direction, nbZeros, score, doitJouer);
	}
	
	return plateauModifie;
}

BOOL fusion_classique(choixBouton direction, int* nbZeros, int* score, BOOL doitJouer)
{
	BOOL plateauModifie = FALSE;
	switch (direction)
	{
		case HAUT :
			plateauModifie = fusion_classique_haut(nbZeros, score, doitJouer);
			break;
		case BAS :
			plateauModifie = fusion_classique_bas(nbZeros, score, doitJouer);
			break;
		case DROITE :
			plateauModifie = fusion_classique_droite(nbZeros, score, doitJouer);
			break;
		case GAUCHE :
			plateauModifie = fusion_classique_gauche(nbZeros, score, doitJouer);
			break;
		default:
			break;
	}

	return plateauModifie;
}

/*
BOOL fusion_totale(choixBouton direction, int* nbZeros, int* score, BOOL doitJouer)
{
	BOOL plateauModifie = FALSE;

	switch (direction)
	{
		case HAUT :
			plateauModifie = fusion_totale_haut(nbZeros, score, doitJouer);
			break;
		case BAS :
			plateauModifie = fusion_totale_bas(nbZeros, score, doitJouer);
			break;
		case DROITE :
			plateauModifie = fusion_totale_droite(nbZeros, score, doitJouer);
			break;
		case GAUCHE :
			plateauModifie = fusion_totale_gauche(nbZeros, score, doitJouer);
			break;
		default:
			break;
	}
	
	return plateauModifie;
}
*/

BOOL fusion_classique_bas(int *nombreZeros, int *score, BOOL doitJouer /* Utile pour simuler un coup et aider le joueur */)
{
	int iColonne, iLigne, iPlace, iSelec;
	BOOL plateauModifie = FALSE;  //Vaut VRAI si le plateau est modifié d'une quelconque façon
	
	/*
	 * 	Calculs des sommes éventuelles
	 */
	for(iColonne = 0; iColonne < T_GRILLE; iColonne++)  //on parcourt toutes les colonnes
	{
		iSelec = 0; //indice de tuile de référence
		iLigne = 1; //indice de tuile de parcours des lignes
		iPlace = 0; //indice de la case suivante à remplir
	
		while(iSelec < T_GRILLE && iLigne < T_GRILLE) //tant que l'on est bien dans la colonne
		{
			if(plateau[iColonne][iSelec] != 0)	//si la tuile de référence est non nulle
			{
				while(plateau[iColonne][iLigne] == 0 && iLigne < T_GRILLE) //on cherche la tuile suivante non nulle
				{
					iLigne++;
				}				
				if(plateau[iColonne][iLigne] == plateau[iColonne][iSelec] && iLigne < T_GRILLE) //si les deux tuiles sont de même valeur
				{
					if(doitJouer)
					{
						plateau[iColonne][iSelec]++;		//on double la valeur de la tuile de réf
						plateau[iColonne][iLigne] = 0;		//et on efface la deuxième tuile
					}
					(*score) += pow(2, plateau[iColonne][iSelec] + 1);
					(*nombreZeros)++;
					iSelec = iLigne + 1;
					iLigne = iSelec + 1;
					plateauModifie = TRUE;
				}
				else
				{
					iSelec = iLigne; 		//sinon, les valeurs ne changent pas, et la tuile non nulle suivante devient la tuile de référence
					iLigne = iSelec + 1;
				}
			}
			else  //si la tuile de référence est nulle, on avance sans rien faire
			{
				iSelec++;
				iLigne++;
			}
		}

		/*
		 * 	Réagencement des tuiles dans le plateau
		 */
		if(doitJouer)
		{
			for(iLigne = 0; iLigne < T_GRILLE; iLigne++)
			{
				if(plateau[iColonne][iLigne] != 0)
				{
					printf(" plateau %d %d : %d\n", iColonne, iLigne, plateau[iColonne][iLigne]);
					plateau[iColonne][iPlace] = plateau[iColonne][iLigne];
					iPlace++;
				}
			}
			while(iPlace < T_GRILLE)
			{
				plateau[iColonne][iPlace]=0;
				iPlace++;
				/*
				if()
				{
					plateauModifie = TRUE;
				}
				*/
			}
		}
	}
	
	return plateauModifie;		
}

BOOL fusion_classique_haut(int *nombreZeros, int *score, BOOL doitJouer)
{	
	int iColonne, iLigne, iPlace, iSelec;
	BOOL plateauModifie = FALSE;  //Vaut VRAI si le plateau est modifié d'une quelconque façon
	
	/*
	 * 	Calculs des sommes 
	 */
	for(iColonne=T_GRILLE-1; iColonne>=0; iColonne--)  //on parcourt toutes les colonnes
	{
		iSelec=T_GRILLE-1;		//indice de tuile de référence
		iLigne=T_GRILLE-2; 		//indice de tuile de parcours des lignes
		iPlace=T_GRILLE-1;		//indice de la case suivante à remplir
	
		while(iSelec>=0 && iLigne>=0)	//tant que l'on est bien dans la colonne
		{
			
			if(plateau[iColonne][iSelec]!=0)	//si la tuile de référence est non nulle
			{
				while(plateau[iColonne][iLigne]==0 && iLigne>=0) //on cherche la tuile suivante non nulle
				{
					iLigne--;
				}
				if(plateau[iColonne][iLigne]==plateau[iColonne][iSelec] && iLigne>=0) //si les deux tuiles sont de même valeur
				{
					if(doitJouer)
					{
						plateau[iColonne][iSelec]++;		//on double la valeur de la tuile de réf
						plateau[iColonne][iLigne]=0;		//et on efface la deuxième tuile
					}
					(*nombreZeros)++;
					(*score)+=pow(2, plateau[iColonne][iSelec]+1);
					iSelec=iLigne-1;
					iLigne=iSelec-1;
					plateauModifie = TRUE;
				}
				else
				{
					iSelec=iLigne; 		//sinon, les valeurs ne changent pas, et la tuile non nulle suivante devient la tuile de référence
					iLigne=iSelec-1;
				}
			}
			else  //si la tuile de référence est nulle, on avance sans rien faire
			{
				iSelec--;
				iLigne--;
			}
		}

		/*
		 * 	Placement des nouvelles tuiles dans le plateau ("déplacement")	
		 */
		if(doitJouer)
		{
			for(iLigne=T_GRILLE-1; iLigne>=0; iLigne--)
			{
				if(plateau[iColonne][iLigne]!=0)
				{
					plateau[iColonne][iPlace]=plateau[iColonne][iLigne];
					iPlace--;
					//plateauModifie = TRUE;
				}
			}
			while(iPlace >= 0)
			{
				plateau[iColonne][iPlace] = 0;
				iPlace--;
				//plateauModifie = TRUE;
			}
		}
	}
	
	return plateauModifie;	
}

BOOL fusion_classique_gauche(int *nombreZeros, int *score, BOOL doitJouer)
{
	int iColonne, iLigne, iPlace, iSelec;
	BOOL plateauModifie = FALSE;  //Vaut VRAI si le plateau est modifié d'une quelconque façon
	
	/*
	 * 	Calculs des sommes
	 */	
	for(iLigne=0; iLigne<T_GRILLE; iLigne++)  //on parcourt toutes les lignes
	{
		iSelec=0;		//indice de tuile de référence
		iColonne=1; 	//indice de tuile de parcours des colonnes
		iPlace=0;		//indice de la case suivante à remplir
	
		while(iSelec<T_GRILLE && iColonne<T_GRILLE)	//tant que l'on est bien dans la colonne
		{
			
			if(plateau[iSelec][iLigne]!=0)	//si la tuile de référence est non nulle
			{
				while(plateau[iColonne][iLigne]==0 && iColonne<T_GRILLE) //on cherche la tuile suivante non nulle
				{
					iColonne++;
				}
				if(plateau[iColonne][iLigne]==plateau[iSelec][iLigne] && iColonne<T_GRILLE) //si les deux tuiles sont de même valeur
				{
					if(doitJouer)
					{
						plateau[iSelec][iLigne]++;		//on double la valeur de la tuile de réf
						plateau[iColonne][iLigne]=0;		//et on efface la deuxième tuile
					}
					(*nombreZeros)++;
					(*score)+=pow(2, plateau[iSelec][iLigne]+1);
					iSelec=iColonne+1;
					iColonne=iSelec+1;
					plateauModifie = TRUE;
				}
				else
				{
					iSelec=iColonne; 		//sinon, les valeurs ne changent pas, et la tuile non nulle suivante devient la tuile de référence
					iColonne=iSelec+1;
				}
			}
			else  //si la tuile de référence est nulle, on avance sans rien faire
			{
				iSelec++;
				iColonne++;
			}
		}
		
		/*
		 * 	Placement des nouvelles tuiles dans le plateau ("déplacement")	
		 */
		if(doitJouer)
		{
			for(iColonne=0; iColonne<T_GRILLE; iColonne++)
			{
				if(plateau[iColonne][iLigne]!=0)
				{
					plateau[iPlace][iLigne]=plateau[iColonne][iLigne];
					iPlace++;
				}
			}
			while(iPlace<T_GRILLE)
			{
				plateau[iPlace][iLigne]=0;
				iPlace++;
			}
		}
	}
	
	return plateauModifie;	
}

BOOL fusion_classique_droite(int *nombreZeros, int *score, BOOL doitJouer)
{
	int iColonne, iLigne, iPlace, iSelec;
	BOOL plateauModifie = FALSE;  //Vaut VRAI si le plateau est modifié d'une quelconque façon
	
	/*
	 * 	Calculs des sommes 
	 */	
	for(iLigne=0; iLigne<T_GRILLE; iLigne++)  //on parcourt toutes les lignes
	{
		iSelec=T_GRILLE-1;		//indice de tuile de référence
		iColonne=T_GRILLE-2; 	//indice de tuile de parcours des colonnes
		iPlace=T_GRILLE-1;		//indice de la case suivante à remplir
	
		while(iSelec>=0 && iColonne>=0)	//tant que l'on est bien dans la colonne
		{
			
			if(plateau[iSelec][iLigne]!=0)	//si la tuile de référence est non nulle
			{
				while(plateau[iColonne][iLigne]==0 && iColonne>=0) //on cherche la tuile suivante non nulle
				{
					iColonne--;
				}
				if(plateau[iColonne][iLigne]==plateau[iSelec][iLigne] && iColonne>=0) //si les deux tuiles sont de même valeur
				{
					if(doitJouer)
					{
						plateau[iSelec][iLigne]++;		//on double la valeur de la tuile de réf
						plateau[iColonne][iLigne]=0;		//et on efface la deuxième tuile
					}
					(*nombreZeros)++;
					(*score)+=pow(2, plateau[iSelec][iLigne]+1);
					iSelec=iColonne-1;
					iColonne=iSelec-1;
					plateauModifie = TRUE;
				}
				else
				{
					iSelec=iColonne; 		//sinon, les valeurs ne changent pas, et la tuile non nulle suivante devient la tuile de référence
					iColonne=iSelec-1;
				}
			}
			else  //si la tuile de référence est nulle, on avance sans rien faire
			{
				iSelec--;
				iColonne--;
			}
		}

		/*
		 * 	Placement des nouvelles tuiles dans le plateau ("déplacement")	
		 */
		if(doitJouer)
		{
			for(iColonne=T_GRILLE-1; iColonne>=0; iColonne--)
			{
				if(plateau[iColonne][iLigne]!=0)
				{
					plateau[iPlace][iLigne]=plateau[iColonne][iLigne];
					iPlace--;
				}
			}
			while(iPlace>=0)
			{
				plateau[iPlace][iLigne]=0;
				iPlace--;
			}
		}
	}
	
	return plateauModifie;
}

BOOL fusion_totale_bas(int* nbZeros, int* score, BOOL doitJouer)
{
	BOOL plateauModifie = FALSE;
	
	do
	{
		/* plateauModifie = */ fusion_classique_bas(nbZeros, score, doitJouer);
		plateauModifie = fusion_classique_bas(NULL, NULL, doitJouer);
	}while(plateauModifie);
	
	return plateauModifie;		
}


choixBouton meilleurCoup()
{
	int score=0, max=0, joker=0; //joker sert à mettre quelquechose en paramètre à la place de nbZeros
	choixBouton meilleur;
	
	fusion_classique_haut(&joker, &score, False);
	max=score;
	meilleur=HAUT;
	score=0;
	
	fusion_classique_bas(&joker, &score, False);
	if(score>max)
	{
		max=score;
		meilleur=BAS;
	}
	score=0;
	
	fusion_classique_gauche(&joker, &score, False);
	if(score>max)
	{
		max=score;
		meilleur=GAUCHE;
	}
	score=0;
	
	fusion_classique_droite(&joker, &score, False);
	if(score>max)
	{
		max=score;
		meilleur=DROITE;
	}

	return meilleur;
}


void generer_nouvelle_tuile(modeDifficulte difficulte, int* nbZeros)
{
	if(difficulte == FACILE)
	{
			generer_nouvelle_tuile_facile(nbZeros);
	}
	else if(difficulte == DIFFICILE)
	{
			generer_nouvelle_tuile_difficile(nbZeros);
	}

	return;
}


void generer_nouvelle_tuile_facile(int* nbZeros) //En mode facile, on génère un 2 sur une case libre aléatoire sans risque de boucler indéfiniment
{
	int i = 0, j = 0, k = 0 /* Compteurs */, indice /* Indice de la case nulle à modifier */;

	if(*nbZeros > 0) //S'il y a au moins un zéro sur le plateau, on est sûr de ne pas boucler indéfiniment
	{
		indice = alea_int(*nbZeros);
		while(k <= indice)
		{
			j=0;
			while(k <= indice && j < T_GRILLE)
			{
				
				if(plateau[i][j]==0) //Dès qu'on a atteint la case à modifier...
				{                  
					if(k == indice)
					{                                     
						plateau[i][j] = alea_int(2)+1; //... on y insère un 2 ou un 4
						(*nbZeros)--; //Le nombre de cases vides diminue de 1
					}
					k++;
				}
				j++;
			   
			}
			i++;
		}
	}

	return;
}

void generer_nouvelle_tuile_difficile(int* nbZeros) //Place un 2 ou un 4 à côté du max ayant une case voisine libre
{
	int i, j, maxAccessible = 0 /* Le max le plus proche d'une casse vide */, iNouv = 0, jNouv = 0;	

	for(i = 0; i < T_GRILLE; i++) //On parcourt le plateau
	{
		for(j = 0; j < T_GRILLE; j++)
		{
			if(plateau[i][j] == 0) //Si on est sur une case vide
			{
				//On teste les cases alentour...
				if(i + 1 < T_GRILLE) //Sans sortir du plateau
				{
					if(plateau[i+1][j] > maxAccessible) //Si la case adjacente est un max local
					{
						maxAccessible = plateau[i+1][j];
						iNouv = i; //On stocke les coordonnées actuelles en vue d'y placer un 2 ou un 4
						jNouv = j;
					}
				}
				if(i - 1 >= 0) //Sans sortir du plateau
				{
					if(plateau[i-1][j] > maxAccessible) //Si la case adjacente est un max local
					{
						maxAccessible = plateau[i-1][j];
						iNouv = i; //On stocke les coordonnées actuelles en vue d'y placer un 2 ou un 4
						jNouv = j;
					}
				}
				if(j + 1 < T_GRILLE) //Sans sortir du plateau
				{
					if(plateau[i][j+1] > maxAccessible) //Si la case adjacente est un max local
					{
						maxAccessible = plateau[i][j+1];
						iNouv = i; //On stocke les coordonnées actuelles en vue d'y placer un 2 ou un 4
						jNouv = j;
					}
				}
				if(j - 1 >= 0) //Sans sortir du plateau
				{
					if(plateau[i][j-1] > maxAccessible) //Si la case adjacente est un max local
					{
						maxAccessible = plateau[i][j-1];
						iNouv = i; //On stocke les coordonnées actuelles en vue d'y placer un 2 ou un 4
						jNouv = j;
					}
				}
			}
		}
	}

	plateau[iNouv][jNouv] = alea_int(2) + 1; //On génère un 2 ou un 4
	(*nbZeros)--; //Le nombre global de cases nulles vient de baisser de 1

	return;
}
