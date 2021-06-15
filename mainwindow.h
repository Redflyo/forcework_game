#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QKeyEvent"
#include "forcework.h"
#include "physicalobject.h"
#include "settings.h"
#include <QTimer>
#include <QPaintEvent>
#include <QSet>
#include <QEvent>
#include <QGraphicsEffect>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots :
    void editLfunc();
    void editRfunc();
    void editJfunc();
    void keyPressEvent(QKeyEvent*ev);
    void keyReleaseEvent(QKeyEvent * ev);
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    ///
    /// \brief loadImage charge les images
    ///
    void loadImage();
    void displayHallOfFame();

private slots:


    void paintEvent(QPaintEvent *event);

    ///
    /// \brief on_pushButton_clicked Bouton pour aller Ã  la page Settings
    ///
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_PB_launchGame_clicked();


    void gameLoop();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:

    std::vector<Block> blocks;
    QGraphicsOpacityEffect *m_opaEffect;
    QImage *image1;
    QImage *image2;
    QImage *image3;
    QImage *image4;
    QImage *flag;
    QImage *flag2;

    bool itsFlagBool = false;
    int itsFlagTime = 0;

    // Image du personage principal
    QImage *perso1;
    QImage *perso2;
    QImage *persoMarcher1_6D;
    QImage *persoMarcher2_6D;
    QImage *persoMarcher3_6D;
    QImage *persoMarcher4_6D;
    QImage *persoMarcher5_6D;
    QImage *persoMarcher6_6D;
    QImage *persoMarcher1_6G;
    QImage *persoMarcher2_6G;
    QImage *persoMarcher3_6G;
    QImage *persoMarcher4_6G;
    QImage *persoMarcher5_6G;
    QImage *persoMarcher6_6G;
    QImage *persoSautHD1_5D;
    QImage *persoSautHD2_5D;
    QImage *persoSautHD3_5D;
    QImage *persoSautHD4_5D;
    QImage *persoSautHD5_5D;
    QImage *persoSautHD1_5G;
    QImage *persoSautHD2_5G;
    QImage *persoSautHD3_5G;
    QImage *persoSautHD4_5G;
    QImage *persoSautHD5_5G;

    // image de Rambo

    QImage *rambo1;
    QImage *rambo2;
    QImage *ramboMarcher1_6D;
    QImage *ramboMarcher2_6D;
    QImage *ramboMarcher3_6D;
    QImage *ramboMarcher4_6D;
    QImage *ramboMarcher5_6D;
    QImage *ramboMarcher6_6D;
    QImage *ramboMarcher1_6G;
    QImage *ramboMarcher2_6G;
    QImage *ramboMarcher3_6G;
    QImage *ramboMarcher4_6G;
    QImage *ramboMarcher5_6G;
    QImage *ramboMarcher6_6G;


    // image de Costar

    QImage *costar1;
    QImage *costar2;
    QImage *costarMarcher1_6D;
    QImage *costarMarcher2_6D;
    QImage *costarMarcher3_6D;
    QImage *costarMarcher4_6D;
    QImage *costarMarcher5_6D;
    QImage *costarMarcher6_6D;
    QImage *costarMarcher1_6G;
    QImage *costarMarcher2_6G;
    QImage *costarMarcher3_6G;
    QImage *costarMarcher4_6G;
    QImage *costarMarcher5_6G;
    QImage *costarMarcher6_6G;


    bool itsPersoSens = false;
    int itsPersoTimeD = 0;
    int itsPersoTimeG = 0;
    int itsPersoTimeJump = 0;



    void launchGame();
    QTimer * gameTimer;
    ForceWork * currentGame = nullptr;
    Ui::MainWindow *ui;
    int editKey;
    Settings * itsSetting;
};
#endif // MAINWINDOW_H
