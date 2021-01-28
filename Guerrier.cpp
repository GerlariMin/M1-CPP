#include "Guerrier.h"

/**             **
 * Constructeurs *
 **             **/

Guerrier::Guerrier()
{
    // c_id
    this->setCID('G');
    // nom personnage
    this->setNom("Thread ARM");
    // nom equipe personnage
    this->setEquipe("Team CPU");
    // pv personnage
    this->setPV(100);
    // mana personnnage
    this->setMana(10);
    // attaque personnage
    this->setAtt(40);
    // défense personnage
    this->setDef(30);
    // dextérité personnage
    this->setDex(10);
}

Guerrier::Guerrier(string nom, string equipe)
{
    this->setCID('G');
    this->setNom(nom);
    this->setEquipe(equipe);
    this->setPV(100);
    this->setMana(10);
    this->setAtt(40);
    this->setDef(30);
    this->setDex(10);
}

Guerrier::Guerrier(string nom, string equipe, int pv, int mana, int attaque, int defense, int dexterite)
{
    this->setCID('G');
    this->setNom(nom);
    this->setEquipe(equipe);
    this->setPV(pv);
    this->setMana(mana);
    this->setAtt(attaque);
    this->setDef(defense);
    this->setDex(dexterite);
}

Guerrier::~Guerrier()
{
}
