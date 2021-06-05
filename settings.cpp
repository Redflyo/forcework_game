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
  for(int i=0; i<(int)strToSplit.size(); ++i)
  {
    if(strToSplit[i]!=charSeparation) x+=strToSplit[i];
    else {vecToReturn.push_back(x); x="";}
  }
  vecToReturn.push_back(x);
}

bool Settings::isTopFive(PlayerScore &playerScore)
{
  vector<string> vecScoresNames;
  vector<double>vecScores;
  string lineOfFile;
  bool isTop=false;
  ifstream inputFile(itsTempleFile);
  if(!inputFile) qDebug() << "Reading error";
  while(!inputFile.eof())
  {
    getline(inputFile, lineOfFile);
    split(lineOfFile, ':', vecScoresNames);

  }
  inputFile.close();
  for(int i=0; i<vecScoresNames.size()-1; i+=2)
  {
    vecScores.push_back(stod(vecScoresNames[i]));
  }
  playerScore.position=0;
  for(int i=0; i<vecScores.size(); ++i)
  {
    if(playerScore.score<vecScores[i]) {playerScore.position=i; break;}
    else playerScore.position=vecScores.size();
  }
  if(vecScores.size()>=5)
  {
    if(playerScore.score<vecScores[4]) isTop=true;
  }
  else isTop=true;
  return isTop;
}

void Settings::writeTempleFile(PlayerScore &playerScore)
{
  ofstream outputFile(itsTempleFile, ios::app);
  ifstream inputFile(itsTempleFile);
  string lineOfFile;
  vector<string> vecScoresNames;
  while(!inputFile.eof())
  {
    getline(inputFile, lineOfFile);
    split(lineOfFile, ':', vecScoresNames);
  }
  vecScoresNames.pop_back(); //supprime le dernier element qui est la remise a la ligne automatique a la fin du fichier
  inputFile.close();
  playerScore.position*=2;
  vector<string>::iterator it=vecScoresNames.begin()+playerScore.position;
  it=vecScoresNames.insert(it, playerScore.name);
  vecScoresNames.insert(it, to_string(playerScore.score));
  if(vecScoresNames.size()>10)
  {
    vecScoresNames.pop_back();
    vecScoresNames.pop_back();
  }
  ofstream out(itsTempleFile); //ouvre le fichier en écriture pour effacer son contenu afin d'eviter les doublons lors du re-enregistrement


  for(int i=0; i<vecScoresNames.size()-1; i+=2)
  {
    outputFile << vecScoresNames[i] << ":" << vecScoresNames[i+1] << endl;
  }
  outputFile.close();
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
























