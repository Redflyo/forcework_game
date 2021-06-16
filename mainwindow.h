#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QKeyEvent"
#include "forcework.h"
#include "settings.h"
#include <QTimer>
#include <QPaintEvent>
#include <QSet>
#include <QEvent>
#include <QGraphicsEffect>
#include <QMouseEvent>
#include "ia.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "animation.h"

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
    void mousePressEvent(QMouseEvent *event);
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
    /// \brief on_pushButton_clicked Bouton pour aller a la page Settings
    ///
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_PB_launchGame_clicked();

    void Win();

    void Loose();

    void gameLoop();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_PB_startmenu_fromMenuWin_clicked();

    void on_PB_startNewGame_fromMenuWin_clicked();

    void on_PB_startNewGame_fromMenuWin_2_clicked();

    void on_PB_startmenu_fromMenuWin_2_clicked();

    void on_PB_startmenu_fromMenuWin_3_clicked();

private:
    PlayerScore *p10 = new PlayerScore;
    std::vector<Block> blocks;
    QGraphicsOpacityEffect *m_opaEffect;

    QImage *heart;


    Animation * animation;
    void launchGame();
    QTimer * gameTimer;
    ForceWork * currentGame = nullptr;
    Ui::MainWindow *ui;
    int editKey;
    Settings * itsSetting;
};
#endif // MAINWINDOW_H
