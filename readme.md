# **Mini Projet C++ - Jeu tour par tour**
> _Auteur:_ **Morgan MINBIELLE**

Il s'agit d'un jeu solo en tour par tour, contre un ennemi (ordinateur).
Vous pouvez vous déplacer dans les limites de la carte sélectionnée en début de partie, ramasser des objets pour augmenter vos chances de gagner et vous battre contre l'ennemi.
La partie est finie lorsqu'il ne reste qu'un seul joueur encore en vie (ou bien lorsque tous les joueurs d'une équipe n'ont plus de vie).

## **Utilisation**

Il suffit d'exécuter le main, de suivre les instructions affichées dans la console. 
Toutes les actions se font via la saisie clavier (Numéros pour utiliser un objet de l'inventaire et les flèches pour les déplacements).

Le jeu commence par proposer le choix entre 2 cartes.
Il sera ensuite demandé de choisir en 2 personnages (guerrier ou mage), le nom de l'équipe et le nom du personnage.
Le jeu commence alors et il suffit de suivre les étapes et de choisir ce qui est proposé!

## **Améliorations**

* Le jeu doit permettre au joueur d'utiliser des pouvoirs (via son mana). 
* Pouvoir jouer contre un deuxième joueur humain ou bien de jouer en équipe contre plusieurs adversaires gérés par l'ordinateur. 
* Ajout d'un système de niveaux pour les personnages.
* Des pièges et des obstacles destructibles sont aussi prévus.

## **Sources**

Je me suis aidé des cours et de divers sites comme:
 * [riptutorial.com](https://riptutorial.com/fr/cplusplus/example/1626/lecture-d-un-fichier#:~:text=C%2B%2B%20Lecture%20d%27un%20fichier.%20Exemple.%20Il%20existe%20plusieurs,fichier%20nomm%C3%A9%20foo.txt%20qui%20contient%20les%20donn%C3%A9es%20suivantes%3A) pour la gestion des fichiers textes;
 * [programmingsimplified](https://www.programmingsimplified.com/c/conio.h/) pour la saisie clavier (des touches fléchées).

## **Main & Classes**

_**Main** (extrait variables et boucle de gestion de la partie)_

```

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

	// [...]

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

```

_**Carte** (structure)_

```
	class Carte
	{
		private:

			// constante qui définit le fichier à lire par défaut pour l'initialisation de la carte
			const string NOM_FICHIER_DEFAUT = "carte1";

			// tableau dynamique des différents objets présents sur la carte
			vector<Element*> elements;
			// tableau contenant le c_id des elements de la carte, utile pour l'affichage de la carte
			vector<vector<char>> grille;
			// nombre de lignes de la grille (axe vertical)
			int hauteur;
			// nombre de colones de la grille (axe horizontal)
			int largeur;
			// nom du fichier voulu par l'utilisateur
			string nomFichier;
			// Personnage courant (pointeur) representant le joueur qui fait son tour
			Personnage* personnage_courant;

		public:

			// constructeur par défaut de la carte, initialisation avec NOM_FICHIER_DEFAUT
			Carte();
			// constructeur avec paramètre, initialisation avec fichier
			Carte(string fichier);
			// destructeur
			~Carte();

			// getter grille
			vector<vector<char>> getGrille() const;
			// setter grille
			void setGrille(vector<vector<char>> g);
			// getter hauteur
			int getHauteur() const;
			//setter hauteur
			void setHauteur(int h);
			//getter largeur
			int getLargeur() const;
			// setter largeur
			void setLargeur(int l);
			// getter nomFichier
			string getNomFichier() const;
			//setter nomFichier
			void setNomFichier(string fichier);
			// getter personnage_courant
			Personnage* getPersonnageCourant() const;
			// setter personnage_courant
			void setPersonnageCourant(Personnage* p);

			// actualiser le contenu de la carte
			void actualiser();
			// afficher la carte
			void afficherCarte();
			// ajouter un element (Obstacle, Guerrier ou Objet ) à la carte
			void ajouterElement(Element* e);
			// Effectueur un deplacement pour un personnage p et une direction donnés
			void deplacementPersonnage(Personnage* p, char direction);
			// ajouter parametre de deplacement: deplacementPossible(Guerrier g, deplacement)
			const bool deplacementPossible(int x, int y);
			// Récupérer un objet ramassable grace a sa position
			ObjetRamassable* getObjetParPosition(int x, int y);
			// Récupérer un personnage grace a sa position
			Personnage* getPersonnageParPosition(int x, int y) const;
			// initialiser la carte
			void initialisation();
			// Un personnage p ramasse un objet o
			void ramasserObjet(Personnage* p, ObjetRamassable* o);
			// Retirer un élément de la carte
			void retirerElement(Element* e);

			// affichage des caractéristique de la Carte
			void toString(ostream &flux) const;
			// surcharge de l'opérateur <<
			friend ostream& operator<<( ostream &flux, Carte* const c );
	};
```

_**Element** (structure)_

```
	class Element
	{
		private:

			// c_id = character id = Lettre d'identification d'un element
			char c_id;
			// position de l'élément
			Position p;

		public:

			// constructeur par défaut
			Element();
			// constructeur avec paramètres pour définir directement la position p de l'élément
			Element(long x, long y);

			// getter c_id
			char getCID() const;
			// setter c_id
			void setCID(char cid);

			// getter p.x
			const int getX();
			// setter p.x
			void setX(int x);

			// getter p.y
			const int getY();
			// setter p.y
			void setY(int y);

			// définir la position de l'élément
			void setPosition(int x, int y);
	};
```

_**ObjetRamassable** (structure)_

```
	class ObjetRamassable : public Element
	{
		private:

			// bonus qu'apporte l'objet à la stat d'attaque du personnage
			int _bonusAtt;
			// bonue qu'apporte l'objet à la stat de défense du personnage
			int _bonusDef;
			// bonue qu'apporte l'objet aux points de vie du personnage
			int _bonusPV;
			// Nom de l'objet
			string _nom;

		public:

			// constructeur par défaut
			ObjetRamassable();
			// constructeur avec paramètre int (utilisé dans Carte, le type définit l'objet que l'on va crée
			ObjetRamassable(int type);
			// Constructeurs avec paramètres pour un objet entièrement personnalisé
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

			// affichage des caractéristique de l'ObjetRamassable
			void toString(ostream &flux) const;
			// surcharge de l'opérateur <<, utilisé dans Personnage::afficherInventaire()
			friend ostream& operator<<( ostream &flux, ObjetRamassable* const o );
	};
```

_**Personnage** (structure)_

```
	class Personnage : public Element
	{
		private:

			// attaque, indique le nombre de dégâts que le personnage inflige à un autre
			int _att;
			// défense, lorsqu'il se fait attaquer, le personnage recoit moins de dégats grâce à ses statistiques de défenses
			int _def;
			//dextérité, a un impact sur les combats (permet d'esquiver une partie des dégâts que le personnage peut recevoir)
			int _dex;
			// nom de l'équipe
			string _equipe;
			// inventaire du personnage, stock les objets que le personnage a ramassé au cours de la partie
			vector<ObjetRamassable*> _inventaire;
			// mana, pouvoir magique/ endurance
			int _mana;
			// nom du personnage
			string _nom;
			// point de vie
			int _pv;

		public:

			// Constructeur par défaut
			Personnage();
			// Constructeurs paramétrés
			Personnage(string nom, string equipe);
			Personnage(string nom, string equipe, int pv, int mana, int attaque, int defense, int dexterite);
			// Destructeur
			//~Personnage();

			// getter _nom
			string getNom() const;
			// setter _nom
			void setNom(string nom);

			// getter equipe
			string getEquipe() const;
			// setter _equipe
			void setEquipe(string equipe);

			// getter _pv
			int getPV() const;
			// setter _pv
			void setPV(int pv);

			// getter _mana
			int getMana() const;
			// _setter
			void setMana(int mana);

			// getter _att
			int getAtt() const;
			// setter _att
			void setAtt(int att);

			// getter _def
			int getDef() const;
			// setter _def
			void setDef(int def);

			// getter _dex
			int getDex() const;
			// setter _dex
			void setDex(int dex);

			// afficher l'inentaire du personnage
			void afficherInventaire();
			// Ajouter un objet à l'inventaire du personnage
			void ajouterDansInventaire(ObjetRamassable* o);
			// attaquer un ennemi p
			void attaquerAdversaire(Personnage* p);
			// indique si le personnage p est un adversaire du personnage courant
			bool estAdversaire(Personnage* p) const;
			// actualiser les coordonnées du personnage après déplacement
			void seDeplacer(long x, long y);
			// récupérer taille inventaire
			int tailleInventaire() const;
			// utilisaer un objet que le personnage a dans son inventaire
			void utiliserObjetInventaire(int i);

			// affichage des caractéristique du Personnage
			void toString(ostream &flux) const;
			// surcharge de l'opérateur <<
			friend ostream& operator<<(ostream &flux, Personnage* const p);
	};
```

_**Personnage** (structure)_

```
	class Position
	{
		private:

			long x; // position dans l'axe vertical
			long y; // position dans l'axe horizontal

		public:

			Position(); // constructeur par défaut
			Position(long x, long y); // constructeur avec paramètres pour déinir la position
			~Position(); // Destructeur

			const long getX(); // getter x
			void setX(long x); // setter x

			const long getY(); // getter y
			void setY(long y); // setter y
	};
```