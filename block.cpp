#include "block.h"

Block::Block(int x, int y): _coordX(x), _coordY(y)
{

}


void Block::setX(int x)
{
    _coordX = x;
}

void Block::setY(int y)
{
    _coordY = y;
}
