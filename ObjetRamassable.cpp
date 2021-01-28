#include "ObjetRamassable.h"

/**             **
 * Constructeurs *
 **             **/

ObjetRamassable::ObjetRamassable()
{
    // c_id
    this->setCID('O');
    // nom de l'objet ramassable
    this->_nom = "Objet commun";
    // bonus d'attaque que donne l'objet
    this->_bonusAtt = 10;
    // bonus de défense que donne l'objet
    this->_bonusDef = 5;
    // bonus de santé que donne l'objet
    this->_bonusPV = 0;
}

ObjetRamassable::ObjetRamassable(int type)
{
    this->setCID('O');
    // en fonction du type souhaité,  l'objet ramassable offre différents niveaux de bonus
    switch(type)
    {
        case 1:

            this->setNom("Boost 1");
            this->_bonusAtt = 5;
            this->_bonusDef = 5;
            this->_bonusPV = 0;
            break;

        case 2:

            this->setNom("Boost 2");
            this->_bonusAtt = 10;
            this->_bonusDef = 5;
            this->_bonusPV = 5;
            break;
        case 3:

            this->setNom("Boost 3");
            this->_bonusAtt = 10;
            this->_bonusDef = 10;
            this->_bonusPV = 10;
            break;

        default:
            ObjetRamassable();
            break;
    }
}

ObjetRamassable::ObjetRamassable(string nom, int bonusAttaque, int bonusDefense, int bonusPV)
{
    this->setCID('O');
    this->_nom = nom;
    this->_bonusAtt = bonusAttaque;
    this->_bonusDef = bonusDefense;
    this->_bonusPV = bonusPV;
}

/**               **
 * Getters Setters *
 **               **/

// _nom
string ObjetRamassable::getNom() const
{
    return this->_nom;
}

void ObjetRamassable::setNom(string nom)
{
    this->_nom = nom;
}

// _bonusAtt
int ObjetRamassable::getBonusAtt() const
{
    return this->_bonusAtt;
}

void ObjetRamassable::setBonusAtt(int bonusAttaque)
{
    this->_bonusAtt = bonusAttaque;
}

// _bonusDef
int ObjetRamassable::getBonusDef() const
{
    return this->_bonusDef;
}

void ObjetRamassable::setBonusDef(int bonusDefense)
{
    this->_bonusDef = bonusDefense;
}

// _bonusPV
int ObjetRamassable::getBonusPV() const
{
    return this->_bonusPV;
}

void ObjetRamassable::setBonusPV(int bonusPV)
{
    this->_bonusPV = bonusPV;
}

// permet d'afficher les caractéristiques de l'objet ramassable
void ObjetRamassable::toString(ostream &flux) const
{
    flux << "Objet ramassable: " << this->getNom() << "[ bonus attaque: " << this->getBonusAtt() << ", bonus défense: " << this->getBonusDef() << ", bonus points de vie: " << this->getBonusPV() <<"] ";
}

// Surcharge de l'opérateur << pour afficher les caractéristiques de l'objet
ostream& operator<<( ostream &flux, ObjetRamassable* const o)
{
    //Affichage des attributs
    o->toString(flux);
    return flux;
}
