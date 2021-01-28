#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED
#include "Element.h"
#include "Personnage.h"
#include "Mage.h"
#include "Guerrier.h"
#include "ObjetRamassable.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Carte
{
    private:

        // constante qui définit le fichier à lire par défaut pour l'initialisation de la carte
        const string NOM_FICHIER_DEFAUT = "carte1";

        // tableau dynamique des différents objets présents sur la carte
        vector<Element*> elements;
        // tableau contenant le c_id des elements de la carte, utile pour l'affichage de la carte
        vector<vector<char>> grille;
        // nombre de lignes de la grille (axe vertical)
        int hauteur;
        // nombre de colones de la grille (axe horizontal)
        int largeur;
        // nom du fichier voulu par l'utilisateur
        string nomFichier;
        // Personnage courant (pointeur) representant le joueur qui fait son tour
        Personnage* personnage_courant;

    public:

        // constructeur par défaut de la carte, initialisation avec NOM_FICHIER_DEFAUT
        Carte();
        // constructeur avec paramètre, initialisation avec fichier
        Carte(string fichier);
        // destructeur
        ~Carte();

        // getter grille
        vector<vector<char>> getGrille() const;
        // setter grille
        void setGrille(vector<vector<char>> g);
        // getter hauteur
        int getHauteur() const;
        //setter hauteur
        void setHauteur(int h);
        //getter largeur
        int getLargeur() const;
        // setter largeur
        void setLargeur(int l);
        // getter nomFichier
        string getNomFichier() const;
        //setter nomFichier
        void setNomFichier(string fichier);
        // getter personnage_courant
        Personnage* getPersonnageCourant() const;
        // setter personnage_courant
        void setPersonnageCourant(Personnage* p);

        // actualiser le contenu de la carte
        void actualiser();
        // afficher la carte
        void afficherCarte();
        // ajouter un element (Obstacle, Guerrier ou Objet ) à la carte
        void ajouterElement(Element* e);
        // Effectueur un deplacement pour un personnage p et une direction donnés
        void deplacementPersonnage(Personnage* p, char direction);
        // ajouter parametre de deplacement: deplacementPossible(Guerrier g, deplacement)
        const bool deplacementPossible(int x, int y);
        // Récupérer un objet ramassable grace a sa position
        ObjetRamassable* getObjetParPosition(int x, int y);
        // Récupérer un personnage grace a sa position
        Personnage* getPersonnageParPosition(int x, int y) const;
        // initialiser la carte
        void initialisation();
        // Un personnage p ramasse un objet o
        void ramasserObjet(Personnage* p, ObjetRamassable* o);
        // Retirer un élément de la carte
        void retirerElement(Element* e);

        // affichage des caractéristique de la Carte
        void toString(ostream &flux) const;
        // surcharge de l'opérateur <<
        friend ostream& operator<<( ostream &flux, Carte* const c );
};

#endif // CARTE_H_INCLUDED
