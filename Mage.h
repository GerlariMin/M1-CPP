#ifndef MAGE_H_INCLUDED
#define MAGE_H_INCLUDED
#include "Personnage.h"

// Mage est une classe fille de Personnage
class Mage : public Personnage
{
    private:

    public:

        // Constructeur par d�faut
        Mage();
        // Contructeurs param�tr�s
        Mage(string nom, string equipe);
        Mage(string nom, string equipe, int pv, int mana, int attaque, int defense, int dexterite);
        // Destructeur
        ~Mage();

};

#endif // MAGE_H_INCLUDED
