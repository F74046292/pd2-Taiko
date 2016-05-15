#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget wid;
    int screenW= 610;
    int screenH= 410;





    w.setGeometry(wid.screen()->width()/2 - (screenW/2),wid.screen()->height()/2 - (screenH/2),screenW,screenH);
    w.show();

    return a.exec();
}
