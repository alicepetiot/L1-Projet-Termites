#include<iostream>
#include "coord.hpp"
#include "grille.hpp"
using namespace std;

Case caseVide(Case ca) {
    ca.type = vide;
    ca.numeroTermite = -1;
    return ca;
}

void initialiseGrilleVide(Grille &g1) {
    for (int i = 0; i < TAILLE_X; i++) {
        for (int j = 0; j < TAILLE_Y; j++) {
            g1.caG[i][j] = caseVide(g1.caG[i][j]);
        }
    } 
}

bool grilleEgale(Grille g1, Grille g2) {
    for (int i = 0; i < TAILLE_X; i++) {
        for (int j = 0; j < TAILLE_Y; j++) {
            if ( (g1.caG[i][j].type == g2.caG[i][j].type) and (g1.caG[i][j].numeroTermite == g2.caG[i][j].numeroTermite) ) {
                return true; 
            }
        }
    } return false; 
}


bool estVide (Grille g1, Coord c) {
    return g1.caG[c.ligne][c.colonne].type == vide;
}

bool dansGrille (Grille g1, Coord c) {
    if ((c.ligne >= 0) and (c.ligne < TAILLE_X) and (c.colonne >= 0) and (c.colonne <TAILLE_Y)) {
                return true; 
    }
    return false;
}

bool contientBrindille (Grille g1, Coord c) {
    return g1.caG[c.ligne][c.colonne].type == brindille;
}

int numeroTermite (Grille g1, Coord c) {
    if (g1.caG[c.ligne][c.colonne].type == termite) {
        return g1.caG[c.ligne][c.colonne].numeroTermite;
    } return -1;
}

void poseBrindille (Grille &g1, Coord c) {
    if ((dansGrille(g1,c)) and (estVide(g1,c))) {
        g1.caG[c.ligne][c.colonne].type = brindille;
    }
}

void enleveBrindille (Grille &g1, Coord c) {
    if ((dansGrille(g1,c)) and (contientBrindille(g1,c))) {
        g1.caG[c.ligne][c.colonne].type = vide;
    } 
}

void poseTermite (Grille &g1, Coord c, int nbTer) {
    if ((dansGrille(g1,c)) and (estVide(g1,c))) {
        g1.caG[c.ligne][c.colonne].type = termite;
        g1.caG[c.ligne][c.colonne].numeroTermite = nbTer;
    }
}    

void enleveTermite (Grille &g1, Coord c) {
    if ((dansGrille(g1,c)) and (g1.caG[c.ligne][c.colonne].type == termite)) {
        g1.caG[c.ligne][c.colonne].type = vide;
    }
}