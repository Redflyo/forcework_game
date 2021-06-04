#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "settings.h"

int main(int argc, char *argv[])
{
  /*int pos;
  double score0=31.2, score1=6.2, score2=21.6, score3=78, score4=12.8, score5=98.6;
  std::string name0="remi", name1="enzo", name2="rmi", name3="nzo", name4="rem", name5="enz";
  Settings setting("../forceWork/lemurdeschampions.txt");
  setting.writeTempleFile(name0, score0, pos);
  qDebug() << "yo";
  if(setting.isTopFive(score1, pos)) qDebug()<<"jesuismeilleur";setting.writeTempleFile(name1, score1, pos);
*/



  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
