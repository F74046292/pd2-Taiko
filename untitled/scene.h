#ifndef SCENE_H
#define SCENE_H

#include <stdlib.h>
#include <QGraphicsScene>
#include <QApplication>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include"btn.h"
#include"drum.h"
#include"rail.h"
class Scene : public QGraphicsScene
{
public:
    Scene();
    void Init();
    void bgChange();
    void bgRecover();
    //void gameInit();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void keyPressEvent(QKeyEvent *event);


    int screenMode;
    int x;

    //btn
    int dis = 0;
    Btn *btn_start;
    Btn *btn_exit;
    Btn *btn_back;
    int btn_start_w;
    int btn_start_h;
    int btn_exit_w;
    int btn_exit_h;
    int btn_back_w;
    int btn_back_h;


    //rail
    Rail *rail_rail;
    Rail *rail_block;
    Rail *rail_mouse;
    int rail_block_w;
    int rail_block_h;
    int rail_mouse_w;
    int rail_mouse_h;

    //drum
    Drum *drum_druma;
    Drum *drum_drumb;

    //timer
    QTimer *timer;

};

#endif // SCENE_H
