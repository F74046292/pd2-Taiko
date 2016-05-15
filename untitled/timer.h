#ifndef MYTIMER_H
#define MYTIMER_H
#include <QtCore>

class Timer: public QObject
{
    Q_OBJECT
public:
    Timer();
    QTimer *timer;
public slots:
    void MySlot();
};

#endif // MYTIMER_H
