#ifndef TERMITE_HPP
#define TERMITE_HPP
#include "coord.hpp"
#include "grille.hpp"

struct Termite {
    int numeroTermite; 
    Coord coord;
    int sablier;
    bool porteBrindille;
    Direction dir; 
    bool tourneSurPlace;
};

void creeTermite(Termite &ter, Coord c, int nbTer);
Direction directionTermite(Termite ter);
Coord devantTermite(Termite ter);
bool porteBrindille(Termite ter);
void tourneADroite(Termite &ter);
void tourneAGauche(Termite &ter);
void tourneAleatoirement(Termite &ter);
void demiTour(Termite &ter);
bool laVoieEstLibre(Termite ter, Grille g1);
bool brindilleEnFace(Termite ter, Grille g1);
bool pasEnferme(Termite ter, Grille g1);
void avanceTermite(Termite &ter, Grille g1);
void dechargeTermite(Termite &ter, Grille g1);
void chargeTermite(Termite &ter, Grille g1);
void MarcheAlea(Termite &ter, Grille g1);


#endif 