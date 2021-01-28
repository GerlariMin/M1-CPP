#ifndef OBJETRAMASSABLE_H_INCLUDED
#define OBJETRAMASSABLE_H_INCLUDED
#include "Element.h"

// ObjetRamassable est une classse fille de Element
class ObjetRamassable : public Element
{
    private:

        // bonus qu'apporte l'objet à la stat d'attaque du personnage
        int _bonusAtt;
        // bonue qu'apporte l'objet à la stat de défense du personnage
        int _bonusDef;
        // bonue qu'apporte l'objet aux points de vie du personnage
        int _bonusPV;
        // Nom de l'objet
        string _nom;

    public:

        // constructeur par défaut
        ObjetRamassable();
        // constructeur avec paramètre int (utilisé dans Carte, le type définit l'objet que l'on va crée
        ObjetRamassable(int type);
        // Constructeurs avec paramètres pour un objet entièrement personnalisé
        ObjetRamassable(string nom, int bonusAttaque, int bonusDefense, int bonusPV);

        // getter _nom
        string getNom() const;
        // setter _nom
        void setNom(string nom);

        // getter _bonusAtt
        int getBonusAtt() const;
        // setter _bonusAtt
        void setBonusAtt(int bonusAttaque);

        // getter _bonusDef
        int getBonusDef() const;
        // setter _bonusDef
        void setBonusDef(int bonusDefense);

        // getter _bonusPV
        int getBonusPV() const;
        // setter _bonusPV
        void setBonusPV(int bonusPV);

        // affichage des caractéristique de l'ObjetRamassable
        void toString(ostream &flux) const;
        // surcharge de l'opérateur <<, utilisé dans Personnage::afficherInventaire()
        friend ostream& operator<<( ostream &flux, ObjetRamassable* const o );
};


#endif // OBJETRAMASSABLE_H_INCLUDED
