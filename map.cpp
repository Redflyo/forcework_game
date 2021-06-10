#include "map.h"
#include <fstream>
#include <sstream>


void Map::addBlock(Block & block)
{
    itsBlocks.push_back(block);
}

int Map::getItsHeightMap() const
{
    return itsHeightMap;
}

int Map::getItsWidthMap() const
{
    return itsWidthMap;
}



Map::Map()
{

}


Map::~Map()
{

}



vector<string> Map::split(string s,string delimeter)
{
    vector<string> result;
    int start = 0;
    int end = s.find(delimeter);
    while (end != -1) {
        result.push_back(s.substr(start, end - start));
        start = end + delimeter.size();
        end = s.find(delimeter, start);
    }
    result.push_back(s.substr(start, end - start));
    return result;
}

std::vector<Block> Map::getItsBlocks() const
{
    return itsBlocks;
}
bool Map::replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}


vector<Personnage*> Map::loadMap(std::string mapFile)
{
    itsWidthMap =0;
    vector<Personnage*> result;
    Block flag(1);
    this->itsMapFile = mapFile;
    ifstream stream(mapFile);
    int y = -1;
    string line;
    while(!stream.eof())
    {
        y++;
        getline(stream,line);

        if(line[0] == '(' )
        {
            // round of enemies
            while(replace(line," ", ""));
            while(replace(line,"(", ""));
            while(replace(line,")", ""));
            vector<string> rounds = split(line,",");
            for(int i = 0;i < (int)rounds.size()-1;i++)
            {
                vector<string>round = split(rounds[i],":");
                if(round.size()== 2)
                {
                    int x1 = stoi(round[0]);
                    int y1 = stoi(round[1]);
                    IA * ia = new IA(x1,x1,y1);
                    result.push_back(ia);
                }
                else if(round.size())
                {
                    int x1 = stoi(round[0]);
                    int x2 = stoi(round[1]);
                    int y1 = stoi(round[2]);
                    IA * ia = new IA(x1,x2,y1);
                    result.push_back(ia);
                }
            }

        }
        else
        {
            // map
            char c;



            for(int i = 0; i<(int)line.size();i++,c = line[i])
            {

                // récupère le plus grand x pour définir la longueur de la carte
                itsWidthMap = itsWidthMap < i ? i : itsWidthMap;


                    if(line[i] >= '2' && line[i] <= '4')
                    {
                        Block block(line[i]- '0',i,y);
                        itsBlocks.push_back(block);
                    }
                    else
                    {
                        if(line[i] == '*')
                        {
                            Player * player = new Player();
                            player->setItsBlockX(i);
                            player->setItsBlockY(y-1);
                            result.push_back(player);
                        }
                        if(line[i] == '.'|| line[i] == '*')
                        {
                            Block block(0,i,y);
                            itsBlocks.push_back(block);
                        }
                        if(line[i] == '1')
                        {
                            flag.setItsBlockX(i);
                            flag.setItsBlockY(y);
                        }

                    }






            }
        }

    }
    itsHeightMap = y;

    stream.close();
    itsBlocks.push_back(flag);
    return result;
}
