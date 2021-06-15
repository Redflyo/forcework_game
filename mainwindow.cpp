#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsEffect>
#include <fstream>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1200,399);
    setWindowTitle("ForceWork");
    setWindowIcon(QIcon("../forcework_game/data/logo.png"));
    m_opaEffect = new QGraphicsOpacityEffect(this);
    m_opaEffect->setOpacity(0.85);
    // Timer du jeu
    gameTimer = new QTimer();
    itsSetting = new Settings();
    //Choisir la fenetre affiché au demarrage (StartMenu)
    ui->stackedWidget->setCurrentWidget(ui->StartMenu);
    //qDebug()<<(ui->stackedWidget->currentIndex());
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

    perso2 = new QImage;
    perso2->load("../forcework_game/data/persoStopG.png");

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
    persoMarcher6_6G->load("../forcework_game/data/persoMarcher6-6G.png");

    balleDroite = new QImage;
    balleDroite->load("../forcework_game/data/BalleD.png");

    balleGauche = new QImage;
    balleGauche->load("../forcework_game/data/BalleG.png");

    *persoMarcher1_6D = persoMarcher1_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher2_6D = persoMarcher2_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher3_6D = persoMarcher3_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher4_6D = persoMarcher4_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher5_6D = persoMarcher5_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher6_6D = persoMarcher6_6D->scaled(QSize(sizeBlock,sizeBlock*2));

    *persoMarcher1_6G = persoMarcher1_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher2_6G = persoMarcher2_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher3_6G = persoMarcher3_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher4_6G = persoMarcher4_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher5_6G = persoMarcher5_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher6_6G = persoMarcher6_6G->scaled(QSize(sizeBlock,sizeBlock*2));


    *perso1 = perso1->scaled(QSize(sizeBlock,sizeBlock*2));
    *perso2 = perso2->scaled(QSize(sizeBlock,sizeBlock*2));

    *flag = flag->scaled(QSize(sizeBlock,sizeBlock*2));
    *flag2 = flag2->scaled(QSize(sizeBlock,sizeBlock*2));


    *image1 = image1->scaled(QSize(sizeBlock,sizeBlock));
    *image2 = image2->scaled(QSize(sizeBlock,sizeBlock));
    *image3 = image3->scaled(QSize(sizeBlock,sizeBlock));
    *image4 = image4->scaled(QSize(sizeBlock,sizeBlock));
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
    else if(ui->stackedWidget->currentIndex() == 1)
    {
        if ( ev->type() == QEvent::KeyPress ) {

            currentGame->getPressedKeys() += ((QKeyEvent*)ev)->key();

        }
    }
    //------------------------------------------------------------------------
    if(ev->key()== Qt::Key_A)
    {
        ui->label_winscore->setText(currentGame->getItsSettings()->getItsTimer());
        Win();
    }
    //--------------------------------------------------------------------------------
}
void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ui->stackedWidget->currentIndex() == 4) currentGame->getPressedKeys().clear();
    if(ui->stackedWidget->currentIndex() == 1)
    {
        if ( ev->type() == QEvent::KeyRelease )
        {
            currentGame->getPressedKeys() -= ((QKeyEvent*)ev)->key();
        }

    }
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && ui->stackedWidget->currentIndex() == 1)
    {
        Bullet *bull = new Bullet((Personnage*)currentGame->getPlayer());
        currentGame->addBullet(bull);
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

void MainWindow::Win()
{
    ui->frame_menuwin->setGraphicsEffect(m_opaEffect);
    ui->stackedWidget->setCurrentWidget(ui->MenuWin);
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

    itsPersoTimeD++;
    itsPersoTimeG++;
    ui->lcdNumber->display(currentGame->getTickScore());
    currentGame->getItsSettings()->setItsTimer(currentGame->getTickScore());
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    if(ui->stackedWidget->currentIndex() == 1 || ui->stackedWidget->currentIndex() == 4 || ui->stackedWidget->currentIndex() == 5)
    {
        blocks = currentGame->getItsMap().getItsBlocks();
        int offSetX = currentGame->getCamera().getItsOffsetX();
        int offSetY = currentGame->getCamera().getItsOffsetY();
        QPainter * painter = new QPainter(this);
        int locX,locY;
        for (int i = 0; i<(int)blocks.size() ;i++ ) {


            locY = blocks[i].getItsBlockY()*sizeBlock+ offSetY;
            locX = blocks[i].getItsBlockX()*sizeBlock+ offSetX;
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

                        painter->drawImage(locX,locY-sizeBlock, *flag);
                        }
                        else
                        {

                        painter->drawImage(locX,locY-sizeBlock, *flag2);
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
            itsPersoTimeD = 0;
            itsPersoTimeG = 0;

            if (itsPersoSens == false)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *perso1);
            }
            if (itsPersoSens == true)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *perso2);
            }
        }
        if (currentGame->getPlayer()->getItsAnimationImage() == 1)
        {
            itsPersoTimeD = 0;
            if (itsPersoTimeG >= 0 and itsPersoTimeG <15)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher1_6G);
            }
            if (itsPersoTimeG >= 15 and itsPersoTimeG <30)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher2_6G);
            }
            if (itsPersoTimeG >= 30 and itsPersoTimeG <45)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher3_6G);
            }
            if (itsPersoTimeG >= 45 and itsPersoTimeG <60)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher4_6G);
            }
            if (itsPersoTimeG >= 60 and itsPersoTimeG <75)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher5_6G);
            }
            if (itsPersoTimeG >= 75 and itsPersoTimeG <90)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher6_6G);

            }
            if (itsPersoTimeG == 90)
            {

            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher1_6G);

            itsPersoTimeG = 0;
            }
            itsPersoSens = true;
        }
        if (currentGame->getPlayer()->getItsAnimationImage() == 2)
        {
            itsPersoTimeG = 0;
            if (itsPersoTimeD >= 0 and itsPersoTimeD <15)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher1_6D);
            }
            if (itsPersoTimeD >= 15 and itsPersoTimeD <30)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher2_6D);
            }
            if (itsPersoTimeD >= 30 and itsPersoTimeD <45)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher3_6D);
            }
            if (itsPersoTimeD >= 45 and itsPersoTimeD <60)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher4_6D);
            }
            if (itsPersoTimeD >= 60 and itsPersoTimeD <75)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher5_6D);
            }
            if (itsPersoTimeD >= 75 and itsPersoTimeD <90)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher6_6D);
            }
            if (itsPersoTimeD == 90)
            {
            itsPersoTimeD = 0;
             painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher1_6D);
            }
            itsPersoSens = false;

        }
        if(currentGame->getItsBullets().size()!=0)
        {
            for(Bullet * bullet : currentGame->getItsBullets())
            {
                if(itsPersoSens == true) painter->drawImage((bullet->getItsOwner())->getItsX(), bullet->getItsOwner()->getGunY(), *balleGauche);
                else if(itsPersoSens == false) painter->drawImage((bullet->getItsOwner())->getItsX()+sizeBlock, bullet->getItsOwner()->getGunY(), *balleDroite);
            }
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

void MainWindow::on_PB_startmenu_fromMenuWin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->StartMenu);
}

void MainWindow::on_PB_startNewGame_fromMenuWin_clicked()
{
    delete currentGame;
    delete itsSetting;
    itsSetting = new Settings;
    ui->PB_launchGame->click();
}
