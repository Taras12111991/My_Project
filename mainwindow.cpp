#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QMenu>
#include <QAction>



MainWindow::MainWindow(QWidget *parent) : _game(new Game), _point(new QGraphicsRectItem), _sizeKoef(18),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu* pMenu = new QMenu("Game");
    pMenu->addAction("New Game", this, SLOT(slotNewGame()));
    menuBar()->addMenu(pMenu);

    slotNewGame();
    resize(_game->size().width(), _game->size().width() + 50);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _game;

    auto it = _itemList.begin();
    for (; it != _itemList.end(); ++it)
        delete *it;
}

void MainWindow::slotNewGame()
{
    _sizeKoef = 18;
    if (_game)
        delete _game;

    _game = new Game;
    _game->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _game->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _game->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    setCentralWidget(_game); _game->setFocus( Qt::PopupFocusReason );

    _point = new QGraphicsRectItem(_game->getBallX()*_sizeKoef, _game->getBallY()*_sizeKoef, _sizeKoef, _sizeKoef);
    _point->setBrush(QBrush(Qt::red));
    _point->setPen(QPen(Qt::red));

    _itemList.clear();

    QGraphicsRectItem *pitem = new QGraphicsRectItem(25*_sizeKoef, 48*_sizeKoef, _sizeKoef, _sizeKoef);
    pitem->setBrush(Qt::red);
    pitem->setPen(QPen(Qt::red));
    _itemList.push_back(pitem);
    pitem = new QGraphicsRectItem(25*_sizeKoef, 49*_sizeKoef, _sizeKoef, _sizeKoef);
    pitem->setBrush(Qt::red);
    pitem->setPen(QPen(Qt::red));
    _itemList.push_back(pitem);

    _game->scene()->addItem(_point);
    _game->scene()->addItem(_itemList.front());
    _game->scene()->addItem(_itemList.back());

    connect(_game, SIGNAL(signalSnakeGrown(int, int)), this, SLOT(slotSnakeGrown(int, int)),Qt::UniqueConnection);
    connect(_game, SIGNAL(signalSnakeMoved(int,int)), this, SLOT(slotSnakeMoved(int,int)),Qt::UniqueConnection);
    connect(_game, SIGNAL(signalBallMoved(int,int)), this, SLOT(slotBallMoved(int,int)),Qt::UniqueConnection);
}

void MainWindow::slotSnakeGrown(int x, int y)
{
    QGraphicsRectItem* pitem = new QGraphicsRectItem(x*_sizeKoef, y*_sizeKoef, _sizeKoef, _sizeKoef);
    pitem->setBrush(Qt::red);
    pitem->setPen(QPen(Qt::red));
    _itemList.push_front(pitem);
    _game->scene()->addItem(_itemList.front());
}

void MainWindow::slotSnakeMoved(int x, int y)
{
    QGraphicsRectItem* pitem = new QGraphicsRectItem(x*_sizeKoef, y*_sizeKoef, _sizeKoef, _sizeKoef);
    pitem->setBrush(Qt::red);
    pitem->setPen(QPen(Qt::red));
    _itemList.push_front(pitem);
    delete _itemList.back();
    _itemList.pop_back();
    _game->scene()->addItem(_itemList.front());
}

void MainWindow::slotBallMoved(int x, int y)
{
    delete _point;
    _point = new QGraphicsRectItem(x*_sizeKoef, y*_sizeKoef, _sizeKoef, _sizeKoef);
    _point->setBrush(Qt::red);
    _point->setPen(QPen(Qt::red));
    _game->scene()->addItem(_point);
}

void MainWindow::resizeEvent(QResizeEvent* e)
{
    static bool isNeeded = false;
    if(isNeeded)
    {
    QMainWindow::resizeEvent(e);
    _game->fitInView(_game->scene()->sceneRect(), Qt::KeepAspectRatio);
    }
    isNeeded = true;
}








