#include "4096.h"
#include "affichage.h"
#include "calculs.h"
#include "controle.h"


//compilations : ....:....:....:....:....:....:....:....:...


int main()
{
	
	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();
	
	int nbZeros=T_GRILLE*T_GRILLE;

	afficheJeu();
	
	initPlateau();

	affichePlateau();

	
	choixBouton boutonChoisi;
	
	do
	{
		printf("%d\n",nbZeros);
		
		boutonChoisi=attendreSelection();
		
		switch(boutonChoisi)
		{
			case HAUT:
				versHaut(&nbZeros);
				pop2F(&nbZeros);
				affichePlateau();
				break;
				
			case BAS:
				versBas(&nbZeros);
				pop2F(&nbZeros);
				break;
				
			case GAUCHE:
				versGauche(&nbZeros);
				pop2F(&nbZeros);
				break;
			
			case DROITE:
				versDroite(&nbZeros);
				pop2F(&nbZeros);
				break;
				
			case AIDE:
				
				break;
			
			
			case QUITTER:
				break;
		}
	

		affichePlateau();
	}while(boutonChoisi!=QUITTER && nbZeros>0);
	
	
	
	return 0 ;
}
