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
    image1->load("12ttp.png");

    image2 = new QImage;
    image2->load("18ttp.png");

    image3 = new QImage;
    image3->load("19ttp.png");

    image4 = new QImage;
    image4->load("3ttp.png");

    flag = new QImage;
    flag->load("20ttp.png");
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

                        painter->drawImage(locX,locY-21, *flag);

                    }
                }

                if (blocks[i].getItsBlockType() == 4){
                    painter->drawImage(locX,locY, *image4);

                }

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
