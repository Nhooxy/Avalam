#include <iostream>
#include <cstring>
#include <cstdlib>
#include "SFML/Audio.hpp"

#include "../HEADER/Pion.h"
#include "../HEADER/Joueur.h"
#include "../HEADER/Plateau.h"
#include "../HEADER/fonction.h"

using namespace std;
using namespace sf;

int main(int argc, char *argv[]) {
    Music maMusic;
    lectureMusique(maMusic);
    intro();
    jouer();

    return 0;
}
