#include<iostream>
#include<cstdlib>
#include "grille.hpp"
#include "coord.hpp"

using namespace std;

int main() {
    Grille g1;
    initialiseGrilleVide(g1);

    srand((unsigned int)time(0));
    const int MAX_BRINDILLE_INIT = 15;
    const int MAX_TERMITE_INIT = 10;
    int NB_BRINDILLE = 0;
    int NB_TERMITE = 0;
    int numeroTermite = 0;

    while (NB_BRINDILLE < MAX_BRINDILLE_INIT) {
        Coord c = creeCoord((rand())%(TAILLE_X),(rand())%(TAILLE_Y));
        poseBrindille(g1,c);
        NB_BRINDILLE++;
    }

    while (NB_TERMITE < MAX_TERMITE_INIT) {
        Coord c = creeCoord((rand())%(TAILLE_X),(rand())%(TAILLE_Y));
        poseTermite(g1,c, numeroTermite);
        NB_TERMITE++;
        numeroTermite++;
    }

    for (int i = 0; i < TAILLE_X; i++) {
        for (int j = 0; j < TAILLE_Y; j++) {
            if (g1.caG[i][j].type == vide) {
                cout << "  ";
            } else if (g1.caG[i][j].type == brindille) {
                cout << "* ";
            } else if (g1.caG[i][j].type == termite) {
                cout << "/ ";
            }
        } cout << endl;
    }
    
}