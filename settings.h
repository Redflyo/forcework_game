#ifndef SETTINGS_H
#define SETTINGS_H
#include <iostream>
using namespace std;
class Settings
{
private:
    string itsTemple;
    string itsLeft1;
    string itsLeft2;
    string itsRight1;
    string itsRight2;
    string itsJump1;
    string itsJump2;
    double itsTimer;
    float itsReactionTimeIA;
    int itsAreaDetected;
    float itsGravity;
    string itsShootButton;

public:
    Settings();
};

#endif // SETTINGS_H
