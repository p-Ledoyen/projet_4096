

#include "4096.h"
#include "affichage.h"
#include "calculs.h"
#include "controle.h"





int main()
{
	
	init_graphics(1200,900);
	affiche_auto_off();
	
	
	


	t_bouton clavierTest[6];//
	
	initJeu(clavierTest);

	afficheJeu();

	initPlateau();

	affichePlateau();
	affiche_all();
	
	choixBouton boutonChoisi;
	
	do
	{
		boutonChoisi=attendreSelection(clavierTest);
		
		switch(boutonChoisi)
		{
			case HAUT:
				pop2F();
				printf("haut\n");
				break;
				
			case BAS:
				pop2F();
				printf("bas\n");
				break;
				
			case GAUCHE:
				pop2F();
				break;
			
			case DROITE:
				pop2F();
				break;
				
			case AIDE_ON:
				
				break;
			
			case AIDE_OFF:
				
				break;
			
			case QUITTER:
				break;
		}
		affichePlateau();
	}while(boutonChoisi!=QUITTER);
	
	

	
	
	
	
	
	/*
	int score;
	t_bouton clavier[8];
	bouton choix;
	bool start=False, doitAider=False;
	
	t_interface interface1, interface2, choixInterface;
	initInterfaces(&interface1, &interface2);
	
	modeFusion choixFusion;
	
	int difficulte;
	
	
	initAccueil(&clavier); //creer boutons, les stocker dans un tableau 
	afficheAccueil(clavier); //fct A
	//attendreParametres(clavier); //fct Co  prend en param le tableau de boutons
	while(!start)
	{
		choix=attendreBouton();
		
		switch(choix.nom)
		{
			case "MODE_AFF_1":
				choixInterface=interface1;
				break;
				
			case "MODE_AFF_2":
				choixInterface=interface2;
				break;
				
			case "FACILE":
				difficulte=0;
				break;
				
			case "DIFFICILE":
				difficulte=1;
				break;
				
			case "FU_CLASSIQUE":
				choixFusion=CLASSIQUE;
			
			case "FU_TOTALE":
				choixFusion=TOTALE;
			
			case "START":
				start=True;
				break;
				
			//case QUITTER:
			//	exit(0);
		}
	}
	
	afficheJeu(); //fct A
    
    initPlateau(&clavier); //fct Ca
    affichePlateau(clavier); //fct A
    
    while(!estFini()) //estFini() teste si il n'y a pas 4096 qqpart, ou si aucun mouvement n'est possible (plateau plein et pas de chgt de score pour tout mouvement)
    {
    	if(doitAider)
		{
			majScore(&score, -1); //fct Ca
			afficheAide();
		}
    	
    	choix=attendreBouton(); //fct Co
		
		pointsGagnes=0;
		    
    	switch(choix)
    	{
        	case AIDE :
            	doitAider = !doitAider;
            	break;
          
			case HAUT :
				points=versHaut(); //fct Ca
				break;
				
			case DROITE :
				points=versDroite(); //fct Ca
				break;
				
			case BAS :
				points=versBas(); //fct Ca
				break;
				
			case GAUCHE:
				points=versGauche(); //fct Ca
				break;
			
		}
		
		majScore(&score, pointsGagnes);
		affichePlateau();
		
		
		
	
	}
	
	
	*/
	
	return 0 ;
}
