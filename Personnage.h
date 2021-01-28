#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include "Element.h"
#include "ObjetRamassable.h"

#include <vector>

using namespace std;

class Personnage : public Element
{
    private:

        // attaque, indique le nombre de dégâts que le personnage inflige à un autre
        int _att;
        // défense, lorsqu'il se fait attaquer, le personnage recoit moins de dégats grâce à ses statistiques de défenses
        int _def;
        //dextérité, a un impact sur les combats (permet d'esquiver une partie des dégâts que le personnage peut recevoir)
        int _dex;
        // nom de l'équipe
        string _equipe;
        // inventaire du personnage, stock les objets que le personnage a ramassé au cours de la partie
        vector<ObjetRamassable*> _inventaire;
        // mana, pouvoir magique/ endurance
        int _mana;
        // nom du personnage
        string _nom;
        // point de vie
        int _pv;

    public:

        // Constructeur par défaut
        Personnage();
        // Constructeurs paramétrés
        Personnage(string nom, string equipe);
        Personnage(string nom, string equipe, int pv, int mana, int attaque, int defense, int dexterite);
        // Destructeur
        //~Personnage();

        // getter _nom
        string getNom() const;
        // setter _nom
        void setNom(string nom);

        // getter equipe
        string getEquipe() const;
        // setter _equipe
        void setEquipe(string equipe);

        // getter _pv
        int getPV() const;
        // setter _pv
        void setPV(int pv);

        // getter _mana
        int getMana() const;
        // _setter
        void setMana(int mana);

        // getter _att
        int getAtt() const;
        // setter _att
        void setAtt(int att);

        // getter _def
        int getDef() const;
        // setter _def
        void setDef(int def);

        // getter _dex
        int getDex() const;
        // setter _dex
        void setDex(int dex);

        // afficher l'inentaire du personnage
        void afficherInventaire();
        // Ajouter un objet à l'inventaire du personnage
        void ajouterDansInventaire(ObjetRamassable* o);
        // attaquer un ennemi p
        void attaquerAdversaire(Personnage* p);
        // indique si le personnage p est un adversaire du personnage courant
        bool estAdversaire(Personnage* p) const;
        // actualiser les coordonnées du personnage après déplacement
        void seDeplacer(long x, long y);
        // récupérer taille inventaire
        int tailleInventaire() const;
        // utilisaer un objet que le personnage a dans son inventaire
        void utiliserObjetInventaire(int i);

        // affichage des caractéristique du Personnage
        void toString(ostream &flux) const;
        // surcharge de l'opérateur <<
        friend ostream& operator<<(ostream &flux, Personnage* const p);
};

#endif // PERSONNAGE_H_INCLUDED
