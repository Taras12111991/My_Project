#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsRectItem>
#include <QObject>

class Block
{
public:
    Block(int x = 0, int y = 0);
    inline int getX() const {return _coordX;}
    inline int getY() const {return _coordY;}
    void setX(int x);
    void setY(int y);

private:
    int _coordX;
    int _coordY;
};

#endif // BLOCK_H
