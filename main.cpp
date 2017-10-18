#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView>

#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include "widgetview.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //WidgetView view;
    //view.show();

    return a.exec();
}
