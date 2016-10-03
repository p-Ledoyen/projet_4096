#include "calculs.h"



void initalise_plateau(int *nombreZeros)
{
	int i,j;
	
	for(i=0; i<T_GRILLE; i++)
	{
		for(j=0; j<T_GRILLE; j++)
		{
			plateau[i][j]=i+1;
		}
	}
	generer_nouvelle_tuile(FACILE, nombreZeros);
	generer_nouvelle_tuile(FACILE, nombreZeros);
	return;
}

void deplacer_vers(choixBouton boutonChoisi, modeDifficulte difficulte, int *nbZeros, int *score)
{
	if(difficulte==FACILE)
	{
		switch(boutonChoisi)
		{
			case HAUT:	versHaut(nbZeros, score, True);	break;
			case BAS:	versBas(nbZeros, score, True);	break;
			case GAUCHE:versGauche(nbZeros, score, True);	break;
			case DROITE:versDroite(nbZeros, score, True);	break;
			default:break;
		}
	}
}

// FONCTIONS DE DEPLACEMENT EN MODE FUSION CLASSIQUE //

int versBas(int *nombreZeros, int *score, BOOL doitJouer)
{
	int iColonne, iLigne, iPlace, iSelec;
	/*
	 * 	Calculs des sommes 
	 */
	for(iColonne=0; iColonne<T_GRILLE; iColonne++)  //on parcourt toutes les colonnes
	{
		iSelec=0;		//indice de tuile de référence
		iLigne=1; 		//indice de tuile de parcours des lignes
		iPlace=0;		//indice de la case suivante à remplir
	
		while(iSelec<T_GRILLE && iLigne<T_GRILLE)	//tant que l'on est bien dans la colonne
		{
			if(plateau[iColonne][iSelec]!=0)	//si la tuile de référence est non nulle
			{
				while(plateau[iColonne][iLigne]==0 && iLigne<T_GRILLE) //on cherche la tuile suivante non nulle
				{
					iLigne++;
				}				
				if(plateau[iColonne][iLigne]==plateau[iColonne][iSelec] && iLigne<T_GRILLE) //si les deux tuiles sont de même valeur
				{
					if(doitJouer)
					{
						plateau[iColonne][iSelec]++;		//on double la valeur de la tuile de réf
						plateau[iColonne][iLigne]=0;		//et on efface la deuxième tuile
					}
					(*score)+=pow(2, plateau[iColonne][iSelec]+1);
					(*nombreZeros)++;
					iSelec=iLigne+1;
					iLigne=iSelec+1;
				}
				else
				{
					iSelec=iLigne; 		//sinon, les valeurs ne changent pas, et la tuile non nulle suivante devient la tuile de référence
					iLigne=iSelec+1;
				}
			}	
			else  //si la tuile de référence est nulle, on avance sans rien faire
			{
				iSelec++;
				iLigne++;
			}
		}
		/*
		 * 	Placement des nouvelles tuiles dans le plateau ("déplacement")	
		 */
		if(doitJouer)
		{
			for(iLigne=0; iLigne<T_GRILLE; iLigne++)
			{
				if(plateau[iColonne][iLigne]!=0)
				{
					plateau[iColonne][iPlace]=plateau[iColonne][iLigne];
					iPlace++;
				}
			}
			while(iPlace<T_GRILLE)
			{
				plateau[iColonne][iPlace]=0;
				iPlace++;
			}
		}
	}
	return 0;		
}


int versHaut(int *nombreZeros, int *score, BOOL doitJouer)
{
	int iColonne, iLigne, iPlace, iSelec;
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
				}
			}
			while(iPlace>=0)
			{
				plateau[iColonne][iPlace]=0;
				iPlace--;
			}
		}
	}
	return 0;	
}


int versGauche(int *nombreZeros, int *score, BOOL doitJouer)
{
	int iColonne, iLigne, iPlace, iSelec;
	
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
	return 0;	
}


int versDroite(int *nombreZeros, int *score, BOOL doitJouer)
{
	int iColonne, iLigne, iPlace, iSelec;
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
	return 0;		
}

///////////////////////////////////////////////////////



choixBouton meilleur_coup()
{
	int score=0, max=0, joker=0; //joker sert à mettre quelquechose en paramètre à la place de nbZeros
	choixBouton meilleur;
	
	versHaut(&joker, &score, False);
	max=score;
	meilleur=HAUT;
	score=0;
	
	versBas(&joker, &score, False);
	if(score>max)
	{
		max=score;
		meilleur=BAS;
	}
	score=0;
	
	versGauche(&joker, &score, False);
	if(score>max)
	{
		max=score;
		meilleur=GAUCHE;
	}
	score=0;
	
	versDroite(&joker, &score, False);
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


void generer_nouvelle_tuile_facile(int* nbZeros) //En mode facile, on g\303\251n\303\250re un 2 sur une case libre al\303\251atoire sans risque de boulcer ind\303\251finiment
{
        int i = 0, j = 0, k = 0, indice /* Indice de la case nulle \303\240 modifier */;

        if(*nbZeros > 0) //S'il y a au moins un zéro sur le plateau, on est s\303\273r de ne pas boucler ind\303\251finiment
        {
                indice = alea_int(*nbZeros);
                while(k <= indice)
                {
                		j=0;
                        while(k <= indice && j<T_GRILLE)
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

void generer_nouvelle_tuile_difficile(int* nbZeros) //Place un 2 ou un 4 \303\240 c\303\264t\303\251 du max ayant une case voisine libre
{
        int i, j, maxAccessible = 0 /* Le max le plus proche d'une casse vide */, iNouv = T_GRILLE - 1, jNouv = T_GRILLE - 1;

        for(i = 0; i < T_GRILLE; i++)
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
                                                iNouv = i; //On stocke les coordonn\303\251es actuelles en vue d'y placer un 2 ou un 4
                                                jNouv = j;
                                        }
                                }
                                if(i - 1 < T_GRILLE) //Sans sortir du plateau
                                {
                                        if(plateau[i-1][j] > maxAccessible) //Si la case adjacente est un max local
                                        {
                                                iNouv = i; //On stocke les coordonn\303\251es actuelles en vue d'y placer un 2 ou un 4
                                                jNouv = j;
                                        }
                                }
                                if(j + 1 < T_GRILLE) //Sans sortir du plateau
                                {
                                        if(plateau[i][j+1] > maxAccessible) //Si la case adjacente est un max local
                                        {
                                                iNouv = i; //On stocke les coordonn\303\251es actuelles en vue d'y placer un 2 ou un 4
                                                jNouv = j;
                                        }
                                }
                                if(j - 1 < T_GRILLE) //Sans sortir du plateau
                                {
                                        if(plateau[i][j-1] > maxAccessible) //Si la case adjacente est un max local
                                        {
                                                iNouv = i; //On stocke les coordonn\303\251es actuelles en vue d'y placer un 2 ou un 4
                                                jNouv = j;
                                        }
                                }
                        }
                }
        }
        plateau[iNouv][jNouv] = alea_int(3); //On g\303\251n\303\250re un 2 ou un 4
        (*nbZeros)--; //Le nombre globasl de cases nulles vient de baisser de 1

        return;
}


BOOL a_gagne()
{
	BOOL trouve4096=False;
	int i=0, j=0;
	while(i<T_GRILLE && !trouve4096)
	{
		j=0;
		while(j<T_GRILLE && !trouve4096)
		{
			printf("i %d, j%d\n",i,j);
			if(plateau[i][j]==12) trouve4096=True;
			j++;
		}
		i++;
	}
	return trouve4096;	
}

BOOL a_perdu(int *nbZeros)
{
	int joker=0;
	if(*nbZeros==0)
	{
		versDroite(nbZeros, &joker, False);
		versGauche(nbZeros, &joker, False);
		versHaut(nbZeros, &joker, False);
		versBas(nbZeros, &joker, False);
		if(*nbZeros==0) return True;
		else *nbZeros=0;
	}
	return False;
}
