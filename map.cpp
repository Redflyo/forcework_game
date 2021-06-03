#include "map.h"
#include <fstream>
#include "forcework.h"
Map::Map()
{

}

void Map::loadMap(std::string mapFile)
{
    this->itsMapFile = mapFile;
    ifstream stream(mapFile);
    stream.close();
}
