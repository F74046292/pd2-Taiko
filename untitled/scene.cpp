#include "scene.h"

Scene::Scene()
{
    screenMode = 0;
}

/*the init scene*/
void Scene::Init()
{
    //start
    btn_start = new Btn();
    QPixmap start;
    start.load(":/new/prefix1/in.jpg");
    start = start.scaled(120,120,Qt::KeepAspectRatio);
    btn_start_w = 150;
    btn_start_h = 150;
    btn_start->setPixmap(start);
    btn_start->setPos(80,280);
    addItem(btn_start);

    //exit
    btn_exit = new Btn();
    QPixmap exit;
    exit.load(":/new/prefix1/out.jpg");
    exit = exit.scaled(110,110,Qt::KeepAspectRatio);
    btn_exit_w = 110;
    btn_exit_h = 110;
    btn_exit->setPixmap(exit);
    btn_exit->setPos(420,275);
    addItem(btn_exit);
}

/*the playing  picture*/
void Scene::bgChange()
{
    /*connect*/
    dis = 0;
    /*change to the playing background*/
    QImage bg;
    bg.load(":/new/prefix1/bg.png");
    bg = bg.scaled(610,410);
    this->setBackgroundBrush(bg);
    /*remove start&exit*/
    this->removeItem(btn_start);
    this->removeItem(btn_exit);

    /*return back button setting*/
    btn_back = new Btn();
    QPixmap back;
    back.load(":/new/prefix1/bye.png");
    back = back.scaled(100,100);
    btn_back->setPixmap(back);
    btn_back->setPos(10,0);
    btn_back_w = 100;
    btn_back_h = 100;
    addItem(btn_back);


    /*rail picture setting*/
    rail_rail = new Rail();
    QPixmap rail;
    rail.load(":/new/prefix1/sfieldbg_gogo.png");
    rail = rail.scaled(610,100);
    rail_rail->setPixmap(rail);
    rail_rail->setPos(0,170);
    addItem(rail_rail);

    /*source setting*/
    rail_mouse = new Rail();
    QPixmap mouse;
    mouse.load(":/new/prefix1/malico.png");
    mouse = mouse.scaled(180,180);
    rail_mouse->setPixmap(mouse);
    rail_mouse->setPos(450,90);
    rail_mouse_w = 180;
    rail_mouse_h = 180;
    addItem(rail_mouse);

    /*destination setting*/
    rail_block = new Rail();
    QPixmap block;
    block.load(":/new/prefix1/thousand4.png");
    block = block.scaled(120,120);
    rail_block->setPixmap(block);
    rail_block->setPos(0,145);
    rail_block_w = 150;
    rail_block_h = 150;
    addItem(rail_block);


    for (int i=0;i<30;i++)
    {
       x=rand()%2;
    }
    if (x==0)
    {
    //drum a
    drum_druma= new Drum();
    QPixmap druma;
    druma.load(":/new/prefix1/seahorse.png");
    druma = druma.scaled(250,250);
    drum_druma->setPixmap(druma);
    drum_druma->setPos(400,130);
    addItem(drum_druma);
    }

    if(x==1)
    {
    //drum b
    drum_drumb= new Drum();
    QPixmap drumb;
    drumb.load(":/new/prefix1/Yugiohchen.png");
    drumb = drumb.scaled(150,150);
    drum_drumb->setPixmap(drumb);
    drum_drumb->setPos(450,150);
    addItem(drum_drumb);

    }


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(advance()));
    timer->start(50);

}


/*the back button*/
void Scene::bgRecover()
{
    /*disconnect*/
    dis = 1;

    /*remove the playing picture*/
    removeItem(btn_back);
    removeItem(rail_rail);
    removeItem(rail_block);
    removeItem(rail_mouse);

    /*add back background*/
    QImage bg;
    bg.load(":/picture/太鼓達人.jpg");
    bg = bg.scaled(610,410);
    this->setBackgroundBrush(bg);

    /*add back start page button*/
    addItem(btn_start);
    addItem(btn_exit);

}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(screenMode == 0)
    {
        /*Beginning page*/
        //Start Game button
        if(event->scenePos().x() > btn_start->pos().x() && event->scenePos().x() <= btn_start->pos().x()+btn_start_w)
        {
           if(event->scenePos().y() > btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y()+btn_start_h)
           {
               cout<<"enter the playing window~"<<endl;
               bgChange();
               screenMode = 1;

           }
        }
        /*Beginning page*/
        //Exit button
        else if(event->scenePos().x() > btn_exit->pos().x() && event->scenePos().x() <= btn_exit->pos().x()+btn_exit_w)
        {
            if(event->scenePos().y() > btn_exit->pos().y() && event->scenePos().y() <= btn_exit->pos().y()+btn_exit_h)
            {
                QApplication::exit();
            }
        }
    }
    if (screenMode == 1)
    {
        /*playing page*/
        //return mainwindow button
        if (event->scenePos().x() > btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_back_w)
        {
            if(event->scenePos().y() > btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_back_h)
            {
                cout<<"return the mainwindow~"<<endl;
                disconnect(timer,SIGNAL(timeout()),this,SLOT(advance()));
                bgRecover();
                screenMode = 0;
            }
        }

    }
}




