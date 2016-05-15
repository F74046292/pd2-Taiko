#include "drum.h"

Drum::Drum()
{
    speed=5;
}
void Drum::advance(int phase)
{
    this->setPos(this->pos().x()-speed,this->pos().y());
}
