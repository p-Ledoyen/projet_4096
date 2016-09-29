#include "4096.h"
#include "affichage.h"
#include "calculs.h"
#include "controle.h"


//compilations : ....:....:....:....:....:....:....:....:....:....:....:....:....:....:....:....:....:....:....:.


int main()
{
	
	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();
	
	int nbZeros=T_GRILLE*T_GRILLE;
	int score=0;
	BOOL aideActivee=0;
	
	initPlateau();
	
	afficheJeu();
	afficheScore(&score);
	affichePlateau();
	
	
	choixBouton boutonChoisi, boutonPropose;
	
	do
	{
		
		if(aideActivee)
		{
			score--;
			boutonPropose=meilleurCoup();
			
			switch(boutonPropose)
			{
				case HAUT:
					afficheBoutonHaut(True);
					break;
					
				case BAS:
					afficheBoutonBas(True);
					break;
				
				case GAUCHE:
					afficheBoutonGauche(True);
					break;
					
				case DROITE:
					afficheBoutonDroite(True);
					break;
			}
			affiche_all();
		}
			
		
		
		boutonChoisi=attendreSelection();
		
		switch(boutonChoisi)
		{
			case HAUT:
				versHaut(&nbZeros, &score, True);
				pop2F(&nbZeros);
				affichePlateau();
				break;
				
			case BAS:
				versBas(&nbZeros, &score, True);
				pop2F(&nbZeros);
				break;
				
			case GAUCHE:
				versGauche(&nbZeros, &score, True);
				pop2F(&nbZeros);
				break;
			
			case DROITE:
				versDroite(&nbZeros, &score, True);
				pop2F(&nbZeros);
				break;
				
			case AIDE:
				aideActivee=!aideActivee;
				afficheBoutonAide(aideActivee);
				afficheBoutonHaut(False);
				afficheBoutonBas(False);
				afficheBoutonGauche(False);
				afficheBoutonDroite(False);
				break;
			
			
			case QUITTER:
				break;
		}
		printf("aide %d\n", aideActivee);
		afficheScore(&score);
		affichePlateau();
		
		if(aideActivee)
		{
			afficheBoutonAide(aideActivee);
			afficheBoutonHaut(False);
			afficheBoutonBas(False);
			afficheBoutonGauche(False);
			afficheBoutonDroite(False);
		}
		
		
	}while(boutonChoisi!=QUITTER && nbZeros>0);
	
	
	
	return 0 ;
}
