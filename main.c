#include "4096.h"
#include "affichage.h"
#include "calculs.h"
#include "controle.h"


//compilations : ....:....:....:....:....:....:....:....:....:....|....:....:....:....:....:....:....:....:....:....|
//               ....:....:....:....:....:....:....:....:....:....|....:....:...


int main()
{
	
	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();
	
	int nbZeros=T_GRILLE*T_GRILLE;
	int score=0;
	BOOL aideActivee=False, start=False;
	choixBouton boutonChoisi, boutonPropose;
	modeDifficulte difficulte = FACILE;
	modeAffichage affichage = AFF0;
	modeFusion fusion = CLASSIQUE;
	
	afficheAccueil(difficulte, affichage, fusion);
	do
	{	
		boutonChoisi=attendreParametres();
		if(boutonChoisi==START) start=TRUE;
		else changerParametres(boutonChoisi, &difficulte, &affichage, &fusion);
		afficheAccueil(difficulte, affichage, fusion);
	}while(!start);
	
	initPlateau(&nbZeros);
	afficheJeu();
	afficheScore(score);
	affichePlateau(affichage);

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
		boutonChoisi=attendreSelection(); //fonction bloquante attendant un clic sur un bouton
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
		affichePlateau(affichage);
		afficheBoutonHaut(False);
		afficheBoutonBas(False);
		afficheBoutonGauche(False);
		afficheBoutonDroite(False);
		
		
	}while(boutonChoisi!=QUITTER && nbZeros>0);
	
	
	
	return 0 ;
}
