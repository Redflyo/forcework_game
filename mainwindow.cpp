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
    QRegularExpression re("^[^,]{0,16}$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(re, this);
    ui->lineEdit->setValidator(validator);
    ui->groupBox->setVisible(false);
    ui->introLabel->setAlignment(Qt::AlignCenter);

}

MainWindow::~MainWindow()
{
    delete heart;
    delete m_opaEffect;
    delete gameTimer;
    delete itsSetting;
    delete ui;
}

void MainWindow::loadImage()
{


    heart = new QImage;
    //heart->load("../forcework_game/data/heart.webp");
    heart->load("../forcework_game/data/heartP.png");



    *heart = heart->scaled(QSize(sizeBlock/2,sizeBlock/2));
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
    itsSetting->split(lineOfFile, ',', vecScoresNames);
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

void MainWindow::viewLabelIntro()
{
    if (itsSetting->getItsTutorial() == false or currentGame->noteIntro() == "ERROR")
    {
       ui->introLabel->setVisible(false);
    }
    else
    {
        ui->introLabel->setVisible(true);
        ui->introLabel->setText(currentGame->noteIntro());
    }
}

void MainWindow::on_pushButton_clicked()
{
        QSound::play("../forcework_game/data/minecraft_click.wav");
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
    /*if(ev->key()==Qt::Key_A)
    {
        Loose();
    }*/
    if(editKey == 0 && ui->stackedWidget->currentIndex()==2)
    {
        ui->keyL1->setText(ev->text());
        itsSetting->setItsLeft1(ev->key());
    }
    if(editKey == 1 && ui->stackedWidget->currentIndex()==2)
    {
        ui->keyR1->setText(ev->text());
        itsSetting->setItsRight1(ev->key());
    }
    if(editKey == 2 && ui->stackedWidget->currentIndex()==2)
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


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && ui->stackedWidget->currentIndex() == 1)
    {
        Bullet *bull = new Bullet((Personnage*)currentGame->getPlayer(), currentGame->getPlayer()->getDirection());
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
    //ui->lineEdit->setText("");
    ui->stackedWidget->setCurrentWidget(ui->GameWidget);
    launchGame();
}

void MainWindow::Win()
{
    ui->frame_menuwin->setGraphicsEffect(m_opaEffect);
    if(itsSetting->getItsTutorial()==false)
    {
        p10->score = (ui->label_winscore->text().toStdString());
        if(itsSetting->isTopFive(*p10))
        {
            ui->groupBox->setVisible(true);
        }
    }
    else
    {
        itsSetting->setItsTutorial(false);
    }
    ui->stackedWidget->setCurrentWidget(ui->MenuWin);
    gameTimer->stop();
}

void MainWindow::Loose()
{
    ui->frame_menuwin->setGraphicsEffect(m_opaEffect);
    ui->stackedWidget->setCurrentWidget(ui->MenuLoose);
    gameTimer->stop();
}

void MainWindow::launchGame()
{

    currentGame = new ForceWork(itsSetting);
    animation = new Animation(currentGame);
    gameTimer->start(10);

}

void MainWindow::gameLoop()
{



    currentGame->gameLoop();
    repaint();


    ui->lcdNumber->display(currentGame->getTickScore());
    currentGame->getItsSettings()->setItsTimer(currentGame->getTickScore());
    animation->updateAnimation();
    if(currentGame->getHaveWin() == true)
    {
        ui->label_winscore->setText(currentGame->getItsSettings()->getItsTimer());
        Win();
    }

    if(animation->getAnimDead() == true)
    {
            Loose();
    }
    viewLabelIntro();

}

void MainWindow::paintEvent(QPaintEvent *event)
{


    if(ui->stackedWidget->currentIndex() == 1 || ui->stackedWidget->currentIndex() == 4 || ui->stackedWidget->currentIndex() == 5)
    {
        QPainter * painter = new QPainter(this);
        animation->drawAnimation(painter);
        //if(currentGame->getPlayer()->getItsLife()>3)currentGame->getPlayer()->setItsLife(3);
        for(int i=0;i<(currentGame->getPlayer()->getItsLife());i++)
        {
             painter->drawImage((i*(sizeBlock/2))+3,5,*heart);
        }




           painter->end();
           delete painter;
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
    ui->PB_launchGame->click();
}

void MainWindow::on_PB_startNewGame_fromMenuWin_2_clicked()
{
    delete currentGame;
    ui->PB_launchGame->click();
}

void MainWindow::on_PB_startmenu_fromMenuWin_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->StartMenu);
}

void MainWindow::on_PB_startmenu_fromMenuWin_3_clicked()
{
    if(itsSetting->getItsTutorial()==false)
    {
     p10->name = (ui->lineEdit->text()).toStdString();
     itsSetting->writeHallOfFameFile(*p10);
    }
     ui->pushButton_4->click();
}

void MainWindow::on_pushButton_9_clicked()
{
    itsSetting->setItsTutorial(true);
    ui->PB_launchGame->click();
}
