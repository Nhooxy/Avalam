#ifndef __fonction_H__
#define __fonction_H__

#include "../SRC/SFML/Audio.hpp"
const short difficulte = 64;

void jouer();
void affMenu();
void affMenu2();
void lectureMusique(sf::Music& maMusic);
int selection();
void centre();
void regle();
bool partie(short slot);
short choixRegle();
void commentJouer();
Plateau deplacement(Joueur j, Plateau first, short hauteurMax);
short selectionSlot(short unOuDeux);
bool charger(short slot);
bool chargerPartie(Plateau second, Joueur j1, Joueur j2, short hauteurMax, short slot);
bool testSiFichierVide(char const *fname);
void quaranteDeux();
void interface();
void son();
void intro();
vector <string> constructionTableau1(vector <string> monTableau);
vector <string> constructionTableau2(vector <string> monTableau);
vector <string> constructionTableau3(vector <string> monTableau);
short testSiNombre();
Plateau deplacementIA(Plateau first, short hauteurMax, short difficulte, short IA);
#endif
