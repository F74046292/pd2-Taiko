#ifndef DRUM_H
#define DRUM_H
#include<iostream>
#include <QGraphicsPixmapItem>

using namespace std;

class Drum : public QGraphicsPixmapItem
{
public:
    Drum();
    void advance(int phase);
    int speed;

};

#endif // DRUM_H
