#include "calculs.h"



void initPlateau()
{
	int i,j;
	
	for(i=0; i<T_GRILLE; i++)
	{
		for(j=0; j<T_GRILLE; j++)
		{
			ajouterTuile(0, i, j);
		}
	}
	return;
}

void ajouterTuile(int puiss, int i, int j)
{
	plateau[i][j]=puiss;
	return;
}
	
	
void initJeu(t_bouton* clavier)
{
	t_bouton bt_haut, bt_bas, bt_gauche, bt_droite,bt_aideOn, bt_aideOff, bt_quitter;
	
	bt_haut.texte="H";
	bt_haut.nom=HAUT;
	bt_haut.pt_hg.x= 975; bt_haut.pt_hg.y= 750;
	bt_haut.pt_bd.x= 1075; bt_haut.pt_bd.y= 650;
	bt_haut.clr_fond=gris;
	bt_haut.clr_texte=blanc;
	bt_haut.t_texte=50;
	
	bt_bas.texte="B";
	bt_bas.nom=BAS;
	bt_bas.pt_hg.x= 975; bt_bas.pt_hg.y= 550;
	bt_bas.pt_bd.x= 1075; bt_bas.pt_bd.y= 450;
	bt_bas.clr_fond=gris;
	bt_bas.clr_texte=blanc;
	bt_bas.t_texte=50;
	
	bt_gauche.texte="G";
	bt_gauche.nom=GAUCHE;
	bt_gauche.pt_hg.x= 875; bt_gauche.pt_hg.y= 650;
	bt_gauche.pt_bd.x= 975; bt_gauche.pt_bd.y= 550;
	bt_gauche.clr_fond=gris;
	bt_gauche.clr_texte=blanc;
	bt_gauche.t_texte=50;
	
	bt_droite.texte="D";
	bt_droite.nom=DROITE;
	bt_droite.pt_hg.x= 1075; bt_droite.pt_hg.y= 650;
	bt_droite.pt_bd.x= 1175; bt_droite.pt_bd.y= 550;
	bt_droite.clr_fond=gris;
	bt_droite.clr_texte=blanc;
	bt_droite.t_texte=50;
	
	bt_aideOn.texte="On";
	bt_aideOn.nom=AIDE_ON;
	bt_aideOn.pt_hg.x= 1025-64; bt_aideOn.pt_hg.y=300;
	bt_aideOn.pt_bd.x= 1025; bt_aideOn.pt_bd.y= 300-64;
	bt_aideOn.clr_fond=gris;
	bt_aideOn.clr_texte=blanc;
	bt_aideOn.t_texte=15;
	
	bt_aideOff.texte="Off";
	bt_aideOff.nom=AIDE_OFF;
	bt_aideOff.pt_hg.x= 1025; bt_aideOff.pt_hg.y= 300;
	bt_aideOff.pt_bd.x= 1025+64; bt_aideOff.pt_bd.y= 300-64;
	bt_aideOff.clr_fond=gris;
	bt_aideOff.clr_texte=blanc;
	bt_aideOff.t_texte=15;
	
	bt_quitter.texte="Quitter";
	bt_quitter.nom=QUITTER;
	bt_quitter.pt_hg.x= 1025-64; bt_quitter.pt_hg.y= 300-64-20;
	bt_quitter.pt_bd.x= 1025+64; bt_quitter.pt_bd.y= 300-64-20-64;
	bt_quitter.clr_fond=gris;
	bt_quitter.clr_texte=blanc;
	bt_quitter.t_texte=15;
	
	clavier[0]=bt_haut;
	clavier[1]=bt_bas;
	clavier[2]=bt_gauche;
	clavier[3]=bt_droite;
	clavier[4]=bt_aideOn;
	clavier[5]=bt_aideOff;
	clavier[6]=bt_quitter;


	
}


void pop2F()
{
	int i,j;
	
	do
	{
		i=alea_int(T_GRILLE);
		j=alea_int(T_GRILLE);
	}while(plateau[i][j]!=0);
	
	ajouterTuile(1, i, j);
}
