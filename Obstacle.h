#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED
#include "Element.h"

// classe fille de Element
class Obstacle : public Element
{
    private:

    public:
        // Constructeur par defaut
        Obstacle();
        // Constructeur param�tr�
        Obstacle(long x, long y);
};

// Doit devenir la classe m�re d'objstacle cassable, obstacle deplacable et de piege

#endif // OBSTACLE_H_INCLUDED
