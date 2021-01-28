#include <iostream>
#include <winuser.h>
#include <fstream>
#include <vector>

#include <cstring>
#include <conio.h> //la bibliothèque de getch() pour la saisie au clavier, notament les flèches

// Inclusion des classes utiles
#include "Carte.h"
#include "Element.h"
#include "Obstacle.h"
#include "Personnage.h"
#include "Guerrier.h"
#include "Mage.h"

using namespace std;

/**                     **
 * Méthodes utilisateurs *
 **                     **/

void choix_carte(string& fichier)
{
    // Boolean pour sortir de la boucle
    bool fin_de_choix = false;
    // valeur pour choisir la carte que l'on veut utiliser pour la partie
    int carte = 0;

    do
    {
        // Si l'utilisateur n'a pas choisit
        if(carte == 0 && fin_de_choix != true)
        {
            cout << " !!! BIENVENUE SUR LE JEU DE ROLE SOLO !!! " << endl;

            cout << "IL EXISTE 2 CARTES: " << endl << " - une carte 5x5 pour une partie rapide (tapez 1)" << endl << " - une carte 10x20 pour une partie plus longue (tapez 2)" << endl;

            // On demande à l'utilisateur de saisir l'entier pour initialiser la carte
            cin >> carte;
        }
        // Si l'utilisateur veut la carte1.txt
        if(carte == 1)
        {
            // on définit la nom du fichier pour la Carte c
            fichier = "carte1";
            // On sort de la boucle
            fin_de_choix = true;
        }
        // Si l'utilisateur veut la carte2.txt
        else if (carte == 2)
        {
            // on définit la nom du fichier pour la Carte c
            fichier = "carte2";
            // On sort de la boucle
            fin_de_choix = true;
        }
        // Sinon on recommence
        else
        {
            cout << "Une erreur s'est produite lors de la saisie! Veuillez réessayer! " << endl;

            cin >> carte;
            //carte = 0;
        }
    }
    // On recommence tant que c'est pas conforme
    while(fin_de_choix != true && carte == 0);

    cout << "Vous avez choisis la carte " << carte << endl;
}

int choix_personnage(string& nom_perso, string& equipe_perso)
{
    // choix du personnage à créer, 1 guerrier, 2 mage
    int personnage;
    // Boolean pour sortir de la boucle
    bool fin_de_choix = false;

    do
    {
        cout << endl << " === CHOIX DU PERSONNAGE! ===" << endl;

        cout << "Il existe 2 types de personnages: " << endl << " - un guerrier (tapez 1)" << endl << " - un mage (tapez 2)" << endl;

        // l'utilisateur saisit le personnage qu'il veut utiliser
        cin >> personnage;

        // formatage de chaine pour afficher les accents
        char dest[256];
        CharToOem("Il vous faut maintenant un nom d'équipe: ", dest);

        cout << "EXCELLENT CHOIX!" << endl << dest << endl;

        // Saisir du nom de l'equipe du personnage
        cin >> equipe_perso;

        // formatage de chaine pour afficher les accents
        CharToOem("C'est noté! Comment voulez-vous que votre personnage s'appelle?", dest);
        cout << dest << endl;

        // Saisir du nom du personnage
        cin >> nom_perso;

        cout << "Parfait! Nous pouvons commencer! " << endl << endl;

        // Si l'entier saisi est correct on sort de la boucle
        if(personnage == 1 || personnage == 2 && (equipe_perso != "" && nom_perso != ""))
        {
            fin_de_choix = true;
        }
        // sinon on recommence
        else
        {
            cout << "Une erreur s'est produite lors de la saisie! Veuillez réessayer! " << endl;
        }

    }
    while(fin_de_choix != true);

    // on retourne le choix du personnage au main
    return personnage;
}

void deplacement_joueur(Carte* c, Personnage* joueur)
{
    /**
    * DOCUMENTATION SAISIE CLAVIER:
    * https://www.programmingsimplified.com/c/conio.h/
    **/

    // Boolean qui determine si le deplacement est effectué ou non
    bool fin_deplacement = false;
    // Valeur de la touche saisie
    int ch = 0;

    // formatage de chaine pour afficher les accents
    char dest[256];
    CharToOem("Utilisez les touches fléchées pour vous déplacer. Si vous voulez rester sur place, cliquez une fois sur la touche échap!", dest);

    do
    {
        cout << dest << endl;
        // ch prend la valeur de la touche saisie
        ch = _getch ();
        // si la touche saisie est echap ou une des flèches directionnelles
        if (ch == 0 || ch == 224)
        {
            // on regarde la valeur de la touche saisie
            switch (_getch ())
            {
                // On a appuyé sur la touche Escape/ echap
                case 27:
                    ch = 27;
                    // L'utilisateur ne veut pas se déplace, on sort de la boucle
                    fin_deplacement = true;
                    break;
                // On a appuyé sur la flèche du haut
                case 72:
                    // On lance la procédure de déplacement du joueur (qui vérifie automatiquement si cela est possible)
                    c->deplacementPersonnage(joueur, 'h');
                    // déplacement possible
                    fin_deplacement = true;
                    break;
                // On a appuyé sur la flèche du bas
                case 80:
                    // On lance la procédure de déplacement du joueur (qui vérifie automatiquement si cela est possible)
                    c->deplacementPersonnage(joueur, 'b');
                    // déplacement possible
                    fin_deplacement = true;
                    break;
                // On a appuyé sur la flèche gauche
                case 75:
                    // On lance la procédure de déplacement du joueur (qui vérifie automatiquement si cela est possible)
                    c->deplacementPersonnage(joueur, 'g');
                    // déplacement possible
                    fin_deplacement = true;
                    break;
                // On a appuyé sur la fleche droite
                case 77:
                    // On lance la procédure de déplacement du joueur (qui vérifie automatiquement si cela est possible)
                    c->deplacementPersonnage(joueur, 'd');
                    // déplacement possible
                    fin_deplacement = true;
                    break;

                default:
                    // aucune saisie ne correspond
                    fin_deplacement = false;
                    break;
            }
        }
    }
    // tant que la touche saisie ne correspond pas aux valeurs attendues et que le deplacement nest pas fait, on recommence
    while(ch!=27 && fin_deplacement == false);
}

void utiliser_objet_inventaire(Personnage* joueur, int indice)
{
    // on utilise l'objet voulu par l'utilisateur (sachant qu'on a un décalage de +1 avec l'indice réel du vector inventaire
    joueur->utiliserObjetInventaire(indice-1);
    // chaine de caractère dest
    char dest[256];
    // pour afficher les accents sur la console
    CharToOem("Vos statistiques ont changées : ", dest);

    cout << dest << endl;
    // on affiche les statistiques du joueur
    cout << joueur << endl << endl;
}

void action_inventaire(Personnage* joueur)
{
    cout << "Votre inventaire: " << endl;

    // Si l'inventaire du joueur contient au moins un Objet à utiliser
    if(joueur->tailleInventaire() > 0)
    {
        cout << "Vous pourrez utiliser un objet de votre inventaire en indiquant le chiffre entre crochets\. Si vous ne voulez pas en utiliser, tapez 0:" << endl;

        joueur->afficherInventaire();
        // indice de l'objet à utiliser
        int indice = -1;
        do
        {
            // l'utilisateur saisie l'indice de l'objet qu'il veut utiliser
            cin >> indice;
        }
        // on demande de saisir tant que indice ne correspond pas à une valeur souhaitée
        while(indice < 0 || indice > joueur->tailleInventaire());

        // si un indice est saisi
        if(indice > 0)
        {
            // on utilise l'objet
            utiliser_objet_inventaire(joueur, indice);
        }
    }
    // Si l'inventaire est vide
    else
    {
        cout << "Votre inventaire est vide! Aucune action n'est encore possible. Ramassez des objets!" << endl;
    }
}

/**                   **
 * Méthodes ordinateur *
 **                   **/

void gestion_inventaire_ordinateur(Personnage* joueur)
{
    // Si l'inventaire du joueur contient au moins 1 objet
    if(joueur->tailleInventaire() > 0)
    {
        // L'ordinateur utilise directement l'objet pour son joueur
        joueur->utiliserObjetInventaire(0);
    }
}

void deplacement_ordinateur(Carte* c, Personnage* joueur)
{
    // Boolean qui vérifiera si le deplacement du joueur est possible
    bool deplacementPossible = false;

    // On récupère les coodonnées du joueur
    int x = joueur->getX();
    int y = joueur->getY();

    // Charactère qui indiquera la direction que va prendre le joueur
    char direction ='n';

    do
    {
        // on tire un int aléatoire entre 0 et 3
        int int_direction = rand()%5;

        switch(int_direction)
        {
            // droite
            case 0:
                // on affecte le charactère correspond à direction
                direction = 'd';
                // On regarde si le déplacement est possible
                deplacementPossible = c->deplacementPossible(x, y+1);
                break;
            //gauche
            case 1:
                // on affecte le charactère correspond à direction
                direction = 'g';
                // On regarde si le déplacement est possible
                deplacementPossible = c->deplacementPossible(x, y-1);
                break;
            //haut
            case 2:
                // on affecte le charactère correspond à direction
                direction = 'h';
                // On regarde si le déplacement est possible
                deplacementPossible = c->deplacementPossible(x-1, y);
                break;
            //bas
            case 3:
                // on affecte le charactère correspond à direction
                direction = 'b';
                // On regarde si le déplacement est possible
                deplacementPossible = c->deplacementPossible(x+1, y);
                break;
            // il reste sur place
            case 4:
                direction = 'n';
                deplacementPossible = true;
                break;
            default:
                // Par défaut, le deplacment n'est pas valable, on recommence
                deplacementPossible = false;
                break;
        }
    }
    // On recommence tant que le déplacement n'est pas possible
    while(deplacementPossible == false && direction != 'n');

    // L'ordinateur effectue le déplacement de son guerrier s'il ne reste pas sur place
    if(direction != 'n')
    {
        c->deplacementPersonnage(joueur, direction);
    }
}

void tour_ordinateur(Personnage* joueur, Carte* c)
{
    cout << " C'est au tour de l'ordinateur de jouer!" << endl;
    cout << joueur << endl << endl;

    // L'ordinateur va gérer son inventaire
    gestion_inventaire_ordinateur(joueur);
    // l'ordinateur va effectuer un déplacement
    deplacement_ordinateur(c, joueur);
}

/**                              **
 * FONCTIONS DE GESTION DE PARTIE *
 **                              **/

void annonce_gagnant(vector<Personnage*> joueurs)
{
    char dest[256];
    // pour afficher les accents sur la console
    CharToOem("Partie terminée! l'équipe gagnante est ", dest);

    // On parcours le vecteur des joueurs
    for(Personnage* p : joueurs)
    {
        // si le personnage courant à une santé non nulle et positive
        if(p->getPV() > 0)
        {
            // On annonce le gagnant
            cout << endl << dest << p->getEquipe() << endl;
        }
    }
}

bool partie_finie(vector<Personnage*> joueurs)
{
    bool fin;
    int nombre_joueurs_vivants = 0;
    string equipe = "";

    // On parcoure le vecteur des joueurs
    for(unsigned int i = 0; i < joueurs.size();  i++)
    {
        // Si on tombe sur le premier joueur avec une vie positive
        if(equipe == "" && joueurs[i]->getPV() > 0)
        {
            // on enregistre son equipe pour ignorer ses equipiers
            equipe = joueurs[i]->getEquipe();
            // le nombre de joueur augmente
            nombre_joueurs_vivants++;
        }
        // Sinon
        else
        {
            // Si le personnage courant à une santé positive et qu'il s'agit d'un adversaire
            if(joueurs[i]->getPV() > 0 && joueurs[i]->getEquipe() != equipe)
            {
                // le nombre de joueur augmente
                nombre_joueurs_vivants++;
            }
        }
    }

    // Si aucun des joueurs n'a de santé positive
    if(nombre_joueurs_vivants == 0)
    {
        // La partie est finie
        fin = true;
        // On annonce le match nul
        cout << endl << "Partie terminée! Match nul!" << endl;
    }
    // Si il y a
    else if(nombre_joueurs_vivants == 1)
    {
        annonce_gagnant(joueurs);
        fin = true;
    }
    else
    {
        fin = false;
    }

    return fin;
}

/**    **
 * MAIN *
 **    **/

int main()
{
    cout << "\t=== LANCEMENT DU JEU ===" << endl << endl;

    /**                     **
     * Variables utiles main *
     **                     **/

    // On stockera les différents joueurs de la partie
    vector<Personnage*> joueurs;
    // On peut stocker des objets que l'on rajoutera en + de ceux présents sur la carte
    //vector<ObjetRamassable*> objets;
    // Nom du fichier texte choisit pour l'initialisation
    string carte;
    // Nom du joueur humain
    string nom_joueur;
    // Nom d'équipe du joueur humain
    string equipe_joueur;
    // Integer qui correspondra au choix du joueur humain, 1 pour un Guerrier, 2 pour un Mage
    int personnage_choisi;
    // Personnage du joueur humain
    Personnage* joueur;
    // Création du guerrier ennemi, géré par ordinateur
    Guerrier* adversaire = new Guerrier();
    // Boolean qui permet de savoir si la partie est finie ou non
    bool fin_partie = false;
    // Chaîne de charactères qui affichera le gagnant de la partie
    string gagnant;
    // integer qui servira pour parcourir le vecteur joueurs pour le tour par tour
    int i = 0;

    /**                           **
     * Initialisation de la partie *
     **                           **/

    // Ajout de nouveaux objets au vecteur objets
    /*
    objets.push_back(new ObjetRamassable(1));
    objets.push_back(new ObjetRamassable(1));
    objets.push_back(new ObjetRamassable(2));
    */

    // L'utilisateur choisit la carte qu'il veut
    choix_carte(carte);

    cout << "Initialisation de la carte en cours..." << endl;
    // création de la carte à partir du choix d'utilisateur
    Carte* c = new Carte(carte);

    // Choix du personnage que le joueur humain veut utiliser
    personnage_choisi = choix_personnage(nom_joueur, equipe_joueur);

    // Si la valeur est 1
    if(personnage_choisi == 1)
    {
        // On créé un Guerrier personnalisé que l'on ajoute au vecteur joueurs
        joueur = new Guerrier(nom_joueur, equipe_joueur);
    }
    // Si la valeur est 2
    else if(personnage_choisi == 2)
    {
        // On créé un Mage personnalisé que l'on ajoute au vecteur joueurs
        joueur = new Mage(nom_joueur, equipe_joueur);
    }

    // On positionne le Personnage du joueur en début de carte, au bord supérieur gauche de la carte
    joueur->setPosition(0,0);

    // On le stocke au vecteur joueurs
    joueurs.push_back(joueur);

    // On positionne le Guerrier géré par l'ordinateur en fond de carte, au bord inférieur droit de la carte
    adversaire->setPosition(c->getHauteur()-1,c->getLargeur()-1);

    // On le stocke au vecteur joueurs
    joueurs.push_back(adversaire);

    // On ajoute les différents personnages de la partie à la Carte c
    for(Personnage* p : joueurs)
    {
        c->ajouterElement(p);
    }

    /*
    for(ObjetRamassable* o : objets)
    {
        // On initialise la position des objets que l'on rajoute en supplément avec des coordonées aléatoires dans les limites de la carte
        o->setPosition( (0 + ( rand() % static_cast<int>( ( c->getHauteur()-2 ) - 1 +1 ) ) ), ( 0 + ( rand() % static_cast<int>( ( c->getLargeur()-2 ) - 1 +1 ) ) ));
        // On ajoute les différents personnages à la Carte c
        c->ajouterElement(o);
    }
    */

    /**                           **
     * Gestion des tours de partie *
     **                           **/

    do
    {
        // On indique à la carte quel est le joueur qui fait son tour de jeu
        c->setPersonnageCourant(joueurs[i]);

        // Si il s'agit du joueur humain, on utilise les fonctions propres à ce type de joueur (où il devra choisir sur l'interface les actions qu'il veut faire)
        if(joueurs[i]->getEquipe() != "Team CPU") //equipe des ordinateurs = Thread ARM
        {
            // Gestion de l'inventaire et des actions possibles
            action_inventaire(joueurs[i]);

            // actualisation de la carte pour voir où le joueur peut se déplacer
            c->actualiser();

            // Gestion du déplacment du joueur
            deplacement_joueur(c, joueurs[i]);
        }
        // Si il s'agit d'un joueur géré par ordinateur, on utilise les fonctions appropriées
        // Si vous n'arrivez pas à toucher le guerrier géré par ordinateur, vous pouvez commenter le else pour qu'il reste statique
        // Si vous voulez tester ce guerrier il suffit de remplacer le i==0 par i==1 en + pour attaquer le personnage du joueur humain qui sera inactif
        else
        {
            tour_ordinateur(joueurs[i], c);
        }

        // si on arrive au bout du vecteur
        if(i == joueurs.size()-1)
        {
            // on repart au début
            i = 0;
        }
        // sinon on continue le parcours du vecteur
        else
        {
            i++;
        }

        fin_partie = partie_finie(joueurs);
    }
    // On fait du tour par tour jusqu'à que la partie soit finie
    while(fin_partie == false);

    delete c;

    cout << endl << "\t=== FIN DE JEU ===" << endl;

    return 0;
}
