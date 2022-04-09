#include<iostream>
#include "coord.hpp"

using namespace std;


#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
				       << " line " << __LINE__ << ": " #test << endl
/** Test d'egalite entre deux coordonnees **/
void testEgalCoord() {
    ASSERT(egalCoord(creeCoord(0,0), creeCoord(0,0)));
    ASSERT(not egalCoord(creeCoord(0,1), creeCoord(2,0)));
    ASSERT(egalCoord(creeCoord(10,25),creeCoord(10,25)));
}

/** Test d'egalite direction pour les fonctions aGauche et aDroite**/
void testDirection() {
    ASSERT(aDroite(aGauche(nord_est)) == nord_est);
    ASSERT(aGauche(aGauche(aGauche(aGauche(aGauche(aGauche(aGauche(aGauche(est))))))))== est);
    ASSERT(aDroite(aDroite(aDroite(aDroite(aDroite(aDroite(aDroite(aDroite(sud_ouest)))))))) == sud_ouest);
}

void testDevantCoord() {
    ASSERT(egalCoord(devantCoord(creeCoord(2,14),nord_ouest),creeCoord(1,13)));
    ASSERT(egalCoord(devantCoord(creeCoord(0,1), sud),creeCoord(1,1)));
    
}

int main() {
    Coord c1 = creeCoord(2,1);
    afficheCoord(c1);
    cout << endl;
    testEgalCoord();
    testDirection();
    return 0;
}
