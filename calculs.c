#include "calculs.h"



void initPlateau()
{
	int i,j;
	
	for(i=0; i<T_GRILLE; i++)
	{
		for(j=0; j<T_GRILLE; j++)
		{
			ajouterTuile(0, i, j);
		}
	}
	return;
}

void ajouterTuile(int puiss, int i, int j)
{
	plateau[i][j]=puiss;
	return;
}
	
	
void initJeu(t_bouton* clavier)
{
	t_bouton bt_haut, bt_bas, bt_gauche, bt_droite,bt_aideOn, bt_aideOff, bt_quitter;
	
	bt_haut.texte="H";
	bt_haut.nom=HAUT;
	bt_haut.pt_hg.x= 975; bt_haut.pt_hg.y= 750;
	bt_haut.pt_bd.x= 1075; bt_haut.pt_bd.y= 650;
	bt_haut.clr_fond=gris;
	bt_haut.clr_texte=blanc;
	bt_haut.t_texte=50;
	
	bt_bas.texte="B";
	bt_bas.nom=BAS;
	bt_bas.pt_hg.x= 975; bt_bas.pt_hg.y= 550;
	bt_bas.pt_bd.x= 1075; bt_bas.pt_bd.y= 450;
	bt_bas.clr_fond=gris;
	bt_bas.clr_texte=blanc;
	bt_bas.t_texte=50;
	
	bt_gauche.texte="G";
	bt_gauche.nom=GAUCHE;
	bt_gauche.pt_hg.x= 875; bt_gauche.pt_hg.y= 650;
	bt_gauche.pt_bd.x= 975; bt_gauche.pt_bd.y= 550;
	bt_gauche.clr_fond=gris;
	bt_gauche.clr_texte=blanc;
	bt_gauche.t_texte=50;
	
	bt_droite.texte="D";
	bt_droite.nom=DROITE;
	bt_droite.pt_hg.x= 1075; bt_droite.pt_hg.y= 650;
	bt_droite.pt_bd.x= 1175; bt_droite.pt_bd.y= 550;
	bt_droite.clr_fond=gris;
	bt_droite.clr_texte=blanc;
	bt_droite.t_texte=50;
	
	bt_aideOn.texte="On";
	bt_aideOn.nom=AIDE;
	bt_aideOn.pt_hg.x= 1025-64; bt_aideOn.pt_hg.y=300;
	bt_aideOn.pt_bd.x= 1025; bt_aideOn.pt_bd.y= 300-64;
	bt_aideOn.clr_fond=gris;
	bt_aideOn.clr_texte=blanc;
	bt_aideOn.t_texte=15;
	
	bt_aideOff.texte="Off";
	bt_aideOff.nom=AIDE;
	bt_aideOff.pt_hg.x= 1025; bt_aideOff.pt_hg.y= 300;
	bt_aideOff.pt_bd.x= 1025+64; bt_aideOff.pt_bd.y= 300-64;
	bt_aideOff.clr_fond=gris;
	bt_aideOff.clr_texte=blanc;
	bt_aideOff.t_texte=15;
	
	bt_quitter.texte="Quitter";
	bt_quitter.nom=QUITTER;
	bt_quitter.pt_hg.x= 1025-64; bt_quitter.pt_hg.y= 300-64-20;
	bt_quitter.pt_bd.x= 1025+64; bt_quitter.pt_bd.y= 300-64-20-64;
	bt_quitter.clr_fond=gris;
	bt_quitter.clr_texte=blanc;
	bt_quitter.t_texte=15;
	
	clavier[0]=bt_haut;
	clavier[1]=bt_bas;
	clavier[2]=bt_gauche;
	clavier[3]=bt_droite;
	clavier[4]=bt_aideOn;
	clavier[5]=bt_aideOff;
	clavier[6]=bt_quitter;


	
}

// FONCTION D'AJOUT DE TUILE EN MODE FACILE //
void generer_2_facile(int* nbZeros)
//En mode facile, on génère un 2 sur une case libre aléatoire sans risque de boulcer indéfiniment
{
        unsigned int i = 0, j = 0, k = 0, occurrence = alea_int(*nbZeros)/* Indice de la case nulle à modifier */;

        while(k != occurrence && k < T_GRILLE * T_GRILLE) //Tant qu'il reste des cases à parcourir
        {
                if(k == occurrence) //Si on a atteint l'indice de la case à modifier
                {
                        plateau[i][j] = 1; //On y insère un 2
                        (*nbZeros)--; //La nombre de cases vides diminue de 1
                }
                else //Autrement, 
                {
                        k++;
                }
                i++;
                i %= 8; //On ne doit pas sortir du plateau
                j++;
                j %= 8;
        }

        return;
}

int pop2F(int *nombreZeros)
{
	int i,j;
	
	do
	{
		i=alea_int(T_GRILLE);
		j=alea_int(T_GRILLE);
	}while(plateau[i][j]!=0);
	
	plateau[i][j]=1;
	(*nombreZeros)--;
	
	return 0;
}

//////////////////////////////////////////////

// FONCTIONS DE DEPLACEMENT EN MODE FUSION CLASSIQUE //

int versBas(int *nombreZeros)
{
	/*
	 *   TO DO : retourner le score
	 */
	
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
					plateau[iColonne][iSelec]++;		//on double la valeur de la tuile de réf
					plateau[iColonne][iLigne]=0;		//et on efface la deuxième tuile
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
	
	return 0;		
}


int versHaut(int *nombreZeros)
{
	/*
	 *   TO DO : retourner le score
	 */
	
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
					plateau[iColonne][iSelec]++;		//on double la valeur de la tuile de réf
					plateau[iColonne][iLigne]=0;		//et on efface la deuxième tuile
					(*nombreZeros)++;
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
	
	return 0;	
}


int versGauche(int *nombreZeros)
{
	/*
	 *   TO DO : retourner le score
	 */
	
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
					plateau[iSelec][iLigne]++;		//on double la valeur de la tuile de réf
					plateau[iColonne][iLigne]=0;		//et on efface la deuxième tuile
					(*nombreZeros)++;
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
	
	return 0;	
}


int versDroite(int *nombreZeros)
{
	/*
	 *   TO DO : retourner le score
	 */
	
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
					plateau[iSelec][iLigne]++;		//on double la valeur de la tuile de réf
					plateau[iColonne][iLigne]=0;		//et on efface la deuxième tuile
					(*nombreZeros)++;
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
	
	return 0;		
}

///////////////////////////////////////////////////////
