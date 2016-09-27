#include "controle.h"


choixBouton attendreSelection(t_bouton* clavier)
{
	POINT P;
	BOOL trouve=False;
	int i, iTrouve=0;
	
	while(!trouve)
	{
		P=wait_clic();
		
		for(i=0; i<7; i++)
		{
			if((P.x>clavier[i].pt_hg.x) && (P.x<clavier[i].pt_bd.x) && (P.y<clavier[i].pt_hg.y) && (P.y>clavier[i].pt_bd.y))
			{
				iTrouve=i;
				trouve=True;
			}
		}
	}
	return clavier[iTrouve].nom;
}
