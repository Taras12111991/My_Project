#ifndef WIDGETVIEW_H
#define WIDGETVIEW_H

#include <QWidget>
#include "game.h"
#include "mybutton.h"
#include <list>
using std::list;


class WidgetView : public QWidget
{
    Q_OBJECT
public:
    WidgetView(QWidget *par = 0);
public slots:
    void snakeMoved(int, int);
    void snakeGrown(int, int);
    void appleMoved(int, int);
protected:
    void keyPressEvent(QKeyEvent *event);
    //bool eventFilter( QObject *obj, QEvent *evt );
private:
    MyButton* _arr[50][50];
    list<MyButton*> butList;
    Game *game;
};

#endif // WIDGETVIEW_H
