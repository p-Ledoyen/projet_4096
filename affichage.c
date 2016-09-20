#include "4096.h"


void initInterfaces(t_interface *interface1, t_interface *interface2)
{
	interface1 -> epaisseur = 5;
	interface1 -> clr_grille = marron;
	interface1 -> palette = {{gris,blanc,jaune, coral, orange, darkorange, crimson, rouge, firebrick, vert, bleu, blueviolet, azure},{noir, noir, noir, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc}};

	interface2 -> epaisseur = 2;
	interface2 -> clr_grille = marron;
	interface2 -> palette = {{gris,blanc,jaune, coral, orange, darkorange, crimson, rouge, firebrick, vert, bleu, blueviolet, azure},{noir, noir, noir, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc}};
		
}




void afficheAccueil()
{
}

void afficheJeu()
{
	POINT P1, P2;
	
	
	P1.x = 50 ; P1.y = 50 ;
	P2.x = 850 ; P2.y = 850 ;
	draw_fill_rectangle(P1, P2, gris);
	
	
	afficheGrille();
}

void afficheGrille()
{
	POINT P1, P2;
	
	int i, pas=100, taille=8;
	
	P1.x = 50 ; P1.y = 50 ;
	P2.x = 850 ; P2.y = 850 ;
	draw_fill_rectangle(P1, P2, gris);
	
	for(i=50 ; i<=(taille+1)*pas ; i+=pas)
	{
		P1.x = i-5 ; P1.y = 50 ;
		P2.x = i+5 ; P2.y = 850 ;
		draw_fill_rectangle(P1, P2, beige);
		
		P1.x = 50 ; P1.y = i-5 ;
		P2.x = 850 ; P2.y = i+5 ;
		draw_fill_rectangle(P1, P2, beige);
	}
	
	affiche_all();	
}


void afficheTuile()
{
}
