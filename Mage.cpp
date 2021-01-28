#include "Mage.h"

Mage::Mage()
{
    // c_id
    this->setCID('M');
    // nom personnage
    this->setNom("Thread ARM");
    // nom equipe personnage
    this->setEquipe("Team CPU");
    // pv personnage
    this->setPV(100);
    // mana personnage
    this->setMana(10);
    // attaque personnage
    this->setAtt(40);
    // défense personnage
    this->setDef(30);
    // dextérité personnage
    this->setDex(10);
}

Mage::Mage(string nom, string equipe)
{
    this->setCID('M');
    this->setNom(nom);
    this->setEquipe(equipe);
    this->setPV(100);
    this->setMana(10);
    this->setAtt(40);
    this->setDef(30);
    this->setDex(10);
}

Mage::Mage(string nom, string equipe, int pv, int mana, int attaque, int defense, int dexterite)
{
    this->setCID('M');
    this->setNom(nom);
    this->setEquipe(equipe);
    this->setPV(pv);
    this->setMana(mana);
    this->setAtt(attaque);
    this->setDef(defense);
    this->setDex(dexterite);
}

Mage::~Mage()
{
}
