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

    ///
    /// \brief editLfunc Signigie que la touche qui va etre edite dans le menu est celle de la touche gauche
    ///
    void editLfunc();
    ///
    /// \brief editRfunc Signigie que la touche qui va etre edite dans le menu est celle de la touche droite
    ///
    void editRfunc();
    ///
    /// \brief editJfunc Signigie que la touche qui va etre edite dans le menu est celle de la touche de saut
    ///
    void editJfunc();
    ///
    /// \brief keyPressEvent Enregistre les touches enfoncés
    /// \param ev evenement de keyPressEvent
    ///
    void keyPressEvent(QKeyEvent*ev);
    ///
    /// \brief keyReleaseEvent Enregistre les touches relachés
    /// \param ev evenement de keyReleaseEvent
    ///
    void keyReleaseEvent(QKeyEvent * ev);
    ///
    /// \brief mousePressEvent Enregistre que un bouton de la souris est enfoncé
    /// \param event evenement de mousePressEvent
    ///
    void mousePressEvent(QMouseEvent *event);
public:
    ///
    /// \brief MainWindow constructeur
    /// \param parent pointeur du parent de MainWindow
    ///
    MainWindow(QWidget *parent = nullptr);
    /// \brief Destructeur MainWindow
    ~MainWindow();
    ///
    /// \brief loadImage charge les images nécessaire à l'interface
    ///
    void loadImage();
    ///
    /// \brief displayHallOfFame affiche les temple de la renommé
    ///
    void displayHallOfFame();
    ///
    /// \brief viewLabelIntro affiche le label lorsque le turoriel est lancé
    ///
    void viewLabelIntro();

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

    ///
    /// \brief Win affiche la victoire du joueur
    ///
    void Win();
    ///
    /// \brief Loose affiche la défaite du joueur
    ///
    void Loose();
    ///
    /// \brief gameLoop methode permettant d'appeller les autres methode afin de derouler le jeu
    ///
    void gameLoop();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_PB_startmenu_fromMenuWin_clicked();

    void on_PB_startNewGame_fromMenuWin_clicked();

    void on_PB_startNewGame_fromMenuWin_2_clicked();

    void on_PB_startmenu_fromMenuWin_2_clicked();

    void on_PB_startmenu_fromMenuWin_3_clicked();

    void on_pushButton_9_clicked();

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
