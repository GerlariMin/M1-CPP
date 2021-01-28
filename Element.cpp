#include "Element.h"

/**             **
 * Constructeurs *
 **             **/

Element::Element()
{
    this->setCID('e');
    this->p.setX(long(0));
    this->p.setY(long(0));
}

Element::Element(long x, long y)
{
    this->p.setX(x);
    this->p.setY(y);
}

/**                **
 * Getters/ Setters *
 **                **/

// c_id
char Element::getCID() const
{
    return this->c_id;
}

void Element::setCID(char c)
{
    this->c_id = c;
}

// p.x
const int Element::getX()
{
    return this->p.getX();
}

void Element::setX(int x)
{
    this->p.setX(x);
}

// p.y
const int Element::getY()
{
    return this->p.getY();
}

void Element::setY(int y)
{
    this->p.setY(y);
}

/**        **
 * Méthodes *
 **        **/

// définir la position de l'élément
void Element::setPosition(int x, int y)
{
    this->p.setX(x);
    this->p.setY(y);
}
