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

void Settings::setItsTimer(const QString &value)
{
    itsTimer = value;
}

QString Settings::getItsTimer() const
{
    return itsTimer;
}

Settings::Settings()
{
    itsJump1 = -50;
    itsLeft1 = -50;
    itsRight1 = -50;

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
  ifstream inputFile(itsHallOfFameFile);
  if(!inputFile) qDebug() << "Reading error";
  while(!inputFile.eof()) //cre un vecteur avec une fois sur deux le score, puis le nom du joueur, avec en indices pairs les scores et en indices impairs les noms des joueurs
  {                       //exemple: vecScoresNames={score1, nom1, score2, nom2 etc...}
    getline(inputFile, lineOfFile);
    split(lineOfFile, ':', vecScoresNames);

  }
  inputFile.close();
  for(int i=0; i<vecScoresNames.size()-1; i+=2) //cre un vecteur que de scores pour pouvoir les comparer
  {
    vecScores.push_back(stod(vecScoresNames[i]));
  }
  playerScore.position=0;
  for(int i=0; i<vecScores.size(); ++i) //recherche de la position exacte du nouveau score dans le top cinq
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

void Settings::writeHallOfFameFile(PlayerScore &playerScore)
{
  ofstream outputFile(itsHallOfFameFile, ios::app);
  ifstream inputFile(itsHallOfFameFile);
  string lineOfFile;
  vector<string> vecScoresNames;
  while(!inputFile.eof())
  {
    getline(inputFile, lineOfFile);
    split(lineOfFile, ':', vecScoresNames);
  }
  vecScoresNames.pop_back(); //supprime le retour a la ligne automatique du fichier qui a ete pris en compte dans le vecteur
  inputFile.close();
  playerScore.position*=2; //multiplication par 2 car la position a ete trouve dans le vecteur de scores or maintenant nous travaillons avec un vecteur de scores avec les noms
  vector<string>::iterator it=vecScoresNames.begin()+playerScore.position;
  it=vecScoresNames.insert(it, playerScore.name);                           //insertion du nouveau score et nom a la position trouvee precedemment
  vecScoresNames.insert(it, to_string(playerScore.score));
  if(vecScoresNames.size()>10) //supprime les lignes de scores et de noms qui ne sont pas dans le top cinq
  {
    vecScoresNames.pop_back();
    vecScoresNames.pop_back();
  }
  ofstream out(itsHallOfFameFile); //ouvre le fichier en �criture pour effacer son contenu afin d'eviter les doublons lors du re-enregistrement


  for(int i=0; i<vecScoresNames.size()-1; i+=2)
  {
    outputFile << vecScoresNames[i] << ":" << vecScoresNames[i+1] << endl;
  }
  outputFile.close();
}

string Settings::getItsHallOfFameFile()
{
  return itsHallOfFameFile;
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



























