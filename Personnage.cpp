#include "Personnage.h"

/**             **
 * Constructeurs *
 **             **/

Personnage::Personnage()
{
    this->setCID('P');
    this->_nom = "Personnage par défaut";
    this->_equipe = "Team Lambda";
    this->_pv = 100;
    this->_mana = 25;
    this->_att = 25;
    this->_def = 20;
    this->_dex = 10;
}

Personnage::Personnage(string nom, string equipe)
{
    this->setCID('P');
    this->_nom = nom;
    this->_equipe = equipe;
    this->_pv = 100;
    this->_mana = 25;
    this->_att = 25;
    this->_def = 20;
    this->_dex = 10;
}

Personnage::Personnage(string nom, string equipe, int pv, int mana, int attaque, int defense, int dexterite)
{
    this->setCID('P');
    this->_nom = nom;
    this->_equipe = equipe;
    this->_pv = pv;
    this->_mana = mana;
    this->_att = attaque;
    this->_def = defense;
    this->_dex = dexterite;
}

/**                **
 * Getters/ Setters *
 **                **/

// _att
int Personnage::getAtt() const
{
    return this->_att;
}

void Personnage::setAtt(int att)
{
    this->_att = att;
}

// _def
int Personnage::getDef() const
{
    return this->_def;
}

void Personnage::setDef(int def)
{
    this->_def = def;
}

// _dex
int Personnage::getDex() const
{
    return this->_dex;
}

void Personnage::setDex(int dex)
{
    this->_dex = dex;
}

// _equipe
string Personnage::getEquipe() const
{
    return this->_equipe;
}

void Personnage::setEquipe(string equipe)
{
    this->_equipe = equipe;
}

// _mana
int Personnage::getMana() const
{
    return this->_mana;
}

void Personnage::setMana(int mana)
{
    this->_mana = mana;
}

// _nom
string Personnage::getNom() const
{
    return this->_nom;
}

void Personnage::setNom(string nom)
{
    this->_nom = nom;
}

// _pv
int Personnage::getPV() const
{
    return this->_pv;
}

void Personnage::setPV(int pv)
{
    this->_pv = pv;
    // Si la santé est basse, on avertir le personnage concerné
    if(this->_pv <= 20)
    {
        cout << "Attention " << this->getNom() << "! Votre sante est faible! Il est peut etre temps d'utiliser un objet!" << endl;
    }
}

/**        **
 * Méthodes *
 **        **/

// Afficher l'inventaire du Personnage (contient des ObjetRamassable)
void Personnage::afficherInventaire()
{
    int i = 0;

    // on parcours les ObjetRamassables de l'inventaire (plus précisement, il s'agit de pointeurs de la classe ObjetRamassable)
    for(ObjetRamassable* o : this->_inventaire)
    {
        // on affiche les caractéristique de l'objet courant de la boucle
        cout << "[" << (i+1) << "] ->" << " " << o << endl;

        i++;
    }
}

void Personnage::ajouterDansInventaire(ObjetRamassable* o)
{
    cout << "Ajout dans l'inventaire: " << o << endl;
    // on ajoute l'objet o à l'inventaire du personnage
    this->_inventaire.push_back(o);
}

void Personnage::attaquerAdversaire(Personnage* p)
{
    // Calcul des dégats arrondis pour rester en int
    int degats = ( this->getAtt() - p->getDef() ); // int( (this->getAtt() - p->getDef()) + p->getDex()  );
    // on applique les dégâts au personnage p adversaire
    p->setPV(p->getPV() - degats);
    // On affiche les dégâts
    cout << this->getNom() << " inflige " << degats << " points de degats a " << p->getNom() << " ! Il lui reste " << p->getPV() << " points de vie." << endl;
}

bool Personnage::estAdversaire(Personnage* p) const
{
    // On regarde si le personnage p est de la même equipe que nous
    if(p->getEquipe() != this->getEquipe())
    {
        // si c'est le cas on renvoit true
        return true;
    }
    else
    {
        // sinon false
        return false;
    }
}

// Déplacer le personnage dans la carte en actualisant sa position p (voir classe Element).
void Personnage::seDeplacer(long x, long y)
{
    // on actualisa la position de p qui est un attribut de personnage hérité de Element
    this->setPosition(x, y);
}

int Personnage::tailleInventaire() const
{
    // on retourne la taille de l'inventaire du personnage
    return this->_inventaire.size();
}

void Personnage::utiliserObjetInventaire(int i)
{
    // on récupère l'objet à l'index souhaité
    ObjetRamassable* o = this->_inventaire[i];

    cout << "Vous avez choisi d'utiliser: " << o << endl;

    // on applique les effets de l'objet au personnage
    this->setPV( this->getPV() + o->getBonusPV() );
    this->setAtt( this->getAtt() + o->getBonusAtt() );
    this->setDef( this->getDef() + o->getBonusDef() );

    auto remove_element = this->_inventaire.begin() + i;

    // on retire l'objet de l'inventaire
    if(remove_element != this->_inventaire.end())
    {
        this->_inventaire.erase(remove_element);
    }

    // on affiche l'inventaire
    //this->afficherInventaire();
}

/**                      **
 * Surcharge Opérateur << *
 **                      **/

void Personnage::toString(ostream &flux) const
{
    flux << "Personnage " << this->getNom() << " [ point de vie:" << this->getPV() << ", attaque: " << this->getAtt() << ", defense: " << this->getDef() << ", mana: " << this->getMana() << ", dexterite: " << this->getDex() << " ] ";
}

ostream& operator<<(ostream &flux, Personnage* const p)
{
    p->toString(flux);
    return flux;
}
