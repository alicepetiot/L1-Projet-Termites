#ifndef COORD_HPP
#define COORD_HPP

/** Structure de donnee representant un point dans l'espace 2D 
    **/

struct Coord {
    int ligne;
    int colonne;
};

enum Direction {nord_ouest, nord, nord_est,est, sud_est, sud, sud_ouest, ouest};

/** Renvoie une nouvelle paire de type coordonnee 
 * @param ligne un numero de ligne
 * @param colonne un numero de colonne
 * @return une coordonnee initialisée à (ligne, colonne)
 **/
Coord creeCoord (int ligne, int colonne);

/** Affiche une coordonnee 
 * @param c une coordonnee 
 * @return les coordonnees de c sous la forme (ligne,colonne)
 **/
void afficheCoord (Coord c);

/** Renvoie le numero de la ligne d une coordonnee
 * @param c une coordonnee
 * @return le numero de la ligne de c
 **/
int getX (Coord c);

/** Renvoie le numero de la colonne d une coordonnee
 * @param c une coordonnee
 * @return le numero de la colonne de c
 **/
int getY (Coord c);

/** Teste si deux coordonnees sont egales
 * @param c1 une coordonnee
 * @param c2 une coordonnee
 * @return vrai si les coordonnees de c1 et c2 sont egales
 **/
bool egalCoord (Coord c1, Coord c2);

void afficheDirection (Direction d);
Direction aGauche (Direction d);
Direction aDroite (Direction d);
Coord devantCoord(Coord c1, Direction d);

#endif