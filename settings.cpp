#include <fstream>
#include <QDebug>

using namespace std;

#include "settings.h"


void Settings::setItsLeft1(int value)
{
    itsLeft1 = value;
}

void Settings::setItsRight1(int value)
{
    itsRight1 = value;
}

void Settings::setItsJump1(int value)
{
    itsJump1 = value;
}

Settings::Settings(string templeFile)
{
    itsTempleFile=templeFile;
}

void Settings::split(std::string strToSplit, char charSeparation, std::vector<std::string> &vecToReturn)
{
  string x="";
  for(int i=0; i<strToSplit.size(); ++i)
  {
    if(strToSplit[i]!=charSeparation) x+=strToSplit[i];
    else {vecToReturn.push_back(x); x="";}
  }
  vecToReturn.push_back(x);
}

bool Settings::isTopFive(double score, int position)
{
  vector<string> vecScoresNames;
  vector<double>vecScores;
  string lineOfFile;
  bool isTop=false;
  ifstream inputFile(itsTempleFile);
  if(!inputFile) qDebug() << "Reading error";
  else qDebug() << "Reading okk";
  while(!inputFile.eof())
  {
    getline(inputFile, lineOfFile);
    split(lineOfFile, ':', vecScoresNames);
  }
  for(int i=0; i<vecScoresNames.size(); i+=2)
  {
  qDebug() << "mhhh";
    vecScores.push_back(stod(vecScoresNames[i]));
    if(score<vecScores[vecScores.size()-1]) position=vecScores.size()-1;
  }
  if(vecScores.size()>=5)
  {
    if(score<vecScores[4]) isTop=true;
  }
  else isTop=true;
  qDebug() << isTop;
  return isTop;
}

void Settings::writeTempleFile(string name, double score, int position)
{
  ofstream outputFile(itsTempleFile);
  ifstream inputFile(itsTempleFile);
  string lineOfFile;
  vector<string> vecScoresNames;
  while(!inputFile.eof())
  {
    getline(inputFile, lineOfFile);
    split(lineOfFile, ':', vecScoresNames);
  }
  position*=2;
  qDebug() << position;
  vector<string>::iterator it=vecScoresNames.begin()+position;
  vecScoresNames.insert(it, name);
  qDebug() << "yaa";
  //vecScoresNames.insert(it, name);
  qDebug() << "yoo";
  for(int i=0; i<vecScoresNames.size(); i+=2)
  {
    outputFile << vecScoresNames[i] << ":" << vecScoresNames[i+1] << endl;
  }
  outputFile.close();
  inputFile.close();
}

void Settings::displayTemple()
{

}

bool Settings::validLeft(int key)
{
    return(itsLeft1 == key || itsLeft2 == key);
}

bool Settings::validRight(int key)
{
    return(itsRight1 == key || itsRight2 == key);
}

bool Settings::validJump(int key)
{
    return(itsJump1 == key || itsJump2 == key);
}






















