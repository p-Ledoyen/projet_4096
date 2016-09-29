#include "affichage.h"

static COULEUR palette[2][13]={{0xC7B591,0xE2DDD3,0xC4B087, 0xFF8C61, 0xDE6D4D, 0xD94A3B, 0xDA2C14, 0xD7B95B, 0xDFB83F, 0xEEBD25, 0xFBC51E, 0xFFB300, noir},{0x4F4F4F, 0x4F4F4F, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc}};

/*
void afficheAccueil()
{
}
*/

 
/*
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
}*/

void afficheJeu()
{
	fill_screen(beige);
	
	POINT P1, P2;

	
	P1.x = 50 ; P1.y = 50 ;
	P2.x = 50+100*T_GRILLE ; P2.y = 50+100*T_GRILLE ;
	draw_fill_rectangle(P1, P2, 0x8D8068);
	
	afficheBoutonHaut();
	afficheBoutonBas();
	afficheBoutonDroite();
	afficheBoutonGauche();
	afficheBoutonAideOn();
	
	return;
}


void afficheBoutonHaut()
{
	POINT P, P1, P2, P3;
	
	P.x=L_FENETRE-180+3; P.y=H_FENETRE-220-3;
	draw_fill_circle(P, 41, 0x857242);
	
	P.x=L_FENETRE-180; P.y=H_FENETRE-220;
	draw_fill_circle(P, 40, 0xD6BE84);
	
	P1.x=P.x; P1.y=P.y+25;
	P2.x=P.x-20; P2.y=P.y-15;
	P3.x=P.x+20; P3.y=P.y-15;
	
	draw_fill_triangle(P1, P2, P3, blanc);
	
	return;
}

void afficheBoutonBas()
{
	POINT P, P1, P2, P3;
	
	P.x=L_FENETRE-180+3; P.y=H_FENETRE-380-3;
	draw_fill_circle(P, 41, 0x857242);
	
	P.x=L_FENETRE-180; P.y=H_FENETRE-380;
	draw_fill_circle(P, 40, 0xD6BE84);
	
	P1.x=P.x; P1.y=P.y-25;
	P2.x=P.x-20; P2.y=P.y+15;
	P3.x=P.x+20; P3.y=P.y+15;
	
	draw_fill_triangle(P1, P2, P3, blanc);
	
	return;
}


void afficheBoutonDroite()
{
	POINT P, P1, P2, P3;
	
	P.x=L_FENETRE-100+3; P.y=H_FENETRE-300-3;
	draw_fill_circle(P, 41, 0x857242);
	
	P.x=L_FENETRE-100; P.y=H_FENETRE-300;
	draw_fill_circle(P, 40, 0xD6BE84);
	
	P1.x=P.x+25; P1.y=P.y;
	P2.x=P.x-15; P2.y=P.y+20;
	P3.x=P.x-15; P3.y=P.y-20;
	
	draw_fill_triangle(P1, P2, P3, blanc);
	
	return;
}

void afficheBoutonGauche()
{
	POINT P, P1, P2, P3;
	
	P.x=L_FENETRE-260+3; P.y=H_FENETRE-300-3;
	draw_fill_circle(P, 41, 0x857242);
	
	P.x=L_FENETRE-260; P.y=H_FENETRE-300;
	draw_fill_circle(P, 40, 0xD6BE84);
	
	P1.x=P.x-25; P1.y=P.y;
	P2.x=P.x+15; P2.y=P.y+20;
	P3.x=P.x+15; P3.y=P.y-20;
	
	draw_fill_triangle(P1, P2, P3, blanc);
	
	return;
}


void afficheBoutonAideOff()
{
	effacerBoutonAide();
	
	POINT P1, P2;
	
	P1.x=L_FENETRE-200; P1.y=H_FENETRE-585;
	P2.x=L_FENETRE-160; P2.y=H_FENETRE-615;
	draw_fill_rectangle(P1, P2, gris);
	
	P1.y=P1.y-15;
	P2.y=P2.y+15;
	draw_fill_circle(P1, 18, lightgrey);
	draw_circle(P1, 18, rouge);
	draw_fill_circle(P2, 15, gris);
	
	return;
}
	
void afficheBoutonAideOn()
{
	effacerBoutonAide();
	
	POINT P1, P2;
	
	P1.x=L_FENETRE-200; P1.y=H_FENETRE-585;
	P2.x=L_FENETRE-160; P2.y=H_FENETRE-615;
	draw_fill_rectangle(P1, P2, gris);
	
	P1.y=P1.y-15;
	P2.y=P2.y+15;
	draw_fill_circle(P2, 18, lightgrey);
	draw_circle(P2, 18, vert);
	draw_fill_circle(P1, 15, gris);
	
	return;
}

void effacerBoutonAide()
{
	POINT P1, P2;
	P1.x=L_FENETRE-200-18; P1.y=H_FENETRE-585+3;
	P2.x=L_FENETRE-160+18; P2.y=H_FENETRE-615-3;
	draw_fill_rectangle(P1,P2, beige);

}


/* AFFICHE GRILLE -- A GARDER POUR L'INSTANT
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
				
			if(plateau[i][j]!=0)
			{
				pt1.y=100*(j+1)+20;
				
				if(plateau[i][j]<4)
				{
					pt1.x=50+2*rayon+100*i+24;
				}
				else if(plateau[i][j]<7)
				{
					pt1.x=50+2*rayon+100*i+15;
				}
				else if(plateau[i][j]<10)
				{
					pt1.x=50+2*rayon+100*i+7;
				}
				else
				{
					pt1.x=50+2*rayon+100*i;
				}
				
				aff_int(pow(2,plateau[i][j]), 28, pt1, palette[1][plateau[i][j]]); 
			}	
			
			
		}
		
	}
	affiche_all();
	return;
}
