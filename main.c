#include "4096.h"
#include "affichage.h"
#include "calculs.h"
#include "controle.h"


int main()
{

	init_graphics(1200,900);
	affiche_auto_off();	
	
	t_interface interfaceTest;
	interfaceTest.epaisseur = 5;
	interfaceTest.clr_grille = marron;
	int i;//
	//interfaceTest.palette[2][13]={{gris,blanc,jaune, coral, orange, darkorange, crimson, rouge, firebrick, vert, bleu, blueviolet, azure},{noir, noir, noir, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc}};
	for(i=0; i<2; i++)
	{
		
		interfaceTest.palette[0][i]=rouge;
		interfaceTest.palette[1][i]=blanc;
		
	}
	
	//COULEUR paletteTest[2][13]={{gris,blanc,jaune, coral, orange, darkorange, crimson, rouge, firebrick, vert, bleu, blueviolet, azure},{noir, noir, noir, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc}};
	
	afficheJeu();
	initPlateau(interfaceTest);
	affichePlateau();
	affiche_all();
	
	wait_escape();
	
	
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
