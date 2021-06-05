#ifndef SETTINGS_H
#define SETTINGS_H
#include <iostream>
#include <vector>
#include <QKeyEvent>

using namespace std;
  struct PlayerScore{string name; double score; int position;};
class Settings
{
private:
    string itsTempleFile="../forceWork/hallOfFame.txt";
    int itsLeft1=-50;
    int itsLeft2=Qt::Key_Left;
    int itsRight1=-50;
    int itsRight2=Qt::Key_Right;
    int itsJump1=-50;
    int itsJump2=Qt::Key_Up;
    double itsTimer;
    float itsReactionTimeIA;
    int itsAreaDetected;
    float itsGravity;
    string itsShootButton;

public:
    Settings();
    void split(string str, char charSeparation, std::vector<std::string> &vecToReturn);
    bool isTopFive(PlayerScore &playerScore);
    void writeTempleFile(PlayerScore &playerScore);
    void displayTemple();
    bool validLeft(int key);
    bool validRight(int key);
    bool validJump(int key);

    void setItsLeft1(int value);
    void setItsRight1(int value);
    void setItsJump1(int value);
};

#endif // SETTINGS_H
