#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED
#include "Position.h"
#include <iostream>

using namespace std;

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

#endif // ELEMENT_H_INCLUDED
