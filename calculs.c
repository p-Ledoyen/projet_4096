#include "calculs.h"



void initPlateau(t_interface interf)
{
	int i,j;
	
	for(i=0; i<T_GRILLE; i++)
	{
		for(j=0; j<T_GRILLE; i++)
		{
			ajouterTuile(1, i, j, interf);
		}
	}
	return;
}

void ajouterTuile(int puiss, int i, int j, t_interface interf)
{
	t_tuile nouvelleTuile;
	
	nouvelleTuile.exposant=puiss;
	nouvelleTuile.clr_fond=interf.palette[0][puiss];
	nouvelleTuile.clr_texte=interf.palette[1][puiss];
	nouvelleTuile.pt_hg.x=50+100*i;
	nouvelleTuile.pt_hg.y=50+100*(j+1);
	nouvelleTuile.pt_bd.x=50+100*(i+1);
	nouvelleTuile.pt_bd.y=50+100*j;
	
	plateau[i][j]=nouvelleTuile;
	return;
}
	
	
