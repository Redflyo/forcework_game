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
    /// \brief split divise une chaine de caractère
    /// \param s string �  diviser
    /// \param delimeter le string qui fixe les lignes de découpage
    /// \return le vecteur contenant les différents morceaux
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

    Map();
    ~Map();
    ///
    /// \brief loadMap Load the map in memory
    /// \param mapFile path to get the map
    ///
    vector<Personnage*> loadMap(std::string mapFile);
    std::vector<Block> getItsBlocks() const;
    int getItsWidthMap() const;
    int getItsHeightMap() const;
};

#endif // MAP_H
