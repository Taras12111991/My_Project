#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
public:
    MyButton(int x, int y, QPushButton *par = 0);
    int getX() const {return _x;}
    int getY() const {return _y;}
private:
    int _x;
    int _y;
};

#endif // MYBUTTON_H
