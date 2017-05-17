#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <unistd.h>
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "../HEADER/Pion.h"
#include "../HEADER/Joueur.h"
#include "../HEADER/Plateau.h"
#include "../HEADER/fonction.h"

using namespace std;
using namespace sf;

#define largeurConsole 80

void jouer() {
    while (1) {
        system("clear");
        affMenu();
        short faire = selection();
        switch (faire) {
            case (1): {//Nouveau Jeu
                system("clear");
                short slot = selectionSlot(1);
                system("clear");
                bool victoire = false;
                while (victoire == false) {
                    victoire = partie(slot);
                }
                break;
            }
            case (2): {//Charger Jeu
                system("clear");
                short slot = selectionSlot(2);
                system("clear");
                if (slot != -1) {
                    bool victoire = false;
                    while (victoire == false) {
                        victoire = charger(slot);
                    }
                }
                break;
            }
            case (3): {//Afficher les regles du jeu
                system("clear");
                regle();
                break;
            }
            case (4): {//Interface SFML
                interface();
                system("clear");
                break;
            }
            case (5): {//Quitter
                system("clear");
                return;
                break;
            }
            default: {//easter egg si autre que choix menu =P
                quaranteDeux();
                break;
            }
        }
    }
}

void affMenu() {

    centre();
    cout << "\E[31;1m" << "┌─────────────────────────────────────┐" << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│       ___                           │" << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│      / \\ \\       " << "\E[32;1mAVALAM" << "\E[m" << "\E[31;1m" << "             │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│     / /_\\_\\        " << "\E[32;1mBy" << "\E[m" << "\E[31;1m" << "               │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│     \\/____/      " << "\E[32;1mPIERRE" << "\E[m" << "\E[31;1m" << "             │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
}

void affMenu2() {

    centre();
    cout << "\E[31;1m" << "┌─────────────────────────────────────┐" << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│       ___                           │" << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│      / \\ \\       " << "\E[32;1mAVALAM" << "\E[m" << "\E[31;1m" << "             │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│     / /_\\_\\        " << "\E[32;1mBy" << "\E[m" << "\E[31;1m" << "               │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│     \\/____/      " << "\E[32;1mPIERRE" << "\E[m" << "\E[31;1m" << "             │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "└─────────────────────────────────────┘" << "\E[m" << endl;
}

int selection() {

    centre();
    cout << "\E[31;1m" << "├─────────────────────────────────────┤" << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│            " << "\E[34;1mNouveau Jeu (1)" << "\E[m" << "\E[31;1m" << "          │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│            " << "\E[35;1mCharger jeu (2) " << "\E[m" << "\E[31;1m" << "         │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│            " << "\E[35;1mRegle du jeu(3)" << "\E[m" << "\E[31;1m" << "          │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│        " << "\E[35;1mInterface (4) (en cours)" << "\E[m" << "\E[31;1m" << "     │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│              " << "\E[36;1mQuitter (5)" << "\E[m" << "\E[31;1m" << "            │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│        " << "\E[36;1mVous pouvez quitter à " << "\E[m" << "\E[31;1m" << "       │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│      " << "\E[36;1mtous moments en entrant 99" << "\E[m" << "\E[31;1m" << "     │"
         << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
    centre();
    cout << "\E[31;1m" << "└─────────────────────────────────────┘" << "\E[m" << endl;
    short faire = testSiNombre();

    return faire;
}

void lectureMusique(Music &maMusic) {
    if (!maMusic.openFromFile("../data/music.ogg")) {
        return; // erreur
    }
    maMusic.setVolume(35);
    maMusic.setLoop(true);
    maMusic.play();
}

void centre() {
    for (short i = 0; i < (largeurConsole - 40) / 2; i++) {
        cout << " ";
    }
}

void regle() {
    centre();
    cout << "              ┌─────────┐" << endl;
    centre();
    cout << "              │  \E[31;1mRegle\E[m  │" << endl;
    centre();
    cout << "┌─────────────┴─────────┴─────────────┐" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ \E[31;1mBASE\E[m                                │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ Chaque joueur choisit sa couleur    │" << endl;
    centre();
    cout << "│ Le but du jeu est de constituer     │" << endl;
    centre();
    cout << "│ un maximum de tours de 1 à 5 pions, │" << endl;
    centre();
    cout << "│ jamais plus, surmontées par un      │" << endl;
    centre();
    cout << "│ pion de sa couleur.                 │" << endl;
    centre();
    cout << "│ Un joueur est le propriétaire       │" << endl;
    centre();
    cout << "│ d'une tour lorsqu'un pion de sa     │" << endl;
    centre();
    cout << "│ couleur en occupe le sommet.        │" << endl;
    centre();
    cout << "│ Un pion isolé constitue             │" << endl;
    centre();
    cout << "│ également une tour.                 │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│     Page 1/5 appuyer sur entree     │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "└─────────────────────────────────────┘" << endl;
    system("read _");
    system("clear");
    centre();
    cout << "              ┌─────────┐" << endl;
    centre();
    cout << "              │  \E[31;1mRegle\E[m  │" << endl;
    centre();
    cout << "┌─────────────┴─────────┴─────────────┐" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ \E[31;1mDEPLACEMENTS\E[m                        │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ Chaque joueur en effectue un        │" << endl;
    centre();
    cout << "│ seul, dans n'importe quel sens      │" << endl;
    centre();
    cout << "│ (horizontal, vertical, diagonal)    │" << endl;
    centre();
    cout << "│ avec n'importe quel pion (ou        │" << endl;
    centre();
    cout << "│ pile de pions), quelle qu'en soit   │" << endl;
    centre();
    cout << "│ la couleur. Ce mouvement            │" << endl;
    centre();
    cout << "│ consiste à empiler le ou les        │" << endl;
    centre();
    cout << "│ pions déplacés sur un trou          │" << endl;
    centre();
    cout << "│ directement voisin déjà occupé      │" << endl;
    centre();
    cout << "│ par un ou plusieurs pions.          │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│     Page 2/5 appuyer sur entree     │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "└─────────────────────────────────────┘" << endl;
    system("read _");
    system("clear");
    centre();
    cout << "              ┌─────────┐" << endl;
    centre();
    cout << "              │  \E[31;1mRegle\E[m  │" << endl;
    centre();
    cout << "┌─────────────┴─────────┴─────────────┐" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ \E[31;1mMOUVEMENT INTERDIT\E[m                  │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ On déplace obligatoirement          │" << endl;
    centre();
    cout << "│ toute la pile se trouvant sur un    │" << endl;
    centre();
    cout << "│ troue (elle peut évidemment         │" << endl;
    centre();
    cout << "│ n'être constituée que d'un seul     │" << endl;
    centre();
    cout << "│ pion). Autrement dit, une pile      │" << endl;
    centre();
    cout << "│ de pions ne peut qu'augmenter,      │" << endl;
    centre();
    cout << "│ jamais diminuer.                    │" << endl;
    centre();
    cout << "│ On ne peut jamais poser de          │" << endl;
    centre();
    cout << "│ pions sur un trou inoccupé: il      │" << endl;
    centre();
    cout << "│ le reste donc définitivement.       │" << endl;
    centre();
    cout << "│ Un pion (ou une tour) isolé de      │" << endl;
    centre();
    cout << "│ tous les cotés ne pourra donc       │" << endl;
    centre();
    cout << "│ plus changer de propriétaire.       │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│     Page 3/5 appuyer sur entree     │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "└─────────────────────────────────────┘" << endl;
    system("read _");
    system("clear");
    centre();
    cout << "              ┌─────────┐" << endl;
    centre();
    cout << "              │  \E[31;1mRegle\E[m  │" << endl;
    centre();
    cout << "┌─────────────┴─────────┴─────────────┐" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ \E[31;1mFIN DE PARTIE\E[m                       │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ Tans qu'un joueur peut effectuer    │" << endl;
    centre();
    cout << "│ un mouvement il a l'obligation de   │" << endl;
    centre();
    cout << "│ jouer,  la partie ne s'achevant     │" << endl;
    centre();
    cout << "│ que lorque plus aucun déplacement   │" << endl;
    centre();
    cout << "│ n'est possible.                     │" << endl;
    centre();
    cout << "│ On compte alors combien de pions    │" << endl;
    centre();
    cout << "│ de chaque couleur occupent le       │" << endl;
    centre();
    cout << "│ sommet des tours restantes, le      │" << endl;
    centre();
    cout << "│ vainqueur étant évidemment          │" << endl;
    centre();
    cout << "│ celui qui en totalise le plus.      │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ /!\\ Qu'une tour comporte 1,2, ou 5  │" << endl;
    centre();
    cout << "│ pions, elle vaut toujours UN point. │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│     Page 4/5 appuyer sur entree     │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "└─────────────────────────────────────┘" << endl;
    system("read _");
    system("clear");
    commentJouer();
}

void commentJouer() {
    centre();
    cout << "              ┌─────────┐" << endl;
    centre();
    cout << "              │  \E[31;1mRegle\E[m  │" << endl;
    centre();
    cout << "┌─────────────┴─────────┴─────────────┐" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ \E[31;1mPOUR JOUER\E[m                          │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│ Entrez les coordonnés du pion a     │" << endl;
    centre();
    cout << "│ déplacer, puis les coordonnés de    │" << endl;
    centre();
    cout << "│ la position souhaitez.              │" << endl;
    centre();
    cout << "│ Inversés les couleurs des joueur    │" << endl;
    centre();
    cout << "│ en entrant pour x 100 et pour y 100 │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "│     Page 5/5 appuyer sur entree     │" << endl;
    centre();
    cout << "│                                     │" << endl;
    centre();
    cout << "└─────────────────────────────────────┘" << endl;
    system("read _");
}

void quaranteDeux() {
    system("clear");
    cout << ".D$$$$" << endl;
    cout << "NN$$$$D  ZN .NDDD. ~  .ZDN$." << endl;
    cout << "D$$$$D8           ..DND$$$$D." << endl;
    cout << " NON           :DN$$$$$$$$$$DN" << endl;
    cout << " N....      ODD$$$$$$$$$$$DDZDI," << endl;
    cout << " D:NN  ..NDO$$$$$$$$$NDN$$$Z$$$$$$$O7." << endl;
    cout << " N.   .DD$$$$$$$$$DDD$$$8$$$$$$$$$$O$$7" << endl;
    cout << " D .DD$$$$$$$$OD8N$$$O$$$$$NDO$$$D$$$N." << endl;
    cout << " D$$$NN$$INZ=,,,,N$$$$$$$$$$$NDDD$$$N$~" << endl;
    cout << " .ND$$DZ$D=D,,,,,,,DDDDDN=D,,N$N$NDD$N." << endl;
    cout << "   ~$$ND8,,NDDN,,,,,,,,DDNDN,,N$$ND.ND." << endl;
    cout << "   .D$D,,DD.   ND=,,,DN.   .DZZOZ8D," << endl;
    cout << "  =,:DDODD      .D,,D7      .N,?D,,8" << endl;
    cout << "  D,N,NDD.   o   DDDD    o   NDN,D,D." << endl;
    cout << "   N.N,,D~       D,,DI       N,D,D:" << endl;
    cout << "     N,D,N.     ND,,,DN.  ..DND,ND" << endl;
    cout << "     N,D,,NDDDND:,,,,,,DNNDD,,D,N" << endl;
    cout << "     .N,D,,,,,,,,,DDD,,,,,,,,N,,D" << endl;
    cout << "       ,D,,,D,,,,,,,,,,,,,,D,,,D," << endl;
    cout << "        DDD,,,,,,,,,,,,,,,,,,DDD" << endl;
    cout << "          ~,,,,,N,,,,,N,,,,,8" << endl;
    cout << "           D,,,,,NDDND,,,,,D" << endl;
    cout << "            D,,,,,,,,,,,,,D" << endl;
    cout << "            .N,,,,,,,,,,,N." << endl;
    cout << "               DDNDDDDDD." << endl;
    system("read _");
}

void intro() {
    for (short i = 0; i < 5; i++) {
        system("clear");
        if (i == 0) {
            centre();
            cout << "\E[31;1m" << "┌─────────────────────────────────────┐" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│       ___                           │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│      / \\ \\       " << "\E[32;1mAVALAM" << "\E[m" << "\E[31;1m"
                 << "             │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│     / /_\\_\\      " << "\E[32;1mLE" << "\E[m" << "\E[31;1m"
                 << "                 │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│     \\/____/      " << "\E[32;1mJEU " << "\E[m" << "\E[31;1m" << "               │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "└─────────────────────────────────────┘" << "\E[m" << endl;
            usleep(1100000);
        } else if (i == 1) {
            centre();
            cout << "\E[31;1m" << "┌─────────────────────────────────────┐" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│               " << "\E[32;1mO   O" << "\E[m" << "\E[31;1m" << "                 │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                " << "\E[32;1m o " << "\E[m" << "\E[31;1m" << "                  │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│               " << "\E[32;1m\\___/" << "\E[m" << "\E[31;1m" << "                 │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "└─────────────────────────────────────┘" << "\E[m" << endl;
        } else if (i == 2) {
            centre();
            cout << "\E[31;1m" << "┌─────────────────────────────────────┐" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│               " << "\E[32;1mO   -" << "\E[m" << "\E[31;1m" << "                 │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                " << "\E[32;1m o " << "\E[m" << "\E[31;1m" << "                  │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│               " << "\E[32;1m\\___/" << "\E[m" << "\E[31;1m" << "                 │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "└─────────────────────────────────────┘" << "\E[m" << endl;
        } else if (i == 3) {
            centre();
            cout << "\E[31;1m" << "┌─────────────────────────────────────┐" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│               " << "\E[32;1mO   O" << "\E[m" << "\E[31;1m" << "                 │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                " << "\E[32;1m o " << "\E[m" << "\E[31;1m" << "                  │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│               " << "\E[32;1m\\___/" << "\E[m" << "\E[31;1m" << "                 │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "└─────────────────────────────────────┘" << "\E[m" << endl;
        } else {
            centre();
            cout << "\E[31;1m" << "┌─────────────────────────────────────┐" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│       ___        " << "\E[32;1mAVALAM" << "\E[m" << "\E[31;1m" << "             │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│      / \\ \\         " << "\E[32;1mBy" << "\E[m" << "\E[31;1m"
                 << "               │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│     / /_\\_\\      " << "\E[32;1mPIERRE" << "\E[m" << "\E[31;1m"
                 << "             │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│     \\/____/    " << "\E[32;1mversion 1.6" << "\E[m" << "\E[31;1m" << "          │"
                 << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "│                                     │" << "\E[m" << endl;
            centre();
            cout << "\E[31;1m" << "└─────────────────────────────────────┘" << "\E[m" << endl;
            usleep(1100000);
        }
        usleep(400000);
    }
}

short choixRegle() {
    cout << "La hauteur maximale d'un pion est de 5, voulez vous changez cette valeur ? (1/0)" << endl;
    short x = 0;
    while (1) {
        x = testSiNombre();
        if (x == 0) {
            return 5;
        } else if (x == 1) {
            do {
                cout << "Quel est la hauteur que vous souhaitez ? (comprise entre 2 et 9)" << endl;
                x = testSiNombre();
            } while (x < 2 || x > 9);
            return x;
        } else {
            cout << "Choix non compris..." << endl;
        }
    }
}

short testSiNombre() {
    short test = 0;
    while (!(cin >> test)) { // on rentre quelque chose qui doit etre de type short (vu l'initialisation de la variable)
        string tmp;
        cin.clear();//vide le cin
        cin >> tmp;//on donne tmp a cin
        cout << "=> Choix Incorrect <=" << endl;
    }//tant que c'est pas un short
    if (test == 99) {
        exit(0);
    }
    return test;
}

bool partie(short slot) {
    affMenu2();
    Music monSon;
    if (!monSon.openFromFile("../data/sound.ogg")) {
        cerr << "Pas de son !" << endl;
    }

    Plateau first;
    short hauteurMax = choixRegle();

    cout << "Jouez contre l'ordinateur (1) " << endl;
    cout << "Jouez contre un ami (2)" << endl;
    short contreIA = testSiNombre();

    if (contreIA == 1) {
        cout << "Joueur 1 entrez votre pseudo : ";
        string nom;
        cin >> nom;
        nom = "\E[31;1m" + nom + "\E[m";
        Joueur j1(nom, 0);
        cout << "Bonjour " << j1.name() << endl;

        Joueur IA("IA84000", 1);
        cout << "Vous jourez contre : " << IA.name() << endl;
        cout << "Appuyer sur entrer " << endl;
        system("read _");

        while (first.possible(hauteurMax)) {
            first.save(slot, j1, IA, hauteurMax);
            first.aff();
            first = deplacement(j1, first, hauteurMax);
            monSon.play();
            first.save(slot, j1, IA, hauteurMax);
            first.aff();
            cout << "L'ia va jouer quand vous appuyer sur entre" << endl;
            system("read _");
            first = deplacementIA(first, hauteurMax, difficulte, 1);
            monSon.play();
            first.aff();
        }
        first.compterPoints(j1, IA);

    } else if (contreIA == 2) {
        cout << "Joueur 1 entrez votre pseudo : ";
        string nom;
        cin >> nom;
        nom = "\E[31;1m" + nom + "\E[m";
        Joueur j1(nom, 0);
        cout << "Bonjour " << j1.name() << endl;

        cout << "Joueur 2 entrez votre pseudo : ";
        cin >> nom;
        Joueur j2(nom, 1);
        cout << "Bonjour " << j2.name() << endl;
        cout << "Appuyer sur entrer " << endl;
        system("read _");

        while (first.possible(hauteurMax)) {
            first.save(slot, j1, j2, hauteurMax);
            first.aff();
            first = deplacement(j1, first, hauteurMax);
            monSon.play();
            first.save(slot, j1, j2, hauteurMax);
            first.aff();
            first = deplacement(j2, first, hauteurMax);;
            monSon.play();
            first.aff();
        }
        first.compterPoints(j1, j2);

    } else if (contreIA == 42) {
        Joueur j1("IA1", 0);
        Joueur j2("IA2", 1);

        while (first.possible(hauteurMax)) {
            first.save(slot, j1, j2, hauteurMax);
            first.aff();
            first = deplacementIA(first, hauteurMax, difficulte, 0);
            monSon.play();
            first.save(slot, j1, j2, hauteurMax);
            first.aff();
            first = deplacementIA(first, hauteurMax, difficulte, 1);
            monSon.play();
            first.aff();
        }
        first.compterPoints(j1, j2);
    } else {
        cout << endl;
        cout << "Choix non compris" << endl;
    }

    cout << endl;
    cout << "Appuyer sur entrée pour un retour au menu" << endl;

    system("read _");
    return true;
}

short selectionSlot(short unOuDeux) {
    affMenu2();
    if (unOuDeux == 1) {//pour les nouvelle partie
        short slot = 0;
        while (slot != 1 && slot != 2 && slot != 3) {
            cout << "Quel slot de sauvegarde souhaitez vous ? : " << endl;
            cout << "Slot 1 (1) ?" << endl;
            cout << "Slot 2 (2) ?" << endl;
            cout << "Slot 3 (3) ?" << endl;
            slot = testSiNombre();
        }
        return slot;
    } else {//pour charger une partie
        short slot = 0;
        fstream fichier1("Slot1.s");
        fstream fichier2("Slot2.s");
        fstream fichier3("Slot3.s");
        while ((slot != 1 && slot != 2 && slot != 3)) {
            cout << "Quel slot de sauvegarde souhaitez vous ? : " << endl;
            cout << "Slot 1 (1) ?" << endl;
            cout << "Slot 2 (2) ?" << endl;
            cout << "Slot 3 (3) ?" << endl;
            cout << "Retour menu (4)" << endl;
            slot = testSiNombre();
            if (slot == 1) {
                if (testSiFichierVide("Slot1.s")) {
                    slot = 0;
                    cout << "Sauvegarde vide ..." << endl;

                }
            } else if (slot == 2) {
                if (testSiFichierVide("Slot2.s")) {
                    slot = 0;
                    cout << "Sauvegarde vide ..." << endl;
                }
            } else if (slot == 3) {
                if (testSiFichierVide("Slot3.s")) {
                    slot = 0;
                    cout << "Sauvegarde vide ..." << endl;
                }
            } else {
                return -1;
            }
        }
        return slot;
    }
}

bool testSiFichierVide(char const *slot) {
    FILE *leFichier = fopen(slot, "r");

    if (leFichier) {
        (void) fgetc(leFichier);
        if (feof(leFichier)) {
            fclose(leFichier);
            return true;
        }
        fclose(leFichier);
    }
    return false;
}

bool charger(short slot) {
    vector <string> monTableau;
    if (slot == 1) {
        monTableau = constructionTableau1(monTableau);
    } else if (slot == 2) {
        monTableau = constructionTableau2(monTableau);

    } else if (slot == 3) {
        monTableau = constructionTableau3(monTableau);

    }

    Joueur j1(monTableau, 0);
    Joueur j2(monTableau, 1);
    short hauteurMax = atoi(monTableau[6].c_str());
    Plateau second(monTableau);

    bool result = chargerPartie(second, j1, j2, hauteurMax, slot);
    return result;

}

vector <string> constructionTableau1(vector <string> monTableau) {
    fstream fichier1("Slot1.s");
    if (fichier1) {//si l'ouverture a réussi
        while (!fichier1.eof()) {
            monTableau.push_back("");//creation d'une ligne vide
            getline(fichier1, monTableau.back());//lecture d'une ligne du fichier
            int ligne = monTableau.size() - 1;//je recupere la taille du tableau (-1 pour la ligne 0)
            if (monTableau[ligne].empty()) {//si la ligne est vide
                monTableau.pop_back();//on la retire du tableau
            }
        }
        fichier1.close();//on referme le fichier
        return monTableau;
    }
}

vector <string> constructionTableau2(vector <string> monTableau) {
    fstream fichier1("Slot2.s");
    if (fichier1) {//si l'ouverture a réussi
        while (!fichier1.eof()) {
            monTableau.push_back("");//creation d'une ligne vide
            getline(fichier1, monTableau.back());//lecture d'une ligne du fichier
            int ligne = monTableau.size() - 1;//je recupere la taille du tableau (-1 pour la ligne 0)
            if (monTableau[ligne].empty()) {//si la ligne est vide
                monTableau.pop_back();//on la retire du tableau
            }
        }
        fichier1.close();//on referme le fichier
        return monTableau;
    }
}

vector <string> constructionTableau3(vector <string> monTableau) {
    fstream fichier1("Slot3.s");
    if (fichier1) {//si l'ouverture a réussi
        while (!fichier1.eof()) {
            monTableau.push_back("");//creation d'une ligne vide
            getline(fichier1, monTableau.back());//lecture d'une ligne du fichier
            int ligne = monTableau.size() - 1;//je recupere la taille du tableau (-1 pour la ligne 0)
            if (monTableau[ligne].empty()) {//si la ligne est vide
                monTableau.pop_back();//on la retire du tableau
            }
        }
        fichier1.close();//on referme le fichier
        return monTableau;
    }
}

bool chargerPartie(Plateau second, Joueur j1, Joueur j2, short hauteurMax, short slot) {
    Music monSon;
    if (!monSon.openFromFile("../data/sound.ogg")) {
        cerr << "Pas de son !" << endl;
    }

    if (j2.name() != "IA84000" && j1.name() != "IA84000") {
        cout << "Bonjour " << j1.name() << endl;
        cout << "Bonjour " << j2.name() << endl;
        cout << "La Hauteur max de cette partie etait de " << hauteurMax << endl;
        cout << "Appuyer sur entree pour continue" << endl;
        system("read _");

        while (second.possible(hauteurMax)) {
            second.save(slot, j1, j2, hauteurMax);
            second.aff();
            second = deplacement(j1, second, hauteurMax);
            monSon.play();
            second.save(slot, j1, j2, hauteurMax);
            second.aff();
            second = deplacement(j2, second, hauteurMax);
            monSon.play();
            second.aff();
        }
    } else {
        cout << "Bonjour " << j1.name() << endl;
        cout << "Vous jouerais contre " << j2.name() << endl;
        cout << "La Hauteur max de cette partie etait de " << hauteurMax << endl;
        cout << "Appuyer sur entree pour continue" << endl;
        system("read _");

        while (second.possible(hauteurMax)) {
            second.save(slot, j1, j2, hauteurMax);
            second.aff();
            second = deplacement(j1, second, hauteurMax);
            monSon.play();
            second.save(slot, j1, j2, hauteurMax);
            second.aff();
            cout << "L'ia va jouer quand vous appuyer sur entre" << endl;
            system("read _");
            second = deplacementIA(second, hauteurMax, 10, 1);
            monSon.play();
            second.aff();
        }
    }

    second.compterPoints(j1, j2);

    cout << endl;
    cout << "Appuyer sur entrée pour un retour au menu" << endl;


    system("read _");
    return true;
}

Plateau deplacement(Joueur j, Plateau first, short hauteurMax) {
    short x = 0;//coordoné du pion ligne
    short y = 0;//coordoné du pion colonne
    short a = 0;//coordoné du déplacement ligne
    short b = 0;//coordoné du déplacement colonne

    cout << j.name() << " Entrez les coordonnés du pion à déplacer (ligne puis colonne)" << endl;
    x = testSiNombre();
    y = testSiNombre();
    if (x == 100 && y == 100) {
        first.inverseCouleur();
        first.aff();
        cout << "Couleur des joueurs inversés." << endl;
    }

    while (!first.coordonnesPlateauValide(x, y) || !first.selectionValide(x, y, hauteurMax) || first.caseVide(x, y) ||
           first.pionHauteurMax(x, y, hauteurMax)) {
        if (x != 100 && y != 100) {
            cout << "Vous vous êtes trompé de coordonnés" << endl;
        }
        cout << j.name() << "Entrez les coordonnés du pion à déplacer (ligne puis colonne)" << endl;
        x = testSiNombre();
        y = testSiNombre();
    }

    cout << j.name() << "Entrez les coordonnés ou vous voulez le déplacer (ligne puis colonne)" << endl;
    a = testSiNombre();
    b = testSiNombre();
    if (a == 100 && b == 100) {
        first.inverseCouleur();
        first.aff();
        cout << "Couleur des joueurs inversés." << endl;
    }

    while (!first.deplacementValide(x, y, a, b, hauteurMax)) {
        if (a != 100 && b != 100) {
            cout << "Vous vous êtes trompé de coordonnés" << endl;
            first.affDeplacementDisponible(x, y, hauteurMax);
        }
        cout << j.name() << "Entrez les coordonnés ou vous voulez le déplacer (ligne puis colonne)" << endl;
        a = testSiNombre();
        b = testSiNombre();
    }

    first.leDeplacement(x, y, a, b);


    return first;
}

Plateau deplacementIA(Plateau first, short hauteurMax, short difficulte,
                      short IA)//fonction qui effectue le deplacement grace au min max
{
    short ligne = first.getLigne();
    short colonne = first.getColonne();
    short note[difficulte + 1][11][11][11][11];
    short best = 0;

    short p = 0;
    first.algoIA(hauteurMax, difficulte, p, note, IA);

    for (short i = 0; i < ligne; i++) {
        for (short j = 0; j < colonne; j++) {
            for (short k = 0; k < ligne; k++) {
                for (short l = 0; l < colonne; l++) {
                    if (note[1][i][j][k][l] > best) {
                        best = note[1][i][j][k][l];
                    }
                }
            }
        }
    }
    for (short i = 0; i < ligne; i++) {
        for (short j = 0; j < colonne; j++) {
            for (short k = 0; k < ligne; k++) {
                for (short l = 0; l < colonne; l++) {
                    if (note[1][i][j][k][l] == best) {
                        cout << "Meilleur Note de l'IA : " << best << " de (" << i << ";" << j << ") en (" << k << ";"
                             << l << ")" << endl;
                        first.leDeplacement(i, j, k, l);
                        return first;
                    }
                }
            }
        }
    }
    if (first.NoteNonConcluante(IA, hauteurMax)) {
        return first;
    }

    cerr << "Pas de possibilité pour l'ia, fin de parti ? (appuyer sur entre) " << endl;
    system("read _");
    return first;
}

void interface() {
    RenderWindow window;
    window.create(VideoMode(1024, 768), "Avalam By Pierre");
    window.setFramerateLimit(60);

    Image icon;
    if (!icon.loadFromFile("../data/icon.png")) {
        return;
    }
    window.setIcon(128, 128, icon.getPixelsPtr());

    while (window.isOpen()) {
        window.clear();
        Event evenement;
        while (window.pollEvent(evenement)) {
            if (evenement.type == Event::Closed) {
                window.close();
            }
        }
        window.display();
    }

}
