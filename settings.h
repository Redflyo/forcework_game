#ifndef SETTINGS_H
#define SETTINGS_H
#include <iostream>
#include <vector>
#include <QKeyEvent>

using namespace std;
  struct PlayerScore{string name; string score; int position;};
class Settings
{
private:
    string itsHallOfFameFile="../forcework_game/data/hallOfFame.txt";
    int itsLeft1=-50;
    int itsLeft2=Qt::Key_Left;
    int itsRight1=-50;
    int itsRight2=Qt::Key_Right;
    int itsJump1=-50;
    int itsJump2=Qt::Key_Up;
    QString itsTimer;
    float itsReactionTimeIA;
    int itsAreaDetected;
    float itsGravity;
    string itsShootButton;
    bool itsTutorial = false;


public:
    ///
    /// \brief Settings constructeur de settings
    ///
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
    ///
    /// \brief validLeft exprime si la touche permet un mouvement vers la gauche
    /// \param key touche qui va être verifie
    /// \return retourne true si la touche permet un mouvement vers la gauche
    ///
    bool validLeft(int key);
    ///
    /// \brief validRight exprime si la touche permet un mouvement vers la droite
    /// \param key touche qui va être verifie
    /// \return retourne true si la touche permet un mouvement vers la droite
    bool validRight(int key);
    ///
    /// \brief validJump exprime si la touche permet un saut
    /// \param key touche qui va être verifie
    /// \return retourne true si la touche permet un saut
    bool validJump(int key);
    ///
    /// \brief setItsLeft1 permet de definir la touche (parametrable) de mouvement vers la gauche
    /// \param value valeur qui va être attribue a la touche parametrable gauche
    ///
    void setItsLeft1(int value);
    ///
    /// \brief setItsRight1 permet de definir la touche (parametrable) de mouvement vers la droite
    /// \param value valeur qui va être attribue a la touche parametrable droite
    ///
    void setItsRight1(int value);
    ///
    /// \brief setItsJump1 permet de definir la touche (parametrable) de saut
    /// \param value valeur qui va etre attribue a la touche parametrable saut
    ///
    void setItsJump1(int value);
    ///
    /// \brief setItsTimer permet de definir la valeur de itsTimer faisant reference au score du joueur
    /// \param value Chaine de caractere qui va etre attribue a itsTimer
    ///
    void setItsTimer(const QString &value);
    ///
    /// \brief getItsTimer Permet d'obtenir itsTimer
    /// \return Retourne ItsTimer
    ///
    QString getItsTimer() const;
    bool getItsTutorial() const;
    void setItsTutorial(bool value);
};

#endif // SETTINGS_H
