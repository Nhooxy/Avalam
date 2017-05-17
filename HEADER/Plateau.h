#ifndef __Plateau_H__
#define __Plateau_H__
#include <vector>
#include "Pion.h"
#include "Joueur.h"

using namespace std;

class Plateau{

	short ligne;
	short colonne;
	vector<vector<Pion*> > board;

public:
	Plateau();
	Plateau(vector<string> monTableau);
	Plateau(Plateau& first);
	~Plateau();
	void aff();
	bool caseVide(short x,short y);
	bool deplacementValide(short x, short y, short a, short b, short hauteurMax);
	void affDeplacementDisponible(short x, short y, short hauteurMax);
	void leDeplacement(short x, short y, short a, short b);
	bool pionHauteurMax(short x, short y, short hauteurMax);
	bool possible(short hauteurMax);
	void compterPoints(Joueur j1, Joueur j2);
	void save(short slot, Joueur j1, Joueur j2, short hauteurMax);
	bool coordonnesPlateauValide(short x, short y);
	bool selectionValide(short x,short y, short hauteurMax);
	void saveSlot1(short slot, Joueur j1, Joueur j2, short hauteurMax);
	void saveSlot2(short slot, Joueur j1, Joueur j2, short hauteurMax);
	void saveSlot3(short slot, Joueur j1, Joueur j2, short hauteurMax);
	short getLigne();
	short getColonne();
	void inverseCouleur();
	bool scoringIA(short IA);
	short MinMax(short& i, short& j, short& k, short& l, short& hauteurMax, short& p, short &IA, short& notation);
	bool algoIA(short& hauteurMax, short& difficulte, short& p, short note[][11][11][11][11], short IA);
	bool NoteNonConcluante(short IA, short hauteurMax);
};

#endif
