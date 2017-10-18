#ifndef SNAKE_H
#define SNAKE_H
#include <list>
#include "block.h"
#include <QKeyEvent>
#include <QObject>

using std::list;
class Game;

enum Direction {D_Left, D_Right, D_Up, D_Down};

class Snake : public QObject
{
    Q_OBJECT
public:
    Snake();
    virtual void grow(int, int);
    void turnLeft();
    void turnRight();
    void makeStep();
    bool checkCoord(int i, int j) const;
    int nextHeadX();
    int nextHeadY();
    inline bool isMoving() const {return _isMoving;}
    inline void setMoving() {_isMoving = true;}
    inline int getLength() const {return _blockList.size();}
    inline Direction headDirection() {return _headDir;}
    inline int headX() const {return _blockList.front().getX();}
    inline int headY() const {return _blockList.front().getY();}
signals:
    void signalLengthChanged(int);
    void signalCollision();
private:
    //friend class Game;
    list<Block> _blockList;
    Direction _headDir;
    bool _isMoving;
};

#endif // SNAKE_H
