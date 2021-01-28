#include "Position.h"

/**             **
 * Constructeurs *
 **             **/

Position::Position()
{
    this->x = 0;
    this->y = 0;
}
Position::Position(long x, long y)
{
    this->x = x;
    this->y = y;
}

/**           **
 * Destructeur *
 **           **/

Position::~Position()
{

}

/**                **
 * Getters/ Setters *
 **                **/

const long Position::getX()
{
    return this->x;
}

void Position::setX(long x)
{
    if(x >= 0)
    {
        this->x = x;
    }
}

const long Position::getY()
{
    return this->y;
}

void Position::setY(long y)
{
    if(y >= 0)
    {
        this->y = y;
    }
}
