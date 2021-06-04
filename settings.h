#ifndef SETTINGS_H
#define SETTINGS_H
#include <iostream>
#include <vector>
using namespace std;
class Settings
{
private:
    string itsTempleFile;
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
    Settings(string templeFiles);
    void split(std::string str, char charSeparation, std::vector<std::string> &vecToReturn);
    bool isTopFive(double score, int position);
    void writeTempleFile(string name, double score, int position);
    void displayTemple();
};

#endif // SETTINGS_H
