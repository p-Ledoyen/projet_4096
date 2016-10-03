#include "controle.h"


choixBouton attendre_selection()
{
        POINT P;
        BOOL trouve=False;
      	choixBouton boutonChoisi;

        while(!trouve)
        {
                P=wait_clic();

              	if(a_clique_dans_bouton_haut(P))
              	{
              		trouve=True;
              		boutonChoisi=HAUT;
              	}
              	
              	else if(a_clique_dans_bouton_bas(P))
              	{
              		trouve=True;
              		boutonChoisi=BAS;
              	}
              	
              	else if(a_clique_dans_bouton_gauche(P))
              	{
              		trouve=True;
              		boutonChoisi=GAUCHE;
              	}
              	
              	else if(a_clique_dans_bouton_droite(P))
              	{
              		trouve=True;
              		boutonChoisi=DROITE;
              	}
              	else if(a_clique_dans_bouton_aide(P))
              	{
              		trouve=True;
              		boutonChoisi=AIDE;
              	}
              	else if(a_clique_dans_bouton_quitter(P))
              	{
					trouve=True;
              		boutonChoisi=QUITTER;
              	}
        }
        return boutonChoisi;
}



choixBouton attendre_parametres()
{
        POINT P;
        BOOL trouve=False;
      	choixBouton boutonChoisi;

        while(!trouve)
        {
                P=wait_clic();

              	if(a_clique_dans_bouton_aff0(P))
              	{
              		trouve=True;
              		boutonChoisi=B_AFF0;
              	}
              	
              	else if(a_clique_dans_bouton_aff1(P))
              	{
              		trouve=True;
              		boutonChoisi=B_AFF1;
              	}
              	
              	else if(a_clique_dans_bouton_facile(P))
              	{
              		trouve=True;
              		boutonChoisi=B_FACILE;
              	}
              	
              	else if(a_clique_dans_bouton_difficile(P))
              	{
              		trouve=True;
              		boutonChoisi=B_DIFFICILE;
              	}
              	else if(a_clique_dans_bouton_totale(P))
              	{
              		trouve=True;
              		boutonChoisi=B_TOTALE;
              	}
              	else if(a_clique_dans_bouton_classique(P))
              	{
              		trouve=True;
              		boutonChoisi=B_CLASSIQUE;
              	}
              	else if(a_clique_dans_bouton_start(P))
              	{
              		trouve=True;
              		boutonChoisi=START;
              	}
        }
        return boutonChoisi;
}

void changer_parametres(choixBouton boutonChoisi, modeDifficulte *difficulte, modeAffichage *affichage, modeFusion *fusion)
{
	switch(boutonChoisi)
	{
		case B_AFF0:      *affichage=AFF0;		break;
		case B_AFF1:      *affichage=AFF1;		break;
		case B_FACILE: 	  *difficulte=FACILE;	break;
		case B_DIFFICILE: *difficulte=DIFFICILE;break;
		case B_CLASSIQUE: *fusion=CLASSIQUE;	break;
		case B_TOTALE:    *fusion=TOTALE;		break;
		default:break;
	}
}


BOOL a_clique_dans_bouton_haut(POINT P)
{
	POINT Pc={L_FENETRE-180, Pc.y=H_FENETRE-220};
	
	if(distance(P, Pc)<=40)
	{
		return True;
	}
	else
	{
		return False;
	}
}

BOOL a_clique_dans_bouton_bas(POINT P)
{
	POINT Pc={L_FENETRE-180, Pc.y=H_FENETRE-380};
	
	if(distance(P, Pc)<=40)
	{
		return True;
	}
	else
	{
		return False;
	}
}

BOOL a_clique_dans_bouton_gauche(POINT P)
{
	POINT Pc={L_FENETRE-260, Pc.y=H_FENETRE-300};
	
	if(distance(P, Pc)<=40)
	{
		return True;
	}
	else
	{
		return False;
	}
}

BOOL a_clique_dans_bouton_droite(POINT P)
{
	POINT Pc={L_FENETRE-100, Pc.y=H_FENETRE-300};
	
	if(distance(P, Pc)<=40)
	{
		return True;
	}
	else
	{
		return False;
	}
}


BOOL a_clique_dans_bouton_aide(POINT P)
{
	POINT P1, P2;
	P1.x=L_FENETRE-135; P1.y=H_FENETRE-585;
	P2.x=L_FENETRE-65; P2.y=H_FENETRE-615;
	
	if(P.x >= P1.x && P.x <= P2.x && P.y >= P2.y && P.y <= P1.y)
	{
		return True;
	}
	else
	{
		return False;
	}
}

BOOL a_clique_dans_bouton_quitter(POINT P)
{
	POINT P1={L_FENETRE-260,140},
		  P2={L_FENETRE-100,60};
	
	if(P.x >= P1.x && P.x <= P2.x && P.y >= P2.y && P.y <= P1.y)
	{
		return True;
	}
	else
	{
		return False;
	}
}

	
BOOL a_clique_dans_bouton_aff0(POINT P)
{
	POINT P1={350,700},
		  P2={550,600};
	
	if(P.x >= P1.x && P.x <= P2.x && P.y >= P2.y && P.y <= P1.y)
	{
		return True;
	}
	else
	{
		return False;
	}
}
BOOL a_clique_dans_bouton_aff1(POINT P)
{
	POINT P1={650,700},
		  P2={850,600};
	
	if(P.x >= P1.x && P.x <= P2.x && P.y >= P2.y && P.y <= P1.y)
	{
		return True;
	}
	else
	{
		return False;
	}
}
BOOL a_clique_dans_bouton_facile(POINT P)
{
	POINT P1={350,500},
		  P2={550,400};
	
	if(P.x >= P1.x && P.x <= P2.x && P.y >= P2.y && P.y <= P1.y)
	{
		return True;
	}
	else
	{
		return False;
	}
}
BOOL a_clique_dans_bouton_difficile(POINT P)
{
	POINT P1={650,500},
		  P2={850,400};
	
	if(P.x >= P1.x && P.x <= P2.x && P.y >= P2.y && P.y <= P1.y)
	{
		return True;
	}
	else
	{
		return False;
	}
}

BOOL a_clique_dans_bouton_classique(POINT P)
{
	POINT P1={350,300},
		  P2={550,200};
	
	if(P.x >= P1.x && P.x <= P2.x && P.y >= P2.y && P.y <= P1.y)
	{
		return True;
	}
	else
	{
		return False;
	}
}
BOOL a_clique_dans_bouton_totale(POINT P)
{
	POINT P1={650,300},
		  P2={850,200};
	
	if(P.x >= P1.x && P.x <= P2.x && P.y >= P2.y && P.y <= P1.y)
	{
		return True;
	}
	else
	{
		return False;
	}
}


BOOL a_clique_dans_bouton_start(POINT P)
{
	POINT P1={350,150},
		  P2={850,50};
	
	if(P.x >= P1.x && P.x <= P2.x && P.y >= P2.y && P.y <= P1.y)
	{
		return True;
	}
	else
	{
		return False;
	}
}
