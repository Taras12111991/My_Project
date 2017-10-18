#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

#include <QGraphicsRectItem>
#include <QResizeEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void slotNewGame();
    void slotSnakeMoved(int, int);
    virtual void slotSnakeGrown(int, int);
    virtual void slotBallMoved(int, int);
protected:
    void resizeEvent(QResizeEvent *e) override;

private:
    Ui::MainWindow *ui;
    Game *_game;
    list<QGraphicsRectItem*> _itemList;
    QGraphicsRectItem *_point;
    int _sizeKoef;
};

#endif // MAINWINDOW_H
