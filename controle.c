#include "controle.h"


choixBouton attendreSelection()
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
              	
        }
        return boutonChoisi;
}



choixBouton attendreParametres()
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

void changerParametres(choixBouton boutonChoisi, modeDifficulte *difficulte, modeAffichage *affichage, modeFusion *fusion)
{
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

	
BOOL a_clique_dans_bouton_aff0(POINT P)
{
	return False;
}
BOOL a_clique_dans_bouton_aff1(POINT P)
{
	return False;
}
BOOL a_clique_dans_bouton_facile(POINT P)
{
	return False;
}
BOOL a_clique_dans_bouton_difficile(POINT P)
{
	return False;
}
BOOL a_clique_dans_bouton_classique(POINT P)
{
	return False;
}
BOOL a_clique_dans_bouton_totale(POINT P)
{
	return False;
}

BOOL a_clique_dans_bouton_start(POINT P)
{
	return False;
}
