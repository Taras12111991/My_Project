#-------------------------------------------------
#
# Project created by QtCreator 2017-06-20T14:48:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    block.cpp \
    snake.cpp \
    game.cpp \
    widgetview.cpp \
    mybutton.cpp

HEADERS  += mainwindow.h \
    block.h \
    snake.h \
    game.h \
    widgetview.h \
    mybutton.h

FORMS    += mainwindow.ui
