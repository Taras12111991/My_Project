#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include "snake.h"
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
#include <QGraphicsView>


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(/*QGraphicsView*/QWidget *parent = 0);
    ~Game();
    inline int getBallX() const {return _ball->getX();}
    inline int getBallY() const {return _ball->getY();}
public slots:
    virtual void slotMoveSnake();
    void slotGameOver();
    void slotVictory(int length);
    void slotStartMoving();
    void slotTurnSnakeLeft();
    void slotTurnSnakeRight();
    void slotSpeedChanged();
    void slotPause();
protected:
    virtual void setBall();
    virtual void keyPressEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *event);
signals:
    void signalBallMoved(int, int);
    void signalSnakeGrown(int, int);
    void signalSnakeMoved(int, int);
private:
    Snake *_snake;
    Block *_ball;
    bool _speed4x;
    QTimer *_timer;
    QTime myTime;
};

#endif // GAME_H





