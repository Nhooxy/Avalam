#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "../HEADER/Plateau.h"
#include "../HEADER/fonction.h"

using namespace std;

Plateau::Plateau() {
    cout << "Quel Plateau voulez vous ? " << endl;
    cout << "Plateau de base (1)" << endl;
    cout << "Plateau preset 2 (2)" << endl;
    cout << "Plateau preset 3 (3)" << endl;
    cout << "Plateau de la taille de votre choix (4)" << endl;
    short choix = -1;
    while (choix < 1 || choix > 4) {
        choix = testSiNombre();
        switch (choix) {
            case (1): {
                colonne = 9;//restriction : il faut que ce soit toujours impair car 
                ligne = 9;//la case du milieu doit toujours etre vide

                //création du tableau[][] vide
                for (short i = 0; i < colonne; i++) {
                    board.push_back(vector<Pion *>(ligne));
                }

                //génération de pion dans le tableau
                for (short i = 0; i < ligne; i++) {
                    //quand les ligne sont paire
                    if (i % 2 == 0) {
                        for (short j = 0; j < colonne; j++) {
                            //quand les colonne sont paire
                            if (j % 2 == 0) {
                                board[i][j] = new Pion(i, j, 0);
                            } else {
                                //quand les colonne ne le sont pas
                                board[i][j] = new Pion(i, j, 1);
                            }
                        }
                        //quand les ligne sont impaire
                    } else {
                        for (short j = 0; j < colonne; j++) {
                            if (j % 2 == 0) {
                                board[i][j] = new Pion(i, j, 1);
                            } else {
                                board[i][j] = new Pion(i, j, 0);
                            }
                        }
                    }
                }
                //application de la restriction
                board[4][4] = NULL;
                //application des restriction du plateau originel
                //board[][] = NULL;
                for (short i = 0; i < ligne; i++) {
                    for (short j = 0; j < colonne; j++) {
                        if (i == 0 && (j <= 3 || j >= 6)) {
                            board[i][j] = NULL;
                        } else if (i == 0 && (j <= 3 || j >= 6)) {
                            board[i][j] = NULL;
                        } else if (i == 1 && (j <= 0 || j >= 6)) {
                            board[i][j] = NULL;
                        } else if (i == 2 && (j >= 7)) {
                            board[i][j] = NULL;
                        } else if (i == 3 && (j >= 7)) {
                            board[i][j] = NULL;
                        } else if (i == 4 && (j <= 0 || j >= 8)) {
                            board[i][j] = NULL;
                        } else if (i == 5 && (j <= 1 || j >= 9)) {
                            board[i][j] = NULL;
                        } else if (i == 6 && (j <= 1 || j >= 9)) {
                            board[i][j] = NULL;
                        } else if (i == 7 && (j <= 2 || j >= 8)) {
                            board[i][j] = NULL;
                        } else if (i == 8 && (j <= 2 || j >= 5)) {
                            board[i][j] = NULL;
                        }
                    }
                }
                break;
            }
            case (2): {
                colonne = 9;//restriction : il faut que ce soit toujours impair car 
                ligne = 9;//la case du milieu doit toujours etre vide

                //création du tableau[][] vide
                for (short i = 0; i < colonne; i++) {
                    board.push_back(vector<Pion *>(ligne));
                }

                //génération de pion dans le tableau
                for (short i = 0; i < ligne; i++) {
                    //quand les ligne sont paire
                    if (i % 2 == 0) {
                        for (short j = 0; j < colonne; j++) {
                            //quand les colonne sont paire
                            if (j % 2 == 0) {
                                board[i][j] = new Pion(i, j, 0);
                            } else {
                                //quand les colonne ne le sont pas
                                board[i][j] = new Pion(i, j, 1);
                            }
                        }
                        //quand les ligne sont impaire
                    } else {
                        for (short j = 0; j < colonne; j++) {
                            if (j % 2 == 0) {
                                board[i][j] = new Pion(i, j, 1);
                            } else {
                                board[i][j] = new Pion(i, j, 0);
                            }
                        }
                    }
                }
                //application de la restriction
                board[4][4] = NULL;
                //application des restriction du plateau originel
                //board[][] = NULL;
                for (short i = 4; i < ligne; i++) {
                    board[i][0] = NULL;
                }
                for (short i = 6; i < ligne; i++) {
                    board[i][1] = NULL;
                }
                for (short i = 0; i < 3; i++) {
                    board[7][i] = NULL;
                }
                for (short i = 0; i < 5; i++) {
                    board[8][i] = NULL;
                }

                for (short i = 4; i < ligne; i++) {
                    board[0][i] = NULL;
                }
                for (short i = 6; i < ligne; i++) {
                    board[1][i] = NULL;
                }
                for (short i = 7; i < ligne; i++) {
                    board[2][i] = NULL;
                }
                for (short i = 0; i < 5; i++) {
                    board[i][8] = NULL;
                }
                break;
            }
            case (3): {
                colonne = 9;//restriction : il faut que ce soit toujours impair car 
                ligne = 9;//la case du milieu doit toujours etre vide

                //création du tableau[][] vide
                for (short i = 0; i < colonne; i++) {
                    board.push_back(vector<Pion *>(ligne));
                }

                //génération de pion dans le tableau
                for (short i = 0; i < ligne; i++) {
                    //quand les ligne sont paire
                    if (i % 2 == 0) {
                        for (short j = 0; j < colonne; j++) {
                            //quand les colonne sont paire
                            if (j % 2 == 0) {
                                board[i][j] = new Pion(i, j, 0);
                            } else {
                                //quand les colonne ne le sont pas
                                board[i][j] = new Pion(i, j, 1);
                            }
                        }
                        //quand les ligne sont impaire
                    } else {
                        for (short j = 0; j < colonne; j++) {
                            if (j % 2 == 0) {
                                board[i][j] = new Pion(i, j, 1);
                            } else {
                                board[i][j] = new Pion(i, j, 0);
                            }
                        }
                    }
                }
                //application de la restriction
                board[4][4] = NULL;
                //application des restriction du plateau originel
                //board[][] = NULL;
                board[4][0] = NULL;
                board[5][0] = NULL;
                board[8][0] = NULL;
                board[8][4] = NULL;
                board[8][1] = NULL;

                board[0][8] = NULL;
                board[0][7] = NULL;
                board[0][4] = NULL;
                board[4][8] = NULL;
                board[5][8] = NULL;
                break;
            }
            case (4): {
                while (ligne < 3 || ligne > 10) {
                    cout << "Entrer un nombre compris entre 3 et 10" << endl;
                    ligne = testSiNombre();
                }
                colonne = ligne;

                //création du tableau[][] vide
                for (short i = 0; i < colonne; i++) {
                    board.push_back(vector<Pion *>(ligne));
                }

                //génération de pion dans le tableau
                for (short i = 0; i < ligne; i++) {
                    //quand les ligne sont paire
                    if (i % 2 == 0) {
                        for (short j = 0; j < colonne; j++) {
                            //quand les colonne sont paire
                            if (j % 2 == 0) {
                                board[i][j] = new Pion(i, j, 0);
                            } else {
                                //quand les colonne ne le sont pas
                                board[i][j] = new Pion(i, j, 1);
                            }
                        }
                        //quand les ligne sont impaire
                    } else {
                        for (short j = 0; j < colonne; j++) {
                            if (j % 2 == 0) {
                                board[i][j] = new Pion(i, j, 1);
                            } else {
                                board[i][j] = new Pion(i, j, 0);
                            }
                        }
                    }
                }

                //application de la restriction
                board[ligne / 2][colonne / 2] = NULL;
                break;
            }
            default: {
                cout << "Choix non disponible..." << endl;
                break;
            }
        }
    }
}

Plateau::Plateau(vector <string> monTableau) {
    ligne = atoi(monTableau[4].c_str());
    colonne = atoi(monTableau[5].c_str());
    for (short i = 0; i < colonne; i++) {
        board.push_back(vector<Pion *>(ligne));
    }

    for (short i = 0; i < monTableau.size(); i++) {
        if ((monTableau[i] != "N") && (monTableau[i] == "*")) {
            i++;
            short a = atoi(monTableau[i].c_str());//recuperation ligne
            short b = atoi(monTableau[i + 1].c_str());//recuperaition colonne
            short c = atoi(monTableau[i + 2].c_str());//recuperation hauteur
            short d = atoi(monTableau[i + 3].c_str());//recuperation qui
            board[a][b] = new Pion(a, b, d, c);
            i++;
        } else if ((monTableau[i] == "N")) {
            i++;
            short a = atoi(monTableau[i].c_str());
            short b = atoi(monTableau[i + 1].c_str());
            board[a][b] = NULL;
        }
    }
}

Plateau::Plateau(Plateau &first) {
    ligne = first.ligne;
    colonne = first.colonne;
    for (short i = 0; i < colonne; i++) {
        board.push_back(vector<Pion *>(ligne));
    }
    for (short i = 0; i < ligne; i++) {
        for (short j = 0; j < colonne; j++) {
            if (first.board[i][j] != NULL) {
                board[i][j] = new Pion(first.board[i][j]->positionLigne, first.board[i][j]->positionColonne,
                                       first.board[i][j]->qui, first.board[i][j]->hauteur);
            } else {
                board[i][j] = NULL;
            }
        }
    }

}

Plateau::~Plateau() {}

void Plateau::affDeplacementDisponible(short x, short y, short hauteurMax) {
    cout << "Les deplacement possible avec le pion selectionné sont : " << endl;

    for (short i = -1; i < 2; i++) {
        if (x == 0 && i == -1) {//si on est sur la ligne 0 est que i de notre for = -1 alors ...
            i++;
        }
        for (short j = -1; j < 2; j++) {
            if (x == ligne - 1 && i == 1) {
                break;// si je suis sur la derniere ligne alors..
            }

            if (i == 0 && j == 0) {
                /*si pion courant alors rien*/
            } else if (y == colonne - 1 && j == 1) {
                /*si pion derniere colonne alors rien*/
            } else if (y == 0 && j == -1) {
                /*si pion premiere colonne alors rien*/
            } else if (!caseVide(x + (i), y + (j))) {
                if (board[x][y]->hauteur + board[x + (i)][y + (j)]->hauteur < hauteurMax) {
                    cout << "( " << x + (i) << " ; " << y + (j) << " )" << endl;
                }
            }
        }
    }

}

void Plateau::saveSlot1(short slot, Joueur j1, Joueur j2, short hauteurMax) {
    //déclaration du flux et ouverture du fichier selon le slot
    fstream fichier1("Slot1.s", ios::out | ios::trunc);
    if (fichier1) {//si l'ouverture a réussi
        fichier1 << j1.name() << endl;
        fichier1 << j1.color() << endl;
        fichier1 << j2.name() << endl;
        fichier1 << j2.color() << endl;
        fichier1 << colonne << endl;
        fichier1 << ligne << endl;
        fichier1 << hauteurMax << endl;
        for (short i = 0; i < ligne; i++) {
            for (short j = 0; j < colonne; j++) {
                if (board[i][j] != NULL) {
                    fichier1 << "*" << endl;
                    fichier1 << board[i][j]->positionLigne << endl;
                    fichier1 << board[i][j]->positionColonne << endl;
                    fichier1 << board[i][j]->hauteur << endl;
                    fichier1 << board[i][j]->qui << endl;
                } else {
                    fichier1 << "N" << endl;
                    fichier1 << i << endl;
                    fichier1 << j << endl;
                }
            }
        }
        fichier1.close();//on referme le fichier
    } else {
        cerr << "Erreur à l'ouverture !" << endl;
    }
}

void Plateau::saveSlot2(short slot, Joueur j1, Joueur j2, short hauteurMax) {
    //déclaration du flux et ouverture du fichier selon le slot
    fstream fichier1("Slot2.s", ios::out | ios::trunc);

    if (fichier1) {//si l'ouverture a réussi
        fichier1 << j1.name() << endl;
        fichier1 << j1.color() << endl;
        fichier1 << j2.name() << endl;
        fichier1 << j2.color() << endl;
        fichier1 << colonne << endl;
        fichier1 << ligne << endl;
        fichier1 << hauteurMax << endl;
        for (short i = 0; i < ligne; i++) {
            for (short j = 0; j < colonne; j++) {
                if (board[i][j] != NULL) {
                    fichier1 << "*" << endl;
                    fichier1 << board[i][j]->positionLigne << endl;
                    fichier1 << board[i][j]->positionColonne << endl;
                    fichier1 << board[i][j]->hauteur << endl;
                    fichier1 << board[i][j]->qui << endl;
                } else {
                    fichier1 << "N" << endl;
                    fichier1 << i << endl;
                    fichier1 << j << endl;
                }
            }
        }
        fichier1.close();//on referme le fichier
    } else {
        cerr << "Erreur à l'ouverture !" << endl;
    }
}

void Plateau::saveSlot3(short slot, Joueur j1, Joueur j2, short hauteurMax) {
    //déclaration du flux et ouverture du fichier selon le slot
    fstream fichier1("Slot3.s", ios::out | ios::trunc);

    if (fichier1) {//si l'ouverture a réussi
        fichier1 << j1.name() << endl;
        fichier1 << j1.color() << endl;
        fichier1 << j2.name() << endl;
        fichier1 << j2.color() << endl;
        fichier1 << colonne << endl;
        fichier1 << ligne << endl;
        fichier1 << hauteurMax << endl;
        for (short i = 0; i < ligne; i++) {
            for (short j = 0; j < colonne; j++) {
                if (board[i][j] != NULL) {
                    fichier1 << "*" << endl;
                    fichier1 << board[i][j]->positionLigne << endl;
                    fichier1 << board[i][j]->positionColonne << endl;
                    fichier1 << board[i][j]->hauteur << endl;
                    fichier1 << board[i][j]->qui << endl;
                } else {
                    fichier1 << "N" << endl;
                    fichier1 << i << endl;
                    fichier1 << j << endl;
                }
            }
        }
        fichier1.close();//on referme le fichier
    } else {
        cerr << "Erreur à l'ouverture !" << endl;
    }
}

void Plateau::save(short slot, Joueur j1, Joueur j2, short hauteurMax) {
    if (slot == 1) {
        saveSlot1(slot, j1, j2, hauteurMax);
    } else if (slot == 2) {
        saveSlot2(slot, j1, j2, hauteurMax);
    } else if (slot == 3) {
        saveSlot3(slot, j1, j2, hauteurMax);
    } else {
        cout << "Erreur slot fonction save" << endl;
    }
}

void Plateau::aff() {
    system("clear");
    //Mise en forme
    cout << endl;
    cout << "     ";
    for (short i = 0; i < colonne; i++) {
        cout << "   " << i << "  ";
    }
    cout << endl;
    cout << "     |";
    for (short i = 1; i < colonne + 1; i++) {
        cout << "__A__|";
    }
    cout << endl << endl;

    //Affichage
    for (short i = 0; i < ligne; i++) {
        cout << " " << i << "=> | ";
        for (short j = 0; j < colonne; j++) {
            if (board[i][j] != NULL) {
                if (board[i][j]->qui == 0) {
                    cout << "\E[31;1m(" << board[i][j]->hauteur << ")\E[m" << " | ";
                } else {
                    cout << "(" << board[i][j]->hauteur << ")" << " | ";
                }
            } else {
                cout << "      ";
            }
        }
        cout << " | <= " << i;
        cout << endl << endl;
    }
}

bool Plateau::caseVide(short x, short y) {
    if (coordonnesPlateauValide(x, y)) {
        if (board[x][y] == NULL) {
            return true;
        } else {
            return false;
        }
    }
}

bool Plateau::selectionValide(short x, short y, short hauteurMax)//si mouvement possible
{
    if (coordonnesPlateauValide(x, y)) {
        for (short i = 0; i < ligne; i++) {
            for (short j = 0; j < colonne; j++) {
                if (!caseVide(x, y)) {
                    if (deplacementValide(x, y, i, j, hauteurMax)) {
                        return true;//si il y a des déplacement possible alors return true
                    }
                }
            }
        }
        return false;
    } else {
        return false;
    }
}

bool Plateau::pionHauteurMax(short x, short y, short hauteurMax) {
    if (coordonnesPlateauValide(x, y)) {
        if (board[x][y]->hauteur == hauteurMax) {
            return true;
        } else {
            return false;
        }
    }
}

bool Plateau::coordonnesPlateauValide(short x, short y) {/*x<0 || y<0 || x>10 || y>10*/
    if (x < 0) {
        return false;
    } else if (y < 0) {
        return false;
    } else if (x > ligne - 1) {
        return false;
    } else if (y > colonne - 1) {
        return false;
    } else {
        return true;
    }
}

bool Plateau::deplacementValide(short x, short y, short a, short b, short hauteurMax) {
    if (caseVide(x, y)) {
        return false;
    }
    if (caseVide(a, b)) {
        return false;
    }
    if (!coordonnesPlateauValide(a, b)) {
        return false;
    }

    if ((board[a][b]->hauteur + board[x][y]->hauteur) > hauteurMax) {
        return false;
    }

    if ((x + 1 != a) && (x != a) && (x - 1 != a)) {
        return false;

    } else if ((y + 1 != b) && (y != b) && (y - 1 != b)) {
        return false;

    } else if ((x == a) && (y == b)) {
        return false;

    } else {
        return true;
    }
}

void Plateau::leDeplacement(short x, short y, short a, short b) {
    if (board[x][y]->qui == 0) {
        board[a][b]->qui = 0;
        board[a][b]->hauteur = board[a][b]->hauteur + board[x][y]->hauteur;
        board[x][y] = NULL;
    } else {
        board[a][b]->qui = 1;
        board[a][b]->hauteur = board[a][b]->hauteur + board[x][y]->hauteur;
        board[x][y] = NULL;
    }
}

bool Plateau::possible(short hauteurMax) {
    for (short i = 0; i < ligne; i++) {
        for (short j = 0; j < colonne; j++) {
            for (short k = 0; k < ligne; k++) {
                for (short l = 0; l < colonne; l++) {
                    if (board[i][j] != NULL) {
                        if (deplacementValide(i, j, k, l, hauteurMax)) {
                            return true;//si il n'y a plus de déplacement possible alors return false pour arreter la boucle while
                        }
                    }
                }
            }
        }
    }
    return false;
}

void Plateau::compterPoints(Joueur j1, Joueur j2) {
    short scoreJ1 = 0;
    short scoreJ2 = 0;
    for (short i = 0; i < ligne; i++) {
        for (short j = 0; j < colonne; j++) {
            if (board[i][j] != NULL) {
                if (board[i][j]->qui == 0) {
                    scoreJ1++;
                } else {
                    scoreJ2++;
                }
            }
        }
    }
    cout << endl;
    if (scoreJ1 == scoreJ2) {
        cout << "Il y a égalité" << endl;
    } else if (scoreJ1 < scoreJ2) {
        cout << j2.name() << "A gagner la partie (J2: " << scoreJ2 << " ; J1: " << scoreJ1 << " )" << endl;
    } else {
        cout << j1.name() << "A gagner la partie (J1: " << scoreJ1 << " ; J2: " << scoreJ2 << " )" << endl;
    }
}

short Plateau::getColonne() {
    return colonne;
}

short Plateau::getLigne() {
    return ligne;
}

void Plateau::inverseCouleur() {
    for (short i = 0; i < ligne; i++) {
        for (short j = 0; j < colonne; j++) {
            if (board[i][j] != NULL) {
                if (board[i][j]->qui == 0) {
                    board[i][j]->qui = 1;
                } else {
                    board[i][j]->qui = 0;
                }
            }
        }
    }
}

bool Plateau::scoringIA(short IA) {
    short scoreJ1 = 0;
    short scoreJ2 = 0;
    for (short i = 0; i < ligne; i++) {
        for (short j = 0; j < colonne; j++) {
            if (board[i][j] != NULL) {
                if (board[i][j]->qui == IA) {//si le pion est a l'ia en question
                    scoreJ1++;
                } else {
                    scoreJ2++;
                }
            }
        }
    }
    if (scoreJ1 > scoreJ2) {
        return true;//l'ia en question est representé par scoreJ1 donc si il est plus grand que scoreJ2 c'est bien
    } else {
        return false;
    }
}

bool Plateau::algoIA(short &hauteurMax, short &difficulte, short &p, short note[][11][11][11][11],
                     short IA) {//Coupure alpha beta
    if (p == difficulte) {
        return scoringIA(IA);
    }

    p++;
    short ligne = getLigne();
    short colonne = getColonne();
    Plateau second(*this);
    short meilleurNote = 0;

    for (short i = 0; i < ligne; i++) {
        for (short j = 0; j < colonne; j++) {
            for (short k = 0; k < ligne; k++) {
                for (short l = 0; l < colonne; l++) {
                    //remplissage des notes dans un tableau qui contien en i,j la case selection et k,l la case destination
                    short pTMP = 1;
                    short notation = 0;
                    note[p][i][j][k][l] = second.MinMax(i, j, k, l, hauteurMax, pTMP, IA, notation);
                    if (meilleurNote < note[p][i][j][k][l]) {
                        meilleurNote = note[p][i][j][k][l];
                    }
                }
            }
        }
    }

    for (short i = 0; i < ligne; i++) {//effectue le deplacement si la note est bonne
        for (short j = 0; j < colonne; j++) {
            for (short k = 0; k < ligne; k++) {
                for (short l = 0; l < colonne; l++) {
                    if (note[p][i][j][k][l] == meilleurNote) {
                        second.leDeplacement(i, j, k, l);
                        //second.aff();
                        if (IA == 0) {
                            IA = 1;
                        } else {
                            IA = 0;
                        }
                        second.algoIA(hauteurMax, difficulte, p, note, IA);
                        return scoringIA(IA);
                    }
                }
            }
        }
    }
}

short Plateau::MinMax(short &i, short &j, short &k, short &l, short &hauteurMax, short &p, short &IA,
                      short &notation) {//le min max
    if (p == difficulte) {
        return notation;
    }
    if (p % 2 != 0) {//si la profondeur est impair alors c'est l'ia donc max

        if (deplacementValide(i, j, k, l, hauteurMax)) {
            if (board[i][j]->qui == IA) {
                if ((board[i][j]->hauteur + board[k][l]->hauteur == hauteurMax) && p == 1) {
                    //si des la premiere profondeur je peux faire une tour de 5 alors c'est ceux qu'il faut faire
                    p++;
                    notation = notation + 32000;
                    return notation;
                }

                short unDesTestIA = 0;
                for (short m = 0; m < ligne; m++) {
                    for (short n = 0; n < colonne; n++) {
                        if (!deplacementValide(k, l, m, n, hauteurMax)) {
                            if (p == 1) {
                                //si la tour de destination se retrouve isolé alors c'est un bon score
                                unDesTestIA++;
                            }
                        }
                    }
                }
                if (unDesTestIA == 80) {
                    notation = notation + 20000;
                    p++;
                    return notation;
                }

                if (board[i][j]->hauteur + board[k][l]->hauteur == hauteurMax) {
                    notation = notation + 500;
                    p++;
                    return MinMax(i, j, k, l, hauteurMax, p, IA, notation);

                } else if (board[i][j]->hauteur + board[k][l]->hauteur == hauteurMax - 1) {
                    notation = notation - 80;//pas important car pion qui peu etre volé !
                    p++;
                    return MinMax(i, j, k, l, hauteurMax, p, IA, notation);

                } else if (board[i][j]->hauteur + board[k][l]->hauteur == hauteurMax - 2) {
                    notation = notation + 30;
                    p++;
                    return MinMax(i, j, k, l, hauteurMax, p, IA, notation);
                }
            }
        }

    } else if (p % 2 == 0) {// si la profondeur est pair alors c'est le joueur donc c'est min
        if (deplacementValide(i, j, k, l, hauteurMax)) {
            if (board[i][j]->hauteur + board[k][l]->hauteur == hauteurMax) {
                notation = notation - 200;
                p++;
                return MinMax(i, j, k, l, hauteurMax, p, IA, notation);

            } else if (board[i][j]->hauteur + board[k][l]->hauteur == hauteurMax - 1) {
                notation = notation + 10;//si il joue comme ca, c'est bien pour l'ia
                p++;
                return MinMax(i, j, k, l, hauteurMax, p, IA, notation);

            } else {
                notation = notation - 10;
                p++;
                return MinMax(i, j, k, l, hauteurMax, p, IA, notation);

            }
        }
    }
    p++;
    notation = notation - 100;
    return MinMax(i, j, k, l, hauteurMax, p, IA, notation);
}

/*
short Plateau::MinMax(short& i, short& j, short& k, short& l, short& hauteurMax, short& p, short& IA)
{//le min max
    short notation = 1;
    if(p%2 != 0 ){//si la profondeur est impair alors c'est l'ia donc max

        if(deplacementValide(i,  j,  k,  l,  hauteurMax)){
            if(board[i][j]->qui == IA){
                if((board[i][j]->hauteur + board[k][l]->hauteur == hauteurMax) && p==1){
                    //si des la premiere profondeur je peux faire une tour de 5 alors c'est ceux qu'il faut faire
                    notation = notation + 32000;
                    return notation;
                }

                short unDesTestIA = 0;
                for(short m=0 ; m<ligne ; m++){
                    for(short n=0 ; n<colonne ; n++){
                        if(!deplacementValide(k,l,m,n, hauteurMax)){
                            if(p == 1){
                            //si la tour de destination se retrouve isolé alors c'est un bon score
                                unDesTestIA++;
                            }
                        }
                    }
                }
                if(unDesTestIA == 80 ){
                    notation = notation + 20000;
                    return notation;
                }

                if(board[i][j]->hauteur + board[k][l]->hauteur == hauteurMax){
                    notation = notation + 100;
                    return notation;

                }else if(board[i][j]->hauteur+board[k][l]->hauteur == hauteurMax-1){
                    notation = notation - 80;//pas important car pion qui peu etre volé !
                    return notation;

                }else if(board[i][j]->hauteur+board[k][l]->hauteur == hauteurMax-2){
                    notation = notation + 30;
                    return notation;

                }else if(board[i][j]->hauteur+board[k][l]->hauteur == hauteurMax-3){
                    notation = notation + 20;
                    return notation;

                }else{
                    notation = notation + 1;
                    return notation;

                }
            }
        }
        
    }else if(p%2 == 0){// si la profondeur est pair alors c'est le joueur donc c'est min
        if(deplacementValide(i,  j,  k,  l,  hauteurMax)){
            if(board[i][j]->hauteur+board[k][l]->hauteur == hauteurMax){
                notation = notation - 200;
                return notation;

            }else if(board[i][j]->hauteur+board[k][l]->hauteur == hauteurMax-1){
                notation = notation + 10;//si il joue comme ca, c'est bien pour l'ia
                return notation;

            }else{
                notation = notation - 10;
                return notation;

            }
        }
    }
    return -32000;
}*/

bool Plateau::NoteNonConcluante(short IA, short hauteurMax) {
    for (short i = 0; i < ligne; i++) {
        for (short j = 0; j < colonne; j++) {
            for (short k = 0; k < ligne; k++) {
                for (short l = 0; l < colonne; l++) {
                    if (!caseVide(i, j)) {
                        if (deplacementValide(i, j, k, l, hauteurMax)) {
                            if (board[i][j]->qui == IA) {
                                leDeplacement(i, j, k, l);
                                cout << "Pas de note concluante ..." << endl;
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}