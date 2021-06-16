#ifndef MAP_H
#define MAP_H
#include "string"

#include "block.h"
#include <vector>
#include "ia.h"
#include "player.h"
using namespace std;
class Map
{
private:



    bool replace(std::string& str, const std::string& from, const std::string& to) ;

    ///
    /// \brief split divise une chaine de caract√®re
    /// \param s string √  diviser
    /// \param delimeter le string qui fixe les lignes de d√©coupage
    /// \return le vecteur contenant les diff√©rents morceaux
    ///
    vector<string> split(string s,string delimeter);
    ///
    /// \brief itsMapFile variable to know which map was load
    ///
    std::string itsMapFile;
    std::vector<Block> itsBlocks;
    void addBlock(Block & block);
    int itsWidthMap,itsHeightMap;

public:
    ///
    /// \brief Map constructeur de la carte
    ///
    Map();

    /// \brief ~Map destructeur de la carte
    ~Map();

    ///
    /// \brief loadMap charge le fichier correspond au niveau dans la memoire
    /// \param mapFile chemin d'acces vers le niveau a charger
    ///
    vector<Personnage*> loadMap(std::string mapFile);
    ///
    /// \brief getItsBlocks getter de itsBlocks
    /// \return retourne les blocks de la carte chargÈ
    ///
    std::vector<Block> & getItsBlocks();
    ///
    /// \brief getItsWidthMap getter itsWidthMap soit la largeur de la carte
    /// \return retourne la largeur de la carte en block
    ///
    int getItsWidthMap() const;
    ///
    /// \brief getItsHeightMap getter itsHeightMap soit la hauteur de la carte
    /// \return retourne la hauteur de la carte en block
    ///
    int getItsHeightMap() const;
};

#endif // MAP_H
