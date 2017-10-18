#include "game.h"
#include <QMessageBox>
#include <QGraphicsScene>


Game::Game(QWidget *parent): QGraphicsView(parent), _snake(new Snake), _ball(new Block(25, 25)),
    _timer(new QTimer), _speed4x(true), myTime(0,0,0)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    setScene(scene);
    this->scene()->setSceneRect(0, 0, 900, 900);
    resize(900, 900);

    connect(_snake, SIGNAL(signalLengthChanged(int)), this, SLOT(slotVictory(int)));
    connect(_snake, SIGNAL(signalCollision()), this, SLOT(slotGameOver()));
    connect(_timer, SIGNAL(timeout()), this, SLOT(slotMoveSnake()));
}

Game::~Game()
{
    delete _timer;
    delete _snake;
    delete _ball;
}

void Game::setBall()
{
    qsrand(myTime.secsTo(QTime::currentTime()));

    int x = qrand()%50;
    int y = qrand()%50;
    while (!_snake->checkCoord(x, y))
    {
        x = qrand()%50;
        y = qrand()%50;
    }
    _ball->setX(x);
    _ball->setY(y);
    emit signalBallMoved(x, y);
}

void Game::slotSpeedChanged()
{
    _speed4x = !_speed4x;
}

void Game::slotMoveSnake()
{
    if (_snake->nextHeadX() == _ball->getX()
            && _snake->nextHeadY() == _ball->getY())
    {
        _snake->grow(_ball->getX(), _ball->getY());
        emit signalSnakeGrown(_ball->getX(), _ball->getY());
        setBall();
    }
    else
    {
        _snake->makeStep();
        emit signalSnakeMoved(_snake->headX(), _snake->headY());
    }
}

void Game::slotGameOver()
{
    QMessageBox* pmb = new QMessageBox;
    pmb->information(0, "Message Box", "Game Over!!!");
    pmb->show();
    _timer->stop();
}

void Game::slotVictory(int length)
{
    if (length == 20)
    {
        QMessageBox* pmb = new QMessageBox;
        pmb->information(0, "Message Box", "Victory!!!");
        pmb->show();
        _timer->stop();
    }
}

void Game::slotStartMoving()
{
    if (!_snake->isMoving())
        _snake->setMoving();
    slotSpeedChanged();
    if (_speed4x)
        _timer->start(100);
    else
        _timer->start(400);
}

void Game::slotTurnSnakeLeft()
{
    if (_snake->isMoving())
        _snake->turnLeft();
}

void Game::slotTurnSnakeRight()
{
    if (_snake->isMoving())
        _snake->turnRight();
}

void Game::slotPause()
{
    if (_timer->isActive())
        _timer->stop();
    else
        _timer->start(400);
}

void Game::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
        slotStartMoving();
        break;
    case Qt::Key_Left:
        slotTurnSnakeLeft();
        break;
    case Qt::Key_Right:
        slotTurnSnakeRight();
        break;
    case Qt::Key_P:
        slotPause();
        break;
    }
}

void Game::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}




