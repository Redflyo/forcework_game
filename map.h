#ifndef MAP_H
#define MAP_H
#include "string"
#include "flag.h"
#include "block.h"
#include <vector>
class Map
{
private:
    ///
    /// \brief itsMapFile variable to know which map was load
    ///
    std::string itsMapFile;
    std::vector<Block> blocks;
    Flag flag;

public:

    Map();
    ///
    /// \brief loadMap Load the map in memory
    /// \param mapFile path to get the map
    ///
    void loadMap(std::string mapFile);
};

#endif // MAP_H
