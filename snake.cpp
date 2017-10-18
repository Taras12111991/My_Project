#include "snake.h"
#include <iterator>

Snake::Snake(): _headDir(D_Up), _isMoving(false)
{
    _blockList.push_back(Block(25, 48));
    _blockList.push_back(Block(25, 49));
}

void Snake::grow(int x, int y)
{
    Block block(x, y);
    _blockList.push_front(block);
    emit signalLengthChanged(_blockList.size());
}

void Snake::turnLeft()
{
    switch(_headDir)
    {
    case D_Left:
        _headDir = D_Down;
        break;

    case D_Up:
        _headDir = D_Left;
        break;

    case D_Right:
        _headDir = D_Up;
        break;

    case D_Down:
        _headDir = D_Right;
    }
}

void Snake::turnRight()
{
    switch(_headDir)
    {
    case D_Left:
        _headDir = D_Up;
        break;

    case D_Up:
        _headDir = D_Right;
        break;

    case D_Right:
        _headDir = D_Down;
        break;

    case D_Down:
        _headDir = D_Left;
    }
}

void Snake::makeStep()
{
    Block block(_blockList.front());

    switch(_headDir)
    {
    case D_Left:
        block.setX(block.getX() - 1);
        break;

    case D_Up:
        block.setY(block.getY() - 1);
        break;

    case D_Right:
        block.setX(block.getX() + 1);
        break;

    case D_Down:
        block.setY(block.getY() + 1);
    }

    _blockList.push_front(block);
    _blockList.pop_back();

    if (headX() > 49 || headX() < 0 || headY() < 0
            || headY() > 49)
        emit signalCollision();

    list<Block>::const_iterator it = _blockList.cbegin();
    it++;

    while (it != _blockList.cend())
    {
        if(it->getX() == headX() && it->getY() == headY())
            emit signalCollision();
        it++;
    }
}

bool Snake::checkCoord(int i, int j) const
{
    list<Block>::const_iterator it = _blockList.cbegin();

    while (it != _blockList.cend())
    {
        if(it->getX() == i && it->getY() == j)
            return false;
        it++;
    }
    return true;
}

int Snake::nextHeadX()
{
    if (_headDir == D_Left)
        return headX() - 1;
    if (_headDir == D_Right)
        return headX() + 1;
    return headX();
}

int Snake::nextHeadY()
{
    if (_headDir == D_Up)
        return headY() - 1;
    if (_headDir == D_Down)
        return headY() + 1;
    return headY();
}


