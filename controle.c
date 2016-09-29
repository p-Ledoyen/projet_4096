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
              	
        }
        return boutonChoisi;
}



BOOL a_clique_dans_bouton_haut(POINT *P)
{
	POINT Pc;
	Pc.x=L_FENETRE-180; Pc.y=H_FENETRE-220;
	
	if(distance(*P, Pc)<=40)
	{
		return True;
	}
	else
	{
		return False;
	}
}
