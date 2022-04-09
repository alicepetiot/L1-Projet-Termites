#include<iostream>
#include "coord.hpp"
using namespace std;

Coord creeCoord (int ligne, int colonne) {
    Coord c;
    c.ligne = ligne;
    c.colonne = colonne;
    return c;
}

void afficheCoord (Coord c) {
    cout << "(" << c.ligne << "," << c.colonne << ")";
}

int getX (Coord c) {
    return c.ligne;
}

int getY (Coord c) {
    return c.colonne;
}

bool egalCoord (Coord c1, Coord c2) {
    int x1 = getX(c1);
    int y1 = getY(c1);
    int x2 = getX(c2);
    int y2 = getY(c2);
    return (x1 == x2 and y1 == y2);
}

void afficheDirection (Direction d){
    cout << d << endl;
}

Direction aGauche (Direction d) {
    Direction leftDirection;
    if (d == nord_ouest) { leftDirection = ouest; }
    else if (d == nord) { leftDirection = nord_ouest; }
    else if (d == nord_est) { leftDirection = nord; }
    else if (d == est) { leftDirection = nord_est; }
    else if (d == sud_est) { leftDirection = est; }
    else if (d == sud) { leftDirection = sud_est; }
    else if (d == sud_ouest) { leftDirection = sud; }
    else if (d == ouest) { leftDirection = sud_ouest; }
    return leftDirection;
}

Direction aDroite (Direction d) {
    Direction rightDirection;
    if (d == nord_ouest) { rightDirection = nord; }
    else if (d == nord) { rightDirection = nord_est; }
    else if (d == nord_est) { rightDirection = est; }
    else if (d == est) { rightDirection = sud_est; }
    else if (d == sud_est) { rightDirection = sud; }
    else if (d == sud) { rightDirection = sud_ouest; }
    else if (d == sud_ouest) { rightDirection = ouest; }
    else if (d == ouest) { rightDirection = nord_ouest; }
    return rightDirection;
}

Coord devantCoord(Coord c1, Direction d) {
    Coord c2;

    if ((d == nord_ouest) or (d == nord) or (d == nord_est)) {
        c2.ligne = c1.ligne -1;
    } else if ((d == ouest) or (d== est)) {
        c2.ligne = c1.ligne;
    } else if ((d == sud_ouest) or (d == sud) or (d == sud_est)) {
        c2.ligne = c1.ligne =1;
    }

    if ((d == nord_ouest) or (d == ouest) or (d == sud_ouest)) {
        c2.colonne = c1.colonne -1;
    } else if ((d == nord) or (d == sud)) {
        c2.colonne = c1.colonne;
    } else if ((d == nord_est) or (d == est) or (d == sud_est)) {
        c2.colonne = c1.colonne +1;
    }
    return c2;
}