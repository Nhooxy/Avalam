#ifndef __Joueur_H__
#define __Joueur_H__
#include <string>
#include <vector>

using namespace std;

class Joueur{

    string pseudo;
	short couleur;// 0 => J1 // 1 => J2

public:
	Joueur(string name, short x);
	Joueur(vector<string> monTableau, short appel);
	string name();
	short color();

};



#endif
