#ifndef GRILLE_HPP
#define GRILLE_HPP
#include "coord.hpp"

enum typeCase {brindille, termite, vide};

struct Case {
    typeCase type;
    int numeroTermite;
};

const int TAILLE_X = 20;
const int TAILLE_Y = 20;

struct Grille {
    Case caG[TAILLE_X][TAILLE_Y];
};

void initialiseGrilleVide(Grille &g1);
bool grilleEgale(Grille g1, Grille g2);
bool estVide (Grille g1, Coord c);
bool dansGrille (Grille g1, Coord c);
bool contientBrindille (Grille g1, Coord c);
int numeroTermite (Grille g1, Coord c);
void poseBrindille(Grille &g1, Coord c);
void enleveBrindille (Grille &g1, Coord c);
void poseTermite (Grille &g1, Coord c, int nbTer);
void enleveTermite (Grille &g1, Coord c);

#endif