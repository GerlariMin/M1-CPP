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
        // position de l'�l�ment
        Position p;

    public:

        // constructeur par d�faut
        Element();
        // constructeur avec param�tres pour d�finir directement la position p de l'�l�ment
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

        // d�finir la position de l'�l�ment
        void setPosition(int x, int y);
};

#endif // ELEMENT_H_INCLUDED
