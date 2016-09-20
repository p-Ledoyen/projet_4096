#include "4096.h"
#include "affichage.h"


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
