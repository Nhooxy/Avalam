#include <iostream>
#include <vector>
#include "../HEADER/Pion.h"

using namespace std;

Pion::Pion(short pLigne, short pColonne, short quiEstCe) {
    positionLigne = pLigne;
    positionColonne = pColonne;
    hauteur = 1;
    qui = quiEstCe;
}

Pion::Pion(short pLigne, short pColonne, short quiEstCe, short laHauteur) {
    positionLigne = pLigne;
    positionColonne = pColonne;
    hauteur = laHauteur;
    qui = quiEstCe;
}

Pion::~Pion() {}

