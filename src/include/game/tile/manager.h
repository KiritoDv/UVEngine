#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include <map>
#include <string>
#include "game/data/tile.h"
#include "game/tile/map.h"

using namespace std;
class Texture;
class Render;
class SDL_Texture;

struct BakedTexture {
    Tile * tile;
    SDL_Texture * bake;
};

class TileManager {
    private:
        map<string, Texture * > _texturePool;
        map<string, Tile * > _tilePool;
        Texture * bakedMap;
        void registerTile(string key, Tile* tile);
    public:
        Map * _tileMap;
        TileManager() = default;
        void loadMap(string path);
        void updateMap();
        void renderMap();
        void bakeTextures();
        inline void disposeMap(){
            _tileMap->_pool.clear();
            _texturePool.clear();
            _tilePool.clear();
            delete _tileMap;
        }
        Render * engine;
};


#endif
