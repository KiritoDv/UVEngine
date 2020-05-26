#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include <map>
#include <string>
#include "game/data/tile.h"
#include "game/tile/map.h"

using namespace std;
class Texture;
class Render;

class TileManager {
    private:
        map<string, Texture *> _texturePool;
        map<string, Tile * > _tilePool;
        void registerTile(string key, Tile* tile);
    public:
        int skipXTiles = 0;
        int skipYTiles = 0;
        Map * _tileMap;
        TileManager(){}
        void loadMap(string path);
        void updateMap();
        void renderMap();
        inline void disposeMap(){
            _tileMap->_pool.clear();
            _texturePool.clear();
            _tilePool.clear();
            delete _tileMap;
        }
        Render * engine;
};


#endif
