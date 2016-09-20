#include "affichage.h"

int main()
{
	init_graphics(1200,900);
	affiche_auto_off();
	
	POINT P1, P2;
	
	
	P1.x = 50 ; P1.y = 50 ;
	P2.x = 850 ; P2.y = 850 ;
	draw_fill_rectangle(P1, P2, gris);
	
	
	afficheGrille();
	
	
	
	
	
	wait_escape();
	return(0);
}
