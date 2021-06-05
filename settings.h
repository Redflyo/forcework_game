#ifndef SETTINGS_H
#define SETTINGS_H
#include <iostream>
#include <vector>
#include <QKeyEvent>
using namespace std;
class Settings
{
private:
    string itsTempleFile;
    int itsLeft1=-50;
    int itsLeft2 = Qt::Key_Left;
    int itsRight1=-50;
    int itsRight2 = Qt::Key_Right;
    int itsJump1=-50;
    int itsJump2 = Qt::Key_Up;
    double itsTimer;
    float itsReactionTimeIA;
    int itsAreaDetected;
    float itsGravity;
    string itsShootButton;

public:
    Settings(string templeFiles);
    void split(std::string str, char charSeparation, std::vector<std::string> &vecToReturn);
    bool isTopFive(double score, int position);
    void writeTempleFile(string name, double score, int position);
    void displayTemple();
    bool validLeft(int key);
    bool validRight(int key);
    bool validJump(int key);

    void setItsLeft1(int value);
    void setItsRight1(int value);
    void setItsJump1(int value);
};

#endif // SETTINGS_H
