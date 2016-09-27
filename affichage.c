#include "affichage.h"

static COULEUR palette[2][13]={{0xC7B591,blanc,jaune, coral, orange, darkorange, crimson, rouge, firebrick, vert, bleu, blueviolet, azure},{noir, noir, noir, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc}};


/*
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
*/

void afficheJeu(t_bouton* clavier)
{
	
	fill_screen(beige);
	
	POINT P1, P2;
	int i;
	
	P1.x = 50 ; P1.y = 50 ;
	P2.x = 850 ; P2.y = 850 ;
	draw_fill_rectangle(P1, P2, 0x8D8068);
	//afficheGrille();
	
	for(i=0 ; i<7; i++)
	{
		afficheBouton(clavier[i]);
	}
	
	return;
}

/*
void afficheGrille()
{
	POINT P1, P2;
	
	int i, pas=100, taille=8, epaisseur=4;
	
	for(i=50 ; i<=(taille+1)*pas ; i+=pas)
	{
		P1.x = i-epaisseur; P1.y = 50 ;
		P2.x = i+epaisseur ; P2.y = 850 ;
		draw_fill_rectangle(P1, P2, 0xA29376);
		
		P1.x = 50 ; P1.y = i-epaisseur ;
		P2.x = 850 ; P2.y = i+epaisseur ;
		draw_fill_rectangle(P1, P2, 0xA29376);
	}
	
	affiche_all();	
	return;
}*/

void afficheBouton(t_bouton bouton)
{
	draw_fill_rectangle(bouton.pt_hg, bouton.pt_bd, bouton.clr_fond);
	POINT P;
	P.x=bouton.pt_hg.x+30;
	P.y=bouton.pt_hg.y-20;
	aff_pol(bouton.texte, bouton.t_texte, P, bouton.clr_texte);
	
	return;
}




void affichePlateau()
{
	int i, j;
	
	for(i=0; i<T_GRILLE; i++)
	{
		for(j=0; j<T_GRILLE; j++)
		{
			
			POINT pt1, pt2;
			int rayon = 8;
			
			pt1.x=50+2*rayon+100*i     ; pt1.y=50-2*rayon+100*(j+1) ;
			pt2.x=50-2*rayon+100*(i+1) ; pt2.y=50+2*rayon+100*j     ;
		
			draw_fill_rectangle(pt1, pt2, palette[0][plateau[i][j]]);
			
			if(plateau[i][j]!=0)
			{
				aff_int(pow(2,plateau[i][j]), 27, pt1, palette[1][plateau[i][j]]); 
			}	
			
			
			
			draw_fill_circle(pt1, rayon, palette[0][plateau[i][j]]);
			draw_fill_circle(pt2, rayon, palette[0][plateau[i][j]]);
			
			pt2.y=50-rayon+100*(j+1);
			draw_fill_rectangle(pt1, pt2, palette[0][plateau[i][j]]);
			
			pt1.x=50-2*rayon+100*(i+1);
			pt2.x=50-rayon+100*(i+1); pt2.y=50+2*rayon+100*j;
			
			draw_fill_rectangle(pt1, pt2, palette[0][plateau[i][j]]);
			draw_fill_circle(pt1, rayon, palette[0][plateau[i][j]]);
			
			pt2.x=50+2*rayon+100*i;
			pt1.y=50+rayon+100*j;
			
			draw_fill_rectangle(pt1, pt2, palette[0][plateau[i][j]]);
			draw_fill_circle(pt2, rayon, palette[0][plateau[i][j]]);
			
			pt1.x=50+rayon+100*i     ; pt1.y=50-2*rayon+100*(j+1) ;
			draw_fill_rectangle(pt1, pt2, palette[0][plateau[i][j]]);
				
			
			
			
		}
		
	}
	affiche_all();
	return;
}
