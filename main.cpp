#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "settings.h"

int main(int argc, char *argv[])
{


  PlayerScore *p1 = new PlayerScore;
  p1->name="remi"; p1->score=31.2;
  PlayerScore *p2 = new PlayerScore;
  p2->name="enzo"; p2->score=60.2;
  PlayerScore *p3 = new PlayerScore;
  p3->name="moshi moshi"; p3->score=21.6;
  PlayerScore *p4 = new PlayerScore;
  p4->name="nzo"; p4->score=78.3;
  PlayerScore *p5 = new PlayerScore;
  p5->name="rem"; p5->score=98.8;
  PlayerScore *p6 = new PlayerScore;
  p6->name="bernard"; p6->score=52.6;
  PlayerScore *p7 = new PlayerScore;
  p7->name="boubagaa"; p7->score=50.2;
  PlayerScore *p8 = new PlayerScore;
  p8->name="redflyo"; p8->score=8.4;
  Settings setting;

  if(setting.isTopFive(*p1)) setting.writeHallOfFameFile(*p1);
  if(setting.isTopFive(*p2)) setting.writeHallOfFameFile(*p2);
  if(setting.isTopFive(*p3)) setting.writeHallOfFameFile(*p3);
  if(setting.isTopFive(*p4)) setting.writeHallOfFameFile(*p4);
  if(setting.isTopFive(*p5)) setting.writeHallOfFameFile(*p5);
  if(setting.isTopFive(*p6)) setting.writeHallOfFameFile(*p6);

  if(setting.isTopFive(*p7)) setting.writeHallOfFameFile(*p7);
  if(setting.isTopFive(*p8)) setting.writeHallOfFameFile(*p8);



  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
