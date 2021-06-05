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

private slots:


    void paintEvent(QPaintEvent *event);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_PB_launchGame_clicked();


    void gameLoop();

private:



    std::vector<Block> blocks;

    QImage *image1;
    QImage *image2;
    QImage *image3;
    QImage *image4;
    QImage *image5;

    void launchGame();
    QTimer * gameTimer;
    ForceWork * currentGame = nullptr;
    Ui::MainWindow *ui;
    int editKey;
    Settings * itsSetting;
};
#endif // MAINWINDOW_H
