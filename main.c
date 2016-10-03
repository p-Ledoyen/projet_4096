#include "4096.h"
#include "affichage.h"
#include "calculs.h"
#include "controle.h"


//compilations : .......


int main()
{
	init_graphics(L_FENETRE, H_FENETRE);
	affiche_auto_off();
	
	int nbZeros=T_GRILLE*T_GRILLE;
	int score=0;
	BOOL aideActivee=False, plateauModifie = FALSE;
	choixBouton boutonChoisi, boutonPropose;
	modeDifficulte difficulte = FACILE;
	
	//afficheAccueil();
	
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
		
		plateauModifie = FALSE;
		boutonChoisi=attendreSelection();
		switch(boutonChoisi)
		{
			case HAUT:
				plateauModifie = fusion_classique_haut(&nbZeros, &score, True);
				if(plateauModifie)
					generer_nouvelle_tuile(difficulte, &nbZeros);
				break;
				
			case BAS:
				plateauModifie = fusion_classique_bas(&nbZeros, &score, True);
				if(plateauModifie)
					generer_nouvelle_tuile(difficulte, &nbZeros);
				break;
				
			case GAUCHE:
				plateauModifie = fusion_classique_gauche(&nbZeros, &score, True);
				if(plateauModifie)
					generer_nouvelle_tuile(difficulte, &nbZeros);
				break;
			
			case DROITE:
				plateauModifie = fusion_classique_droite(&nbZeros, &score, True);
				if(plateauModifie)
					generer_nouvelle_tuile(difficulte, &nbZeros);
				break;
				
			case AIDE:
				aideActivee =! aideActivee;
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
		
		
	}while(boutonChoisi != QUITTER && nbZeros>0 /* && score actuel est le meilleur score */);

	return 0 ;
}
