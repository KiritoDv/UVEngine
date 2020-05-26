#ifndef MAP_H
#define MAP_H

#include <vector>
#include "game/data/tile.h"

using namespace std;

class Map {
    public:
        Map(){}
        vector<Tile * > _pool;
        Size _mapSize;
        Size _tileSize;
};

#endif
