#include "4096.h"
#include "affichage.h"
#include "calculs.h"
#include "controle.h"


//compilations : ....:....:....:....:....:....:....:....:....:....|....:....:....:....:....:....:....:....:....:....||....:....:....:....:....:....:...


int main()
{
	
	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();
	
	int nbZeros=T_GRILLE*T_GRILLE;
	int score=0;
	BOOL aideActivee=False;
	choixBouton boutonChoisi, boutonPropose;
	modeDifficulte difficulte = FACILE;
	initPlateau(&nbZeros);
	
	afficheJeu();
	afficheScore(score);
	affichePlateau();

	do
	{
		if(aideActivee)
		{
			score--;
			boutonPropose=meilleurCoup();

			switch(boutonPropose) // sortir du main
			{
				case HAUT:	afficheBoutonHaut(True);	break;
				case BAS:	afficheBoutonBas(True);		break;
				case GAUCHE:afficheBoutonGauche(True);	break;
				case DROITE:afficheBoutonDroite(True);	break;
				default:	break;
			}
			affiche_all();
		}
		boutonChoisi=attendreSelection();
		switch(boutonChoisi)
		{
			case HAUT:
				versHaut(&nbZeros, &score, True);
				generer_2(difficulte, &nbZeros);
				break;
				
			case BAS:
				versBas(&nbZeros, &score, True);
				generer_2(difficulte, &nbZeros);
				break;
				
			case GAUCHE:
				versGauche(&nbZeros, &score, True);
				generer_2(difficulte, &nbZeros);
				break;
			
			case DROITE:
				versDroite(&nbZeros, &score, True);
				generer_2(difficulte, &nbZeros);
				break;
				
			case AIDE:
				aideActivee=!aideActivee;
				afficheBoutonAide(aideActivee);
				break;
			
			case QUITTER:
				break;
		}
		afficheScore(score);
		affichePlateau();
		afficheBoutonHaut(False);
		afficheBoutonBas(False);
		afficheBoutonGauche(False);
		afficheBoutonDroite(False);
		
		
	}while(boutonChoisi!=QUITTER && nbZeros>0);
	
	
	
	return 0 ;
}
