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
    string itsHallOfFameFile="../forceWork/hallOfFame.txt";
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
    ///
    /// \brief split : fonction servant a decouper un string en plusieurs string grace a un caractere separateur et a les inserer dans un vecteur
    /// \param str : string a decouper
    /// \param charSeparation : caractere separateur
    /// \param vecToReturn : vecteur contenant les differents strings decoupes renvoye par reference
    ///
    void split(string str, char charSeparation, std::vector<std::string> &vecToReturn);
    ///
    /// \brief isTopFive : fonction nous indiquant si le nouveau score se situe dans le top cinq des meilleurs scores puis si oui, renvoie par reference sa position exacte dans le top
    /// \param playerScore : le joueur avec son score
    /// \return true si il est dans le top cinq, false sinon
    ///
    bool isTopFive(PlayerScore &playerScore);
    ///
    /// \brief writeHallOfFameFile : fonction qui ecrit dans le fichier hallOfFame.txt le top cinq avec un joueur et son score par ligne de la sorte: score:nom
    /// \param playerScore : le joueur avec son nom et sa position dans le top cinq
    ///
    void writeHallOfFameFile(PlayerScore &playerScore);
    ///
    /// \brief getItsHallOfFameFile : fonction qui renvoie le nom du fichier
    /// \return le nom du fichier
    ///
    string getItsHallOfFameFile();
    bool validLeft(int key);
    bool validRight(int key);
    bool validJump(int key);

    void setItsLeft1(int value);
    void setItsRight1(int value);
    void setItsJump1(int value);
};

#endif // SETTINGS_H
