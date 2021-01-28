#ifndef OBJETRAMASSABLE_H_INCLUDED
#define OBJETRAMASSABLE_H_INCLUDED
#include "Element.h"

// ObjetRamassable est une classse fille de Element
class ObjetRamassable : public Element
{
    private:

        // bonus qu'apporte l'objet � la stat d'attaque du personnage
        int _bonusAtt;
        // bonue qu'apporte l'objet � la stat de d�fense du personnage
        int _bonusDef;
        // bonue qu'apporte l'objet aux points de vie du personnage
        int _bonusPV;
        // Nom de l'objet
        string _nom;

    public:

        // constructeur par d�faut
        ObjetRamassable();
        // constructeur avec param�tre int (utilis� dans Carte, le type d�finit l'objet que l'on va cr�e
        ObjetRamassable(int type);
        // Constructeurs avec param�tres pour un objet enti�rement personnalis�
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

        // affichage des caract�ristique de l'ObjetRamassable
        void toString(ostream &flux) const;
        // surcharge de l'op�rateur <<, utilis� dans Personnage::afficherInventaire()
        friend ostream& operator<<( ostream &flux, ObjetRamassable* const o );
};


#endif // OBJETRAMASSABLE_H_INCLUDED
