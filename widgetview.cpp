#include "widgetview.h"
#include <QGridLayout>

WidgetView::WidgetView(QWidget *par): QWidget(par)
{
    QGridLayout *playout = new QGridLayout(this);
    playout->setHorizontalSpacing(1);
    playout->setVerticalSpacing(1);
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            {
                _arr[i][j] = new MyButton(i, j);
                playout->addWidget(_arr[i][j], i, j);
                _arr[i][j]->resize(20,20);
                _arr[i][j]->setCheckable(true);
            }
    butList.push_back(_arr[48][25]);
    _arr[48][25]->setChecked(true);
    butList.push_back(_arr[49][25]);
    _arr[49][25]->setChecked(true);

    _arr[25][25]->setChecked(true);

    setFixedSize(700,700);

    game = new Game();
    game->setFocus();

    QObject::connect(game, SIGNAL(signalBallMoved(int,int)), this, SLOT(appleMoved(int,int)));
    QObject::connect(game, SIGNAL(signalSnakeMoved(int,int)), this, SLOT(snakeMoved(int,int)));
    QObject::connect(game, SIGNAL(signalSnakeGrown(int,int)), this, SLOT(snakeGrown(int,int)));

    //game->installEventFilter(this);
}

void WidgetView::snakeGrown(int j, int i)
{
    _arr[i][j]->setChecked(true);
    butList.push_front(_arr[i][j]);
}

void WidgetView::snakeMoved(int j, int i)
{
    butList.push_front(_arr[i][j]);
    _arr[i][j]->setChecked(true);
    butList.back()->setChecked(false);
    butList.pop_back();
}

void WidgetView::appleMoved(int j, int i)
{
    _arr[i][j]->setChecked(true);
}

void WidgetView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_W:
        game->slotStartMoving();
        break;
    case Qt::Key_A:
        game->slotTurnSnakeLeft();
        break;
    case Qt::Key_D:
        game->slotTurnSnakeRight();
        break;
    case Qt::Key_P:
        game->slotPause();
    }
    QWidget::keyPressEvent(event);
}

/*bool WidgetView::eventFilter( QObject *obj, QEvent *evt )
  {
    if( evt->type() == QEvent::KeyPress )
    {
    if (obj == game)
    {
        QKeyEvent* e = static_cast<QKeyEvent*>(evt);
    switch (e->key())
    {
    case Qt::Key_Up:
        game->slotStartMoving();
        break;
    case Qt::Key_Left:
        game->slotTurnSnakeLeft();
        break;
    case Qt::Key_Right:
        game->slotTurnSnakeRight();
        break;
    case Qt::Key_P:
        game->slotPause();
    }
    return true;
    }
    }

    return WidgetView::eventFilter( obj, evt );
  }*/





