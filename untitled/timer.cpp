#include"timer.h"


Timer::Timer()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));

    timer->start(1000);
}

void MyTimer::MySlot()
{

}
