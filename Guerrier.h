#ifndef GUERRIER_H_INCLUDED
#define GUERRIER_H_INCLUDED
#include "Personnage.h"

// Guerrier est une classe fille de Personnage
class Guerrier : public Personnage
{
    private:

    public:

        // Constructeur par défaut (utilisé pour créer des guerriers gérés par l'ordinateur)
        Guerrier();
        // Constructeurs paramétrés
        Guerrier(string nom, string equipe);
        Guerrier(string nom, string equipe, int pv, int mana, int attaque, int defense, int dexterite);
        // destructeur
        ~Guerrier();

};


#endif // GUERRIER_H_INCLUDED
