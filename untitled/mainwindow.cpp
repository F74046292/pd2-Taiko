#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //set new window
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(5,5,600,400); //window size
    settingBg(); //background
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingBg()
{
    QImage bg;
    bg.load(":/picture/太鼓達人.jpg");
    bg = bg.scaled(610,410);//background size
    scene->setBackgroundBrush(bg);
    scene->Init();
}
