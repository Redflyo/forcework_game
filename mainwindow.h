#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QKeyEvent"

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
public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent*ev);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    int editKey;
    QEvent *Lkey;
    QEvent *Rkey;
    QEvent *Jkey;
};
#endif // MAINWINDOW_H
