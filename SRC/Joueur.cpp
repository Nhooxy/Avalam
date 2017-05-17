#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "../HEADER/Joueur.h"

using namespace std;


Joueur::Joueur(string name, short x) {
    pseudo = name;
    couleur = x;
}

Joueur::Joueur(vector <string> monTableau, short appel) {
    if (appel == 1) {
        pseudo = monTableau[0];
        couleur = atoi(monTableau[1].c_str());//fonction dans cstdlib converti string en short / int ...
    } else {
        pseudo = monTableau[2];
        couleur = atoi(monTableau[3].c_str());
    }
}

string Joueur::name() {
    return pseudo;
}

short Joueur::color() {
    return couleur;
}