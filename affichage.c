#include "affichage.h"

/*
	palette[nombre de modes d'affichage][couleurs fond de tuile + couleurs texte tuile][couleurs pour chaque valeur]
*/
static COULEUR palette[2][2][13]={{{0xCEBFB6,0xF2E3DA,0xECE0C8, 0xF2B179, 0xF59563, 0xF55E3C, 0xF75E3C, 0xEDCE72, 0xECCB61, 0xEDC750, 0xEDC440, 0xECC12E, 0xFF3D3D},
								{0x776E65, 0x776E65, 0x776E65, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc}},
							   {{0x7F7F7F,0x00FF00,0x1E90FF, 0xA020F0, 0xADD8E6, 0xE6E6FA, 0xBFBFBF, 0x4DB430, 0xFF0000, 0xFFC0CB, 0x1E89FB, 0xDDA45D, noir},
							    {0x4F4F4F, 0x4F4F4F, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc, blanc}}};



void affiche_jeu()
{
	fill_screen(beige);
	
	POINT P1, P2,
		  P4096 ={L_FENETRE-280, H_FENETRE-50},
		  Pscore={L_FENETRE-320, H_FENETRE-500},
		  Paide ={L_FENETRE-295, H_FENETRE-570};

	
	P1.x = 50 ; P1.y = 50 ;
	P2.x = 50+100*T_GRILLE ; P2.y = 50+100*T_GRILLE ;
	draw_fill_rectangle(P1, P2, 0xBBAD9F);
	
	affiche_bouton_Haut(False);
	affiche_bouton_Bas(False);
	affiche_bouton_Droite(False);
	affiche_bouton_Gauche(False);
	affiche_bouton_AideOff();
	affiche_bouton_quitter();
	
	aff_pol("4096", 80, P4096, darkgray);
	aff_pol("Score :", 40, Pscore, darkgray);
	aff_pol("Aide :", 40, Paide, darkgray);
	
	
	
	return;
}


void affiche_accueil(modeDifficulte difficulte, modeAffichage affichage, modeFusion fusion)
{
	fill_screen(beige);
	affiche_texte_accueil();
	affiche_bouton_Start(False);
	if(affichage==AFF0)
	{
		affiche_bouton_Aff0(True);
		affiche_bouton_Aff1(False);
	}
	else if(affichage==AFF1)
	{
		affiche_bouton_Aff1(True);
		affiche_bouton_Aff0(False);
	}
	
	if(difficulte==FACILE)
	{
		affiche_bouton_Facile(True);
		affiche_bouton_Difficile(False);
	}
	else if(difficulte==DIFFICILE)
	{
		affiche_bouton_Facile(False);
		affiche_bouton_Difficile(True);
	}
	
	if(fusion==CLASSIQUE)
	{
		affiche_bouton_Classique(True);
		affiche_bouton_Totale(False);
	}
	else if(fusion==TOTALE)
	{
		affiche_bouton_Classique(False);
		affiche_bouton_Totale(True);
	}
	affiche_all();
}


void affiche_bouton_Haut(BOOL a)
{
	POINT P, P1, P2, P3;
	
	P.x=L_FENETRE-180+3; P.y=H_FENETRE-220-3;
	draw_fill_circle(P, 41, 0x857242);
	
	P.x=L_FENETRE-180; P.y=H_FENETRE-220;
	draw_fill_circle(P, 40, 0xD6BE84);
	
	P1.x=P.x; P1.y=P.y+25;
	P2.x=P.x-20; P2.y=P.y-15;
	P3.x=P.x+20; P3.y=P.y-15;
	
	if(a)
	{
		draw_fill_triangle(P1, P2, P3, jaune);
	}
	else
	{
		draw_fill_triangle(P1, P2, P3, blanc);
	}
	
	return;
}

void affiche_bouton_Bas(BOOL a)
{
	POINT P, P1, P2, P3;
	
	P.x=L_FENETRE-180+3; P.y=H_FENETRE-380-3;
	draw_fill_circle(P, 41, 0x857242);
	
	P.x=L_FENETRE-180; P.y=H_FENETRE-380;
	draw_fill_circle(P, 40, 0xD6BE84);
	
	P1.x=P.x; P1.y=P.y-25;
	P2.x=P.x-20; P2.y=P.y+15;
	P3.x=P.x+20; P3.y=P.y+15;
	
	if(a)
	{
		draw_fill_triangle(P1, P2, P3, jaune);
	}
	else
	{
		draw_fill_triangle(P1, P2, P3, blanc);
	}
	
	
	return;
}


void affiche_bouton_Droite(BOOL a)
{
	POINT P, P1, P2, P3;
	
	P.x=L_FENETRE-100+3; P.y=H_FENETRE-300-3;
	draw_fill_circle(P, 41, 0x857242);
	
	P.x=L_FENETRE-100; P.y=H_FENETRE-300;
	draw_fill_circle(P, 40, 0xD6BE84);
	
	P1.x=P.x+25; P1.y=P.y;
	P2.x=P.x-15; P2.y=P.y+20;
	P3.x=P.x-15; P3.y=P.y-20;
	
	if(a)
	{
		draw_fill_triangle(P1, P2, P3, jaune);
	}
	else
	{
		draw_fill_triangle(P1, P2, P3, blanc);
	}
	
	
	return;
}

void affiche_bouton_Gauche(BOOL a)
{
	POINT P, P1, P2, P3;
	
	P.x=L_FENETRE-260+3; P.y=H_FENETRE-300-3;
	draw_fill_circle(P, 41, 0x857242);
	
	P.x=L_FENETRE-260; P.y=H_FENETRE-300;
	draw_fill_circle(P, 40, 0xD6BE84);
	
	P1.x=P.x-25; P1.y=P.y;
	P2.x=P.x+15; P2.y=P.y+20;
	P3.x=P.x+15; P3.y=P.y-20;
	
	if(a)
	{
		draw_fill_triangle(P1, P2, P3, jaune);
	}
	else
	{
		draw_fill_triangle(P1, P2, P3, blanc);
	}
	
	return;
}


void affiche_bouton_Aide(BOOL a)
{
	if(a)
	{
		affiche_bouton_AideOn();
	}
	else
	{
		affiche_bouton_AideOff();
	}
}

void affiche_bouton_AideOff()
{
	effacer_bouton_Aide();
	
	POINT P1, P2;
	
	P1.x=L_FENETRE-120; P1.y=H_FENETRE-585;
	P2.x=L_FENETRE-80; P2.y=H_FENETRE-615;
	draw_fill_rectangle(P1, P2, gris);
	
	P1.y=P1.y-15;
	P2.y=P2.y+15;
	draw_fill_circle(P1, 18, rouge);
	draw_fill_circle(P1, 15, lightgrey);
	draw_fill_circle(P2, 15, gris);
	
	return;
}
	
void affiche_bouton_AideOn()
{
	effacer_bouton_Aide();
	
	POINT P1, P2;
	
	P1.x=L_FENETRE-120; P1.y=H_FENETRE-585;
	P2.x=L_FENETRE-80; P2.y=H_FENETRE-615;
	draw_fill_rectangle(P1, P2, gris);
	
	P1.y=P1.y-15;
	P2.y=P2.y+15;
	draw_fill_circle(P2, 18, vert);
	draw_fill_circle(P2, 15, lightgrey);
	draw_fill_circle(P1, 15, gris);
	
	return;
}

void effacer_bouton_Aide()
{
	POINT P1, P2;
	P1.x=L_FENETRE-120-18; P1.y=H_FENETRE-585+3;
	P2.x=L_FENETRE-80+18; P2.y=H_FENETRE-615-3;
	draw_fill_rectangle(P1,P2, beige);

}

void affiche_bouton_quitter()
{
	POINT P1={L_FENETRE-260,140},
		  P2={L_FENETRE-100,60};
	draw_fill_rectangle(P1, P2, 0x857242);
	P1.x+=5; P1.y-=5;
	P2.x-=5; P2.y+=5;
	draw_fill_rectangle(P1, P2, 0xD6BE84);
	P1.x=L_FENETRE-225; P1.y=120;
	aff_pol("Quitter", 25, P1, blanc);
	return;
}

void affiche_plateau(modeAffichage choix)
{
	int i, j;
	
	for(i=0; i<T_GRILLE; i++)
	{
		for(j=0; j<T_GRILLE; j++)
		{
			
			POINT pt1, pt2; // attention
			int rayon = 8;
			
			pt1.x=50+2*rayon+100*i     ; pt1.y=50-2*rayon+100*(j+1) ;
			pt2.x=50-2*rayon+100*(i+1) ; pt2.y=50+2*rayon+100*j     ;
		
			draw_fill_rectangle(pt1, pt2, palette[choix][0][plateau[i][j]]);				
			draw_fill_circle(pt1, rayon, palette[choix][0][plateau[i][j]]);
			draw_fill_circle(pt2, rayon, palette[choix][0][plateau[i][j]]);
			
			pt2.y=50-rayon+100*(j+1);
			draw_fill_rectangle(pt1, pt2, palette[choix][0][plateau[i][j]]);
			
			pt1.x=50-2*rayon+100*(i+1);
			pt2.x=50-rayon+100*(i+1); pt2.y=50+2*rayon+100*j;
			
			draw_fill_rectangle(pt1, pt2, palette[choix][0][plateau[i][j]]);
			draw_fill_circle(pt1, rayon, palette[choix][0][plateau[i][j]]);
			
			pt2.x=50+2*rayon+100*i;
			pt1.y=50+rayon+100*j;
			
			draw_fill_rectangle(pt1, pt2, palette[choix][0][plateau[i][j]]);
			draw_fill_circle(pt2, rayon, palette[choix][0][plateau[i][j]]);
			
			pt1.x=50+rayon+100*i     ; pt1.y=50-2*rayon+100*(j+1) ;
			draw_fill_rectangle(pt1, pt2, palette[choix][0][plateau[i][j]]);
				
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
				
				aff_int(pow(2,plateau[i][j]), 28, pt1, palette[choix][1][plateau[i][j]]); 
			}	
			
			
		}
		
	}
	affiche_all();
	return;
}




void affiche_score(int score)
{	
	POINT P1={L_FENETRE-170, H_FENETRE-501},
		  P2={L_FENETRE, H_FENETRE-551};
	draw_fill_rectangle(P1, P2, beige);
	aff_int(score, 40, P1, darkgray);
	return;
}


void affiche_texte_accueil()
{
	POINT P4096={462, 900};
	aff_pol("4096", 100, P4096, gray);
	P4096.x-=2; P4096.y+=2;	
	aff_pol("4096", 100, P4096, darkgray);
	return;
}

void affiche_bouton_Aff0(BOOL actif)
{
	POINT P1={350,700},
		  P2={550,600};
	char texte[]="Vue 1";
	affiche_bouton_menu(actif, P1, P2, texte);
	return;
}

void affiche_bouton_Aff1(BOOL actif)
{
	POINT P1={650,700},
		  P2={850,600};
	char texte[]="Vue 2";
	affiche_bouton_menu(actif, P1, P2, texte);
	return;
}

void affiche_bouton_Facile(BOOL actif)
{
	POINT P1={350,500},
		  P2={550,400};
	char texte[]="Facile";
	affiche_bouton_menu(actif, P1, P2, texte);
	return;
}

void affiche_bouton_Difficile(BOOL actif)
{
	POINT P1={650,500},
		  P2={850,400};
	char texte[]="   Difficile";
	affiche_bouton_menu(actif, P1, P2, texte);
	return;
}

void affiche_bouton_Classique(BOOL actif)
{
	POINT P1={350,300},
		  P2={550,200};
	char texte[]="Classique ";
	affiche_bouton_menu(actif, P1, P2, texte);
	return;
}

void affiche_bouton_Totale(BOOL actif)
{
	POINT P1={650,300},
		  P2={850,200};
	char texte[]="Totale";
	affiche_bouton_menu(actif, P1, P2, texte);
	return;
}

void affiche_bouton_Start(BOOL actif)
{
	POINT P1={350,150},
		  P2={850,50};
	char texte[]="Commencer la partie !";
	affiche_bouton_menu(actif, P1, P2, texte);
	return;
}

void affiche_bouton_menu(BOOL actif, POINT P1, POINT P2, char *texte)
{
	POINT P3={P1.x+5,P2.y+5},
		  P4={P2.x-4,P1.y-5};
	
	if(actif)
	{
		draw_fill_rectangle(P1,P2, 0x568B60);
		P1.x+=5; P1.y-=5;
		P2.x-=5; P2.y+=5;
		draw_fill_rectangle(P1,P2,0xE97814);
		P3.x=(P1.x+P2.x)/2-strlen(texte)*6; P3.y=(P1.y+P2.y)/2+20;
		aff_pol(texte,25,P3, blanc);
	}
	else
	{
		draw_fill_rectangle(P1,P2, 0x8C4644);
		P1.x+=5; P1.y-=5;
		P2.x-=5; P2.y+=5;
		draw_fill_rectangle(P1,P2,0xCF6802);
		P1.x-=9; P1.y+=9;
		P2.x-=4; P2.y+=4;
		draw_fill_rectangle(P1,P2,0xE97814);
		P1.x-=1;      P1.y=P3.y+4;
		P2.x=P1.x+10; P2.y=P1.y;
		draw_fill_triangle(P1, P3, P2,0xCF6802);
		P1.x=P4.x-4;  P1.y=P4.y;
		P2.x=P1.x;    P2.y=P1.y+9;
		draw_fill_triangle(P4, P2, P1, 0xCF6802);
		P3.x=(P3.x+P4.x-10)/2-strlen(texte)*6; P3.y=(P3.y+P4.y+20)/2+20;
		aff_pol(texte,25,P3, blanc);
	}
	
	return;
}


void affiche_bouton_propose(choixBouton boutonPropose)
{
	switch(boutonPropose) // sortir du main
	{
		case HAUT:	affiche_bouton_Haut(True);	break;
		case BAS:	affiche_bouton_Bas(True);		break;
		case GAUCHE:affiche_bouton_Gauche(True);	break;
		case DROITE:affiche_bouton_Droite(True);	break;
		default:	break;
	}
	affiche_all();
	return;
}

void efface_bouton_propose()
{
	affiche_bouton_Haut(False);
	affiche_bouton_Bas(False);
	affiche_bouton_Gauche(False);
	affiche_bouton_Droite(False);
	return;
}

void affiche_gagne()
{
	POINT P1={L_FENETRE-310, H_FENETRE-170},
	      P2={L_FENETRE-250, H_FENETRE-430};
	draw_fill_rectangle(P1, P2, jaune);
	return;
}

void affiche_perdu()
{
	POINT P1={L_FENETRE-310, H_FENETRE-170},
	      P2={L_FENETRE-250, H_FENETRE-430};      
	draw_fill_rectangle(P1, P2, rouge);
	return;
}
