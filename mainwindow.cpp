#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsEffect>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1200,399);
    setWindowTitle("ForceWork");
    setWindowIcon(QIcon("logo.png"));
    m_opaEffect = new QGraphicsOpacityEffect(this);
    m_opaEffect->setOpacity(0.9);
    // Timer du jeu
    gameTimer = new QTimer();
    itsSetting = new Settings();
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
    image1->load("../forcework_game/data/Terre.png");

    image2 = new QImage;
    image2->load("../forcework_game/data/Metal.png");

    image3 = new QImage;
    image3->load("../forcework_game/data/Ciel.png");

    image4 = new QImage;
    image4->load("../forcework_game/data/Herbe.png");

    flag = new QImage;
    flag->load("../forcework_game/data/drapeau1-2.png");

    flag2 = new QImage;
    flag2->load("../forcework_game/data/drapeau2-2.png");

    perso1 = new QImage;
    perso1->load("../forcework_game/data/persoStopD.png");

    persoMarcher1_6D = new QImage;
    persoMarcher1_6D->load("../forcework_game/data/persoMarcher1-6D.png");

    persoMarcher2_6D = new QImage;
    persoMarcher2_6D->load("../forcework_game/data/persoMarcher2-6D.png");

    persoMarcher3_6D = new QImage;
    persoMarcher3_6D->load("../forcework_game/data/persoMarcher3-6D.png");

    persoMarcher4_6D = new QImage;
    persoMarcher4_6D->load("../forcework_game/data/persoMarcher4-6D.png");

    persoMarcher5_6D = new QImage;
    persoMarcher5_6D->load("../forcework_game/data/persoMarcher5-6D.png");

    persoMarcher6_6D = new QImage;
    persoMarcher6_6D->load("../forcework_game/data/persoMarcher6-6D.png");

    persoMarcher1_6G = new QImage;
    persoMarcher1_6G->load("../forcework_game/data/persoMarcher1-6G.png");

    persoMarcher2_6G = new QImage;
    persoMarcher2_6G->load("../forcework_game/data/persoMarcher2-6G.png");

    persoMarcher3_6G = new QImage;
    persoMarcher3_6G->load("../forcework_game/data/persoMarcher3-6G.png");

    persoMarcher4_6G = new QImage;
    persoMarcher4_6G->load("../forcework_game/data/persoMarcher4-6G.png");

    persoMarcher5_6G = new QImage;
    persoMarcher5_6G->load("../forcework_game/data/persoMarcher5-6G.png");

    persoMarcher6_6G = new QImage;
    persoMarcher6_6D->load("../forcework_game/data/persoMarcher6-6G.png");
}

void MainWindow::displayHallOfFame()
{
  ifstream inputFile(itsSetting->getItsHallOfFameFile());
  if(!inputFile) qDebug() << "Reading error";
  vector<string> vecScoresNames;
  string lineOfFile;
  while(!inputFile.eof()) //cre un vecteur avec une fois sur deux le score, puis le nom du joueur, avec en indices pairs les scores et en indices impairs les noms des joueurs
  {
    getline(inputFile, lineOfFile);
    itsSetting->split(lineOfFile, ':', vecScoresNames);
  }
  inputFile.close();
  vecScoresNames.pop_back(); //supprime le retour a la ligne automatique du fichier qui a ete pris en compte dans le vecteur
  for(int i=vecScoresNames.size(); i<10; ++i) //complete les champs vides si il n'y a pas encore eu cinq joueurs enregistres
  {
    vecScoresNames.push_back("-");
  }

  ui->score1->setText(QString::fromStdString(vecScoresNames[0]));
  ui->score1->setAlignment(Qt::AlignCenter);
  ui->name1->setText(QString::fromStdString(vecScoresNames[1]));
  ui->name1->setAlignment(Qt::AlignCenter);
  ui->score2->setText(QString::fromStdString(vecScoresNames[2]));
  ui->score2->setAlignment(Qt::AlignCenter);
  ui->name2->setText(QString::fromStdString(vecScoresNames[3]));
  ui->name2->setAlignment(Qt::AlignCenter);
  ui->score3->setText(QString::fromStdString(vecScoresNames[4]));
  ui->score3->setAlignment(Qt::AlignCenter);
  ui->name3->setText(QString::fromStdString(vecScoresNames[5]));
  ui->name3->setAlignment(Qt::AlignCenter);
  ui->score4->setText(QString::fromStdString(vecScoresNames[6]));
  ui->score4->setAlignment(Qt::AlignCenter);
  ui->name4->setText(QString::fromStdString(vecScoresNames[7]));
  ui->name4->setAlignment(Qt::AlignCenter);
  ui->score5->setText(QString::fromStdString(vecScoresNames[8]));
  ui->score5->setAlignment(Qt::AlignCenter);
  ui->name5->setText(QString::fromStdString(vecScoresNames[9]));
  ui->name5->setAlignment(Qt::AlignCenter);
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
    displayHallOfFame();
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
    if(ui->stackedWidget->currentIndex()==1 && ev->key()== Qt::Key_Escape)
    {
        gameTimer->stop();
        ui->frame_4->setGraphicsEffect(m_opaEffect);
        ui->stackedWidget->setCurrentWidget(ui->EscMenu);
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
    currentGame = new ForceWork(itsSetting);
    gameTimer->start(10);

}

void MainWindow::gameLoop()
{
    itsFlagTime++;
    if (itsFlagTime == 40)
    {
        itsFlagBool =! itsFlagBool;
        itsFlagTime = 0;
    }

    currentGame->gameLoop();
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    if(ui->stackedWidget->currentIndex() == 1 || ui->stackedWidget->currentIndex() == 4)
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
                    if (blocks[i].getItsBlockType() == 1){

                        if (itsFlagBool == false)
                        {

                        painter->drawImage(locX,locY-21, *flag);
                        }
                        if (itsFlagBool == true)
                        {

                        painter->drawImage(locX,locY-21, *flag2);
                        }

                    }
                }

                if (blocks[i].getItsBlockType() == 4){
                    painter->drawImage(locX,locY, *image4);

                }

            }
        }
        if (currentGame->getPlayer()->getItsAnimationImage() == 0)
        {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY(), *perso1);
        }
        if (currentGame->getPlayer()->getItsAnimationImage() == 1)
        {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY(), *persoMarcher1_6G);
        }
        if (currentGame->getPlayer()->getItsAnimationImage() == 2)
        {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY(), *persoMarcher1_6D);
        }
            painter->end();
    }

}

void MainWindow::on_pushButton_5_clicked()
{
    gameTimer->start(10);
    ui->stackedWidget->setCurrentWidget(ui->GameWidget);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->StartMenu);
}

void MainWindow::on_pushButton_8_clicked()
{
    this->close();
}
