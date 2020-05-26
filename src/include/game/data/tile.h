#ifndef GTILE_H
#define GTILE_H

#include <string>
#include <vector>
#include "gsize.h"
#include "nlohmann/json.hpp"
#include "engine/util/EngineUtil.h"

using namespace std;

enum TileProperties{
    BREAK,
    MOVE,
    INTERACT,
    SWITCH,
    BLOCK
};

struct Pos{
    int x = 0;
    int y = 0;
    int layer = 0;
};

struct TileAnimationFrame{
    long delay = 0;
    Pos frame;
};

struct TileAnimationData{
    vector<TileAnimationFrame> frames;
    bool pingPong = false;
};

struct TileAnimation{
    int animationIndex = 0;
    long time = EngineUtil::getTime();
    long initTime = time;

    string currentAnimation = "";
    map<string, TileAnimationData> animations;

    float getTime(){
        return (EngineUtil::getTime() - time) / 1000.0;
    }
};

struct TileData{
    vector<string> textures;
    Size size;
    Pos uv;
    vector<TileProperties> properties;
    TileAnimation animation;
};

class Tile{
    public:
        TileData data;
        Pos position;
        Tile(){}
        Tile * clone(){
            return new Tile(*this);
        }
        virtual void onEvent(){}
};

#endif
