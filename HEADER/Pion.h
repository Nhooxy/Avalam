#ifndef __Pion_H__
#define __Pion_H__

using namespace std;

class Pion{

	short positionLigne;
	short positionColonne;
    short hauteur;
    short qui;// 0 => J1 // 1 => J2
    friend class Plateau;

public:
    Pion(short pLigne, short pColonne, short quiEstCe);
    Pion(short pLigne, short pColonne, short quiEstCe, short laHauteur);
    ~Pion();

};


#endif
