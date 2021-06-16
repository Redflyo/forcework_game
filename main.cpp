#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "settings.h"

int main(int argc, char *argv[])
{



  Settings setting;


  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
