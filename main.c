#include "4096.h"
#include "affichage.h"
#include "calculs.h"
#include "controle.h"

//compilations : ....:....:....:....:....:....:....:....:....:....|....:....:....:....:....:....:....:....:....:....|
//               ....:....:....:....:....:....:....:....:....:....|....:....:....:....:....:....:....:....:....:....|
//				 ....:....:....:....:....:....:....:....:....:....|....:....:....:....:....:....:....:....:....:....|
//				 ....:...

int main()
{
	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();

	int score=0, nbZeros=T_GRILLE*T_GRILLE;
	BOOL aideActivee=False, start=False, finDePartie=False;
	choixBouton boutonChoisi, boutonPropose;
	modeDifficulte difficulte = FACILE;
	modeAffichage affichage = AFF0;
	modeFusion fusion = CLASSIQUE;
	
	affiche_accueil(difficulte, affichage, fusion);
	do
	{	
		boutonChoisi=attendre_parametres();
		if(boutonChoisi==START) start=TRUE;
		else changer_parametres(boutonChoisi, &difficulte, &affichage, &fusion);
		affiche_accueil(difficulte, affichage, fusion);
	}while(!start);
	
	initalise_plateau(&nbZeros);
	affiche_jeu();
	affiche_score(score);
	affiche_plateau(affichage);

	do
	{
		if(aideActivee)
		{
			score--;
			boutonPropose=meilleur_coup();
			affiche_bouton_propose(boutonPropose);
		}
		boutonChoisi=attendre_selection(); //fonction bloquante attendant un clic sur un bouton
		if(boutonChoisi==AIDE)
		{
			aideActivee=!aideActivee;
			affiche_bouton_Aide(aideActivee);
		}
		else if(boutonChoisi==QUITTER) finDePartie=True;
		else
		{
			deplacer_vers(boutonChoisi, fusion, &nbZeros, &score);
			generer_nouvelle_tuile(difficulte, &nbZeros);
		}
		affiche_score(score);
		affiche_plateau(affichage);
		efface_bouton_propose();
		if(a_gagne())
		{
			affiche_gagne();
			finDePartie=True;
			wait_clic();
		}
		else if(a_perdu(&nbZeros))
		{
			affiche_perdu();
			finDePartie=True;
			wait_clic();
		}
	}while(!finDePartie);
	
	
	return 0 ;
}
