#ifndef GUERRIER_H_INCLUDED
#define GUERRIER_H_INCLUDED
#include "Personnage.h"

// Guerrier est une classe fille de Personnage
class Guerrier : public Personnage
{
    private:

    public:

        // Constructeur par d�faut (utilis� pour cr�er des guerriers g�r�s par l'ordinateur)
        Guerrier();
        // Constructeurs param�tr�s
        Guerrier(string nom, string equipe);
        Guerrier(string nom, string equipe, int pv, int mana, int attaque, int defense, int dexterite);
        // destructeur
        ~Guerrier();

};


#endif // GUERRIER_H_INCLUDED
