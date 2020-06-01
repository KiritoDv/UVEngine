#ifndef GTILE_H
#define GTILE_H

#include <string>
#include <vector>
#include "gsize.h"
#include "nlohmann/json.hpp"
#include "engine/util/EngineUtil.h"
#include "game/animation/animation.h"

enum TileProperties{
    BREAK,
    MOVE,
    INTERACT,
    SWITCH,
    BLOCK
};

struct TileData{
    std::vector<std::string> textures;
    Size size;
    Pos uv;
    std::vector<TileProperties> properties;
    Animation animation;
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
