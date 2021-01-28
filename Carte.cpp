#include "Carte.h"

Carte::Carte()
{
    this->nomFichier = this->NOM_FICHIER_DEFAUT;
    this->initialisation();
}

Carte::Carte(string fichier)
{
    this->nomFichier = fichier;
    this->initialisation();
}

Carte::~Carte()
{
    delete this->personnage_courant;
}

/**
 ***********************
 * Guetters // Setters *
 ***********************
                      **/

vector<vector<char>> Carte::getGrille() const
{
    return this->grille;
}

void Carte::setGrille(vector<vector<char>> g)
{
    this->grille = g;
}

int Carte::getHauteur() const
{
    return this->hauteur;
}

void Carte::setHauteur(int h)
{
    this->hauteur = h;
}

int Carte::getLargeur() const
{
    return this->largeur;
}

void Carte::setLargeur(int l)
{
    this->largeur = l;
}

string Carte::getNomFichier() const
{
    return this->nomFichier;
}

void Carte::setNomFichier(string nf)
{
    this->nomFichier = nf;
}

Personnage* Carte::getPersonnageCourant() const
{
    return this->personnage_courant;
}

void Carte::setPersonnageCourant(Personnage* p)
{
    this->personnage_courant = p;
}

/**
 *******************************
 * Méthodes de la classe Carte *
 *******************************
                              **/

void Carte::actualiser()
{
    for (auto &item : this->elements)
    {
        //cout << "item: " << item->getCID() << " classe: " << typeid(item).name() << endl;
        this->grille[item->getX()][item->getY()] = item->getCID();
    }

    this->afficherCarte();
}

void Carte::afficherCarte()
{
    // Affichage de la bordure supérieure de la carte
    for(int l = 0; l < (this->largeur + 2); l++)
    {
        cout << " #";
    }
    cout << endl;

    // Affichage du contenu de la carte
    for (auto &item : this->grille)
    {
        cout << " # ";
        for (auto &item1 : item)
        {
            cout << item1 << " ";
        }
        cout << "# ";
        cout << endl;
    }

    // Affichage de la bordure inférieure de la carte
    for(int l = 0; l < (this->largeur + 2); l++)
    {
        cout << " #";
    }
    cout << endl;
}

void Carte::ajouterElement(Element* e)
{
    this->elements.push_back(e);
    //this->actualiser();
}

void Carte::deplacementPersonnage(Personnage* p, char direction)
{
    // on récupère la position courante du personnage qui souhaite se déplacer
    int x = p->getX();
    int y = p->getY();

    // ce seront les coordonées temporaires pour vérifier si le déplacement voulu est possible
    int tmp_x = x;
    int tmp_y = y;

    // on modifie les valeurs temporaires en fonction de la direction qui est un caractere issu du main (qui vien de la saisie des touches directionnelles)
    switch(direction)
    {
        case 'h':
            tmp_x--;
            break;

        case 'g':
            tmp_y--;
            break;

        case 'd':
            tmp_y++;
            break;

        case 'b':
            tmp_x++;
            break;

        default:
            break;
    }

    bool deplacementPossible = this->deplacementPossible(tmp_x, tmp_y);

    if(deplacementPossible == true)
    {
        this->grille[x][y] = 'x';
        this->grille[tmp_x][tmp_y] = p->getCID();
        p->seDeplacer(tmp_x, tmp_y); // p->setPosition(tmp_x, tmp_y);
    }
    /*
    else
    {
        cout << "Déplacement impossible!" << endl;
    }
    */

    //this->actualiser();
}

const bool Carte::deplacementPossible(int x, int y)
{
    // Si le déplacement est en dehors des limites
    if(x < 0 || y < 0 || x > (this->hauteur-1) || y > (this->largeur-1))
    {
        cout << "Hors limite!" << endl;
        // on ne peut se déplacer
        return false;
    }

    // si l'emplacement est vide
    if( this->grille[x][y] == 'x' )
    {
        // on peut se déplacer
        return true;
    }
    // si l'emplacement est occupé par un ObjetRamassable
    else if( tolower(this->grille[x][y]) == 'o' )
    {
        ObjetRamassable* o = getObjetParPosition(x,y);
        // Le personnage ramasse automatique l'objet et le stocke dans son inventaire
        this->personnage_courant->ajouterDansInventaire(o);

        // On retire l'objet de la carte
        retirerElement(o);

        // déplacement possible
        return true;
    }
    // si l'emplacement est occupé par un guerrier
    else if( tolower(this->grille[x][y]) == 'g' )
    {
        cout << "Tiens, un guerrier sauvage est sur votre chemin!" << endl;
        Personnage* inconnu = getPersonnageParPosition(x,y);
        // on vérifie que le personnage qui est dans la direction choisie est un ennemi
        bool estAdversaire = this->personnage_courant->estAdversaire(inconnu);

        if(estAdversaire == true)
        {
            // Si c'est un ennemi, le combat se lance automatiquement
            cout << "Ennemi en vue! Il fait partit de " << inconnu->getEquipe() << ". Le combat commence!" << endl;
            this->personnage_courant->attaquerAdversaire(inconnu);
        }
        else
        {
            // Si c'est un allié, on ne fait rien
            cout << "Du calme, c'est simplement un allie!" << endl;
        }

        // le déplacement n'est pas possible
        return false;
    }
    // si l'emplacement est occupé par un mage
    else if( tolower(this->grille[x][y]) == 'm' )
    {
        cout << "Tiens, un mage sauvage est sur votre chemin!" << endl;
        Personnage* inconnu = getPersonnageParPosition(x,y);
        // on vérifie que le personnage qui est dans la direction choisie est un ennemi
        bool estAdversaire = this->personnage_courant->estAdversaire(inconnu);

        if(estAdversaire == true)
        {
            // Si c'est un ennemi, le combat se lance automatiquement
            cout << "Ennemi en vue! Il fait partit de " << inconnu->getEquipe() << ". Le combat commence!" << endl;
            this->personnage_courant->attaquerAdversaire(inconnu);
        }
        else
        {
            // Si c'est un allié, on ne fait rien
            cout << "Du calme, c'est simplement un allie!" << endl;
        }

        // le déplacement n'est pas possible
        return false;
    }
    // Dans les autres cas, on ne peut pas se déplacer
    else
    {
        cout << "Deplacement impossible! " << endl;
        return false;
    }
}

ObjetRamassable* Carte::getObjetParPosition(int x, int y)
{
    for(Element* e : this->elements)
    {
        if(e->getCID() == 'O' && e->getX() == x && e->getY() == y)
        {
            return (ObjetRamassable*) e;
        }
    }
    // Si la boucle se finit, c'est qu'on a pas trouver l'objet souhaité
    return nullptr;
}

Personnage* Carte::getPersonnageParPosition(int x, int y) const
{
    for(Element* e : this->elements)
    {
        if((e->getCID() == 'G' || e->getCID() == 'M') && e->getX() == x && e->getY() == y)
        {
            return (Personnage*) e;
        }
    }
    // Si la boucle se finit, c'est qu'on a pas trouver le personnage souhaité
    return nullptr;
}

// Initialisation de la carte à partir d'un fichier texte formaté
void Carte::initialisation()
{
    /**
     * DOCUMENTATION FICHIER:
     * https://riptutorial.com/fr/cplusplus/example/1626/lecture-d-un-fichier#:~:text=C%2B%2B%20Lecture%20d%27un%20fichier.%20Exemple.%20Il%20existe%20plusieurs,fichier%20nomm%C3%A9%20foo.txt%20qui%20contient%20les%20donn%C3%A9es%20suivantes%3A
     **/

    // Ouvrir le fichier voulu
    std::ifstream is(this->nomFichier+".txt");

    // Défini la position au début du fichier ouvert/ Sets position to the start of the file.
    is.seekg(0, std::ios::beg);

    int numeroLigne = 0;

    // getLine retournera faux si il n'y a pas d'autres lignes/ The function getline returns false if there are no more lines.
    for (string str; getline(is, str);)
    {
        switch(numeroLigne)
        {
            case 0:
                is >> this->hauteur; // la première ligne correspond à un int qui définit la hauteur
                break;

            case 1:
                is >> this->largeur; // la deuxième ligne correspond à un int
                break;

            default:
                //si la chaîne est non vide
                if(str!="")
                {
                    // déclaration d'un vecteur de char v qui prendra la valeur de chaque caractère qui composent la carte et qui sera ajouté à la grille.
                    vector<char> v;
                    //parcours des caractères de la ligne courante (c'est à dire la ligne n°numeroLigne
                    for(unsigned int i = 0; i < str.size(); i++)
                    {
                        // on récupère le caractère courant
                        switch(str[i])
                        {
                            // si str[i] est un int entre 1 et 3, il s'agit d'un ObjetRamassable
                            case '1':
                                {
                                    // on créé un objet de type 1
                                    ObjetRamassable* o1 = new ObjetRamassable(1);
                                    // on définit la position de l'objet par rapport à sa position sur la carte du fichier texte
                                    o1->setPosition(numeroLigne-3, i);
                                    // on ajoute l'ObjetRamassable aux éléments de la carte
                                    this->ajouterElement(o1);
                                    // on ajoutera 'O' à la grille de charactères
                                    v.push_back(o1->getCID());
                                    break;
                                }

                            case '2':
                                {
                                    // on créé un objet de type 2
                                    ObjetRamassable* o2 = new ObjetRamassable(2);
                                    // on définit la position de l'objet par rapport à sa position sur la carte du fichier texte
                                    o2->setPosition(numeroLigne-3, i);
                                    // on ajoute l'ObjetRamassable aux éléments de la carte
                                    this->ajouterElement(o2);
                                    // on ajoute 'O' à la grille de charactères
                                    v.push_back(o2->getCID());
                                    break;
                                }

                            case '3':
                               {
                                    // on créé un objet de type 3
                                    ObjetRamassable* o3 = new ObjetRamassable(3);
                                    // on définit la position de l'objet par rapport à sa position sur la carte du fichier texte
                                    o3->setPosition(numeroLigne-3, i);
                                    // on ajoute l'ObjetRamassable aux éléments de la carte
                                    this->ajouterElement(o3);
                                    // on ajoute 'O' à la grille de charactères
                                    v.push_back(o3->getCID());
                                    break;
                               }
                            // si il vaut G, c'est un guerrier géré par ordinateur (donc on utilisera le constructeur par défaut)
                            case 'G':
                                {
                                    // on initialise un guerrier
                                    Guerrier* g = new Guerrier();
                                    // on définit sa position par rapport à son emplacement sur la carte du fichier texte
                                    g->setPosition(numeroLigne-3, i);
                                    // on ajoute le guerrier aux éléments de la carte
                                    this->ajouterElement(g);
                                    // on ajoute 'G' à la grille de charactères
                                    v.push_back(g->getCID());
                                    break;
                                }
                            // si il vaut M, c'est un mage géré par ordinateur (donc on utilisera le constructeur par défaut)
                            case 'M':
                                {
                                    // on initialise un mage
                                    Mage* m = new Mage();
                                    // on définit sa position par rapport à son emplacement sur la carte du fichier texte
                                    m->setPosition(numeroLigne-3, i);
                                    // on ajoute le mage aux éléments de la carte
                                    this->ajouterElement(m);
                                    // on ajoute 'M' à la grille de charactères
                                    v.push_back(m->getCID());
                                    break;
                                }

                            default:
                                v.push_back(str[i]); // dans les autres cas, on ajoute le charactère au vecteur de charactères v
                                break;
                        }
                    }
                    //cout << endl;
                    this->grille.push_back(v); // on ajoute le vecteur de charactères v au vecteur grille
                }
                break;
        }
        numeroLigne ++;
    }
    cout << "Carte cree! " << endl << this << endl;
    //cout << "Carte[hauteur: " << this->hauteur << " largeur: " << this->largeur << " grille " << this->grille.size() << "]" << endl;
}

void Carte::ramasserObjet(Personnage* p, ObjetRamassable* o)
{
    // on rajoute l'objet à l'inventaire du personage p
    p->ajouterDansInventaire(o);
    // l'objet est maintenant considéré comme ramassé
}

void Carte::retirerElement(Element* e)
{
    // https://www.delftstack.com/fr/howto/cpp/remove-element-from-vector-cpp/#:~:text=Utilisez%20la%20m%C3%A9thode%20erase%20%28%29%20pour%20retirer%20un,retourne%20un%20it%C3%A9rateur%20suivant%20le%20dernier%20%C3%A9l%C3%A9ment%20supprim%C3%A9.

    // indice pour retirer l'élément du vecteur elements
    int indice = 0;
    // on parcourt le vecteur
    for (unsigned int i = 0; i < this->elements.size(); i++)
    {
        // si l'élément correspond
        if(elements[i] == e)
        {
            // indice recupère l'inex correspondant
            indice = i;
        }
    }

    auto remove_element = this->elements.begin() + indice;

    if(remove_element != this->elements.end())
    {
        // on supprime l'élément à l'indice souhaité
        this->elements.erase(remove_element);
    }
}

/**                      **
 * Surcharge Opérateur << *
 **                      **/

void Carte::toString(ostream &flux) const
{
    flux << "Carte[ hauteur: " << this->hauteur << ", largeur: " << this->largeur << ", grille " << this->grille.size() << " ]";
}

ostream& operator<<(ostream &flux, Carte* const c)
{
    c->toString(flux);
    return flux;
}
