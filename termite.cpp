#include<iostream>
#include "coord.hpp"
#include "grille.hpp"
#include "termite.hpp"

using namespace std;

void creeTermite(Termite &ter, Coord c, int nbTer) {
    ter.coord = c;
    ter.numeroTermite = nbTer;
    ter.dir = static_cast<Direction>(rand()%8);
    ter.porteBrindille = false;
    ter.sablier = 0;
    ter.tourneSurPlace = false;
}

Direction directionTermite(Termite ter) {
    return ter.dir; 
}

Coord devantTermite(Termite ter) {
    return devantCoord(ter.coord,ter.dir);
}

bool porteBrindille(Termite ter) {
    return ter.porteBrindille; 
}

void tourneADroite(Termite &ter) {
    ter.dir = aDroite(ter.dir); 
}

void tourneAGauche(Termite &ter) {
    ter.dir = aGauche(ter.dir);
}

void tourneAleatoirement(Termite &ter) {
    int chance = rand()%2;
    if (chance == 0) {
        tourneADroite(ter); 
    } else { 
        tourneAGauche(ter);
    }
}

void demiTour(Termite &ter) {
    for (int i = 0; i < 4; i++) {
        tourneADroite(ter);
    }
}

bool laVoieEstLibre(Termite ter, Grille g1) {
    return estVide(g1,devantTermite(ter));
}

bool brindilleEnFace(Termite ter, Grille g1) {
    return contientBrindille(g1, devantTermite(ter));
}

bool pasEnferme(Termite ter, Grille g1) {
    Coord c1 = creeCoord(ter.coord.ligne, ter.coord.colonne); 
    if ( brindilleEnFace(ter,g1)
        and    ((estVide(g1,creeCoord(c1.ligne-1,c1.colonne-1)))
            or (estVide(g1,creeCoord(c1.ligne-1,c1.colonne)))
            or (estVide(g1,creeCoord(c1.ligne-1,c1.colonne+1)))
            or (estVide(g1,creeCoord(c1.ligne, c1.colonne-1)))
            or (estVide(g1,creeCoord(c1.ligne, c1.colonne+1)))
            or (estVide(g1,creeCoord(c1.ligne+1, c1.colonne-1)))
            or (estVide(g1,creeCoord(c1.ligne+1, c1.colonne)))
            or (estVide(g1,creeCoord(c1.ligne+1, c1.colonne+1))))){
                return true;
    } return false;
}

void avanceTermite(Termite &ter, Grille g1) {
        enleveTermite(g1, ter.coord);
        ter.coord = devantTermite(ter);
        poseTermite(g1, ter.coord, ter.numeroTermite);
}

void dechargeTermite(Termite &ter, Grille g1) {
    if (porteBrindille(ter) and laVoieEstLibre(ter, g1)) {
        ter.porteBrindille = false;
    }
}

void chargeTermite(Termite &ter, Grille g1) {
    if (not porteBrindille(ter) and brindilleEnFace(ter, g1)){
        ter.porteBrindille = true;
    }
}   

void MarcheAlea(Termite &ter, Grille g1) {
    if (laVoieEstLibre(ter, g1)) {
        if (rand()%10 != 0) {
            avanceTermite(ter, g1);
        } else { 
            tourneAleatoirement(ter);
            avanceTermite(ter, g1);
        }
    } else {
        tourneAleatoirement(ter);
        avanceTermite(ter, g1);
    }
}