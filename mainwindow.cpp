#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Timer du jeu
    gameTimer = new QTimer();
    itsSetting = new Settings("");
    //Choisir la fenetre affiché au demarrage (StartMenu)
    ui->stackedWidget->setCurrentWidget(ui->StartMenu);
    qDebug()<<(ui->stackedWidget->currentIndex());
    loadImage();

    //Connect des differents boutons
    connect(ui->editL,SIGNAL(clicked()), this, SLOT(editLfunc()));
    connect(ui->editR,SIGNAL(clicked()), this, SLOT(editRfunc()));
    connect(ui->editJ,SIGNAL(clicked()), this, SLOT(editJfunc()));
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(gameLoop()));

}

MainWindow::~MainWindow()
{
    delete gameTimer;
    delete itsSetting;
    delete ui;
}

void MainWindow::loadImage()
{
    image1 = new QImage;
    image1->load("12ttp.png");

    image2 = new QImage;
    image2->load("18ttp.png");

    image3 = new QImage;
    image3->load("19ttp.png");

    image4 = new QImage;
    image4->load("3ttp.png");

    image5 = new QImage;
    image5->load("20ttp.png");

}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Settings);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->StartMenu);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HOF);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->StartMenu);
}



void MainWindow::keyPressEvent(QKeyEvent*ev)
{
    if(editKey == 0)
    {
        ui->keyL1->setText(ev->text());
        itsSetting->setItsLeft1(ev->key());
    }
    if(editKey == 1)
    {
        ui->keyR1->setText(ev->text());
        itsSetting->setItsRight1(ev->key());
    }
    if(editKey == 2)
    {
        ui->keyJ1->setText(ev->text());
        itsSetting->setItsJump1(ev->key());
    }


    if(ui->stackedWidget->currentIndex() == 1)
    {
        if ( ev->type() == QEvent::KeyPress ) {

            currentGame->getPressedKeys() += ((QKeyEvent*)ev)->key();

        }
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ui->stackedWidget->currentIndex() == 1)
    {
        if ( ev->type() == QEvent::KeyRelease )
        {
            currentGame->getPressedKeys() -= ((QKeyEvent*)ev)->key();
        }

    }
}


void MainWindow::editLfunc()
{
    ui->keyL1->setText(" Press a key :");
    editKey = 0;
}

void MainWindow::editRfunc()
{
    ui->keyR1->setText(" Press a key :");
    editKey = 1;
}

void MainWindow::editJfunc()
{
    ui->keyJ1->setText(" Press a key :");
    editKey = 2;
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_PB_launchGame_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->GameWidget);
    launchGame();




}

void MainWindow::launchGame()
{
    this->setFixedSize(1200,399);
    currentGame = new ForceWork(itsSetting);
    gameTimer->start(10);

}

void MainWindow::gameLoop()
{

    currentGame->gameLoop();
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    if(ui->stackedWidget->currentIndex() == 1)
    {
        blocks = currentGame->getItsMap().getItsBlocks();
        int offSetX = currentGame->getCamera().getItsOffsetX();
        int offSetY = currentGame->getCamera().getItsOffsetY();
        QPainter * painter = new QPainter(this);
        int locX,locY;
        for (int i = 0; i<(int)blocks.size() ;i++ ) {


            locY = blocks[i].getItsBlockY()*21+ offSetY;
            locX = blocks[i].getItsBlockX()*21+ offSetX;
            if(locX > -50 && locX < 1200)
            {
                if (blocks[i].getItsBlockType() == 2){
                    painter->drawImage(locX,locY, *image1);
                }
                if (blocks[i].getItsBlockType() == 3){
                    painter->drawImage(locX,locY, *image2);
                }
                if (blocks[i].getItsBlockType() == 0 or blocks[i].getItsBlockType() == 1){
                    painter->drawImage(locX,locY, *image3);

                }
                if (blocks[i].getItsBlockType() == 1){

                    painter->drawImage(locX,locY, *image5);

                }
                if (blocks[i].getItsBlockType() == 4){
                    painter->drawImage(locX,locY, *image4);

                }
            }
        }
            painter->end();
    }

}
