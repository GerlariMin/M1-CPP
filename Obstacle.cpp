#include "Obstacle.h"

Obstacle::Obstacle()
{
    Element();
    this->setCID('*');
}

Obstacle::Obstacle(long x, long y)
{
    this->setCID('*');
    this->setPosition(x, y);
}
