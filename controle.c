#include "controle.h"


choixBouton attendreSelection()
{
        POINT P;
        BOOL trouve=False;
      	choixBouton boutonChoisi;

        while(!trouve)
        {
                P=wait_clic();

              	if(a_clique_dans_bouton_haut(&P))
              	{
              		trouve=True;
              		boutonChoisi=HAUT;
              	}
              	
              	if(a_clique_dans_bouton_bas(&P))
              	{
              		trouve=True;
              		boutonChoisi=BAS;
              	}
              	
              	if(a_clique_dans_bouton_gauche(&P))
              	{
              		trouve=True;
              		boutonChoisi=GAUCHE;
              	}
              	
              	if(a_clique_dans_bouton_droite(&P))
              	{
              		trouve=True;
              		boutonChoisi=DROITE;
              	}
              	if(a_clique_dans_bouton_aide(&P))
              	{
              		trouve=True;
              		boutonChoisi=AIDE;
              	}
              	
        }
        return boutonChoisi;
}



BOOL a_clique_dans_bouton_haut(POINT *P)
{
	POINT Pc={L_FENETRE-180, Pc.y=H_FENETRE-220};
	
	if(distance(*P, Pc)<=40)
	{
		return True;
	}
	else
	{
		return False;
	}
}

BOOL a_clique_dans_bouton_bas(POINT *P)
{
	POINT Pc={L_FENETRE-180, Pc.y=H_FENETRE-380};
	
	if(distance(*P, Pc)<=40)
	{
		return True;
	}
	else
	{
		return False;
	}
}

BOOL a_clique_dans_bouton_gauche(POINT *P)
{
	POINT Pc={L_FENETRE-260, Pc.y=H_FENETRE-300};
	
	if(distance(*P, Pc)<=40)
	{
		return True;
	}
	else
	{
		return False;
	}
}

BOOL a_clique_dans_bouton_droite(POINT *P)
{
	POINT Pc={L_FENETRE-100, Pc.y=H_FENETRE-300};
	
	if(distance(*P, Pc)<=40)
	{
		return True;
	}
	else
	{
		return False;
	}
}


BOOL a_clique_dans_bouton_aide(POINT *P)
{
	POINT P1, P2;
	P1.x=L_FENETRE-135; P1.y=H_FENETRE-585;
	P2.x=L_FENETRE-65; P2.y=H_FENETRE-615;
	
	if(P->x >= P1.x && P->x <= P2.x && P->y >= P2.y && P->y <= P1.y)
	{
		return True;
	}
	else
	{
		return False;
	}
}

	
