#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

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

#endif // POSITION_H_INCLUDED
