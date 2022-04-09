#include<iostream>
#include "coord.hpp"
#include "grille.hpp"

using namespace std;


#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
				       << " line " << __LINE__ << ": " #test << endl

void testInitialiseGrilleVide() {
    Grille g1;
    Grille g2;
    g2.caG[0][0].type = vide; g2.caG[0][0].numeroTermite = -1;
    g2.caG[0][1].type = vide; g2.caG[0][1].numeroTermite = -1;
    g2.caG[1][0].type = vide; g2.caG[1][0].numeroTermite = -1;
    g2.caG[1][1].type = vide; g2.caG[1][1].numeroTermite = -1;
    initialiseGrilleVide(g1);
    ASSERT(grilleEgale(g1,g2));
}

void testEstVide() {
    Coord c1; c1.ligne = 0; c1.colonne = 0;
    Coord c2; c2.ligne = 0; c2.colonne = 1;
    Coord c3; c3.ligne = 1; c3.colonne = 0;
    Grille g1;
    g1.caG[0][0].type = vide; g1.caG[0][0].numeroTermite = -1;
    g1.caG[0][1].type = termite; g1.caG[0][1].numeroTermite = 4;
    g1.caG[1][0].type = brindille; g1.caG[1][0].numeroTermite = -1;
    g1.caG[1][1].type = vide; g1.caG[1][1].numeroTermite = -1;

    ASSERT(estVide(g1,c1));
    ASSERT(not estVide(g1,c2));
    ASSERT(not estVide(g1,c3));
}


void testDansGrille() {
    Grille g1; 
    Coord c1; c1.ligne = 1; c1.colonne=1;
    Coord c2; c2.ligne = 0; c2.colonne = 0;
    Coord c3; c3.ligne = -1; c2.colonne =0;
    Coord c4; c4.ligne = 2; c4.colonne = 1;
    ASSERT(dansGrille(g1,c1));
    ASSERT(dansGrille(g1,c2));
    ASSERT(not dansGrille(g1,c3));
    ASSERT(not dansGrille(g1,c4));
}

void testContientBrindille() {
    Coord c1; c1.ligne = 0; c1.colonne = 0;
    Coord c2; c2.ligne = 0; c2.colonne = 1;
    Coord c3; c3.ligne = 1; c3.colonne = 0;
    Grille g1;
    g1.caG[0][0].type = vide; g1.caG[0][0].numeroTermite = -1;
    g1.caG[0][1].type = termite; g1.caG[0][1].numeroTermite = 4;
    g1.caG[1][0].type = brindille; g1.caG[1][0].numeroTermite = -1;
    g1.caG[1][1].type = vide; g1.caG[1][1].numeroTermite = -1;

    ASSERT(not contientBrindille(g1,c1));
    ASSERT(not contientBrindille(g1,c2));
    ASSERT(contientBrindille(g1,c3));
}

void testNumeroTermite () {
    Coord c1; c1.ligne = 0; c1.colonne = 0;
    Coord c2; c2.ligne = 0; c2.colonne = 1;
    Coord c3; c3.ligne = 1; c3.colonne = 0;
    Grille g1;
    g1.caG[0][0].type = vide; g1.caG[0][0].numeroTermite = -1;
    g1.caG[0][1].type = termite; g1.caG[0][1].numeroTermite = 4;
    g1.caG[1][0].type = brindille; g1.caG[1][0].numeroTermite = -1;
    g1.caG[1][1].type = vide; g1.caG[1][1].numeroTermite = -1;
    
    ASSERT(numeroTermite(g1,c1) == -1);
    ASSERT(numeroTermite(g1,c2) == 4);
    ASSERT(numeroTermite(g1,c3) == -1);
}

void testPoseBrindille() {
    Coord c1; c1.ligne = 0; c1.colonne = 0;
    Coord c2; c2.ligne = 0; c2.colonne = 1;
    Coord c3; c3.ligne = 1; c3.colonne = 0;
    Grille g1;
    g1.caG[0][0].type = vide; g1.caG[0][0].numeroTermite = -1;
    g1.caG[0][1].type = termite; g1.caG[0][1].numeroTermite = 4;
    g1.caG[1][0].type = brindille; g1.caG[1][0].numeroTermite = -1;
    g1.caG[1][1].type = vide; g1.caG[1][1].numeroTermite = -1;
    
    poseBrindille(g1, c1);
    ASSERT(g1.caG[c1.ligne][c1.colonne].type == brindille);
    poseBrindille(g1,c2);
    ASSERT(g1.caG[c2.ligne][c2.colonne].type == termite);
    poseBrindille(g1,c3);
    ASSERT(g1.caG[c3.ligne][c3.colonne].type == brindille);
}

void testEnleveBrindille() {
    Coord c1; c1.ligne = 0; c1.colonne = 0;
    Coord c2; c2.ligne = 0; c2.colonne = 1;
    Coord c3; c3.ligne = 1; c3.colonne = 0;
    Grille g1;
    g1.caG[0][0].type = vide; g1.caG[0][0].numeroTermite = -1;
    g1.caG[0][1].type = termite; g1.caG[0][1].numeroTermite = 4;
    g1.caG[1][0].type = brindille; g1.caG[1][0].numeroTermite = -1;
    g1.caG[1][1].type = vide; g1.caG[1][1].numeroTermite = -1;

    enleveBrindille(g1,c1);
    ASSERT(g1.caG[c1.ligne][c1.colonne].type == vide);
    enleveBrindille(g1,c2);
    ASSERT(g1.caG[c2.ligne][c2.colonne].type  == termite);
    enleveBrindille(g1,c3);
    ASSERT(g1.caG[c3.ligne][c3.colonne].type  == vide);
}

void testPoseTermite() {
    Coord c1; c1.ligne = 0; c1.colonne = 0;
    Coord c2; c2.ligne = 0; c2.colonne = 1;
    Coord c3; c3.ligne = 1; c3.colonne = 0;
    Grille g1;
    g1.caG[0][0].type = vide; g1.caG[0][0].numeroTermite = -1;
    g1.caG[0][1].type = termite; g1.caG[0][1].numeroTermite = 4;
    g1.caG[1][0].type = brindille; g1.caG[1][0].numeroTermite = -1;
    g1.caG[1][1].type = vide; g1.caG[1][1].numeroTermite = -1;
    
    poseTermite(g1,c1);
    ASSERT(g1.caG[c1.ligne][c1.colonne].type == termite);
    poseTermite(g1,c2);
    ASSERT(g1.caG[c2.ligne][c2.colonne].type== termite);
    poseTermite(g1,c3);
    ASSERT(g1.caG[c3.ligne][c3.colonne].type == brindille);
}

void testEnleveTermite() {
    Coord c1; c1.ligne = 0; c1.colonne = 0;
    Coord c2; c2.ligne = 0; c2.colonne = 1;
    Coord c3; c3.ligne = 1; c3.colonne = 0;
    Grille g1;
    g1.caG[0][0].type = vide; g1.caG[0][0].numeroTermite = -1;
    g1.caG[0][1].type = termite; g1.caG[0][1].numeroTermite = 4;
    g1.caG[1][0].type = brindille; g1.caG[1][0].numeroTermite = -1;
    g1.caG[1][1].type = vide; g1.caG[1][1].numeroTermite = -1;

    enleveTermite(g1,c1);
    ASSERT(g1.caG[c1.ligne][c1.colonne].type== vide);
    enleveTermite(g1,c2);
    ASSERT(g1.caG[c2.ligne][c2.colonne].type == vide);
    enleveTermite(g1,c3);
    ASSERT(g1.caG[c3.ligne][c3.colonne].type == brindille);
}

int main() {
    if ((TAILLE_X == 2) and (TAILLE_Y == 2)) {
        testInitialiseGrilleVide();
        testDansGrille();
    } else { 
        cout << "testInitialiseGrilleVide() et testDansGrille() est prévu pour une grille 2*2" << endl;
    }
    testEstVide();
    testContientBrindille();
    testNumeroTermite();
    testPoseBrindille();
    testEnleveBrindille();
    testPoseTermite();
    testEnleveTermite();
    return 0;
}