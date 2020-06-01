//
// Created by Ruine on 5/26/2020.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "glm/glm.hpp"
#include "engine/util/EngineUtil.h"
#include <string>
#include <game/data/tile.h>
#include <map>
#include <engine/util/umath.h>

using namespace std;
using namespace glm;

struct Player {
    vec3 position = {0, 0, 0};
    string texture;
};


#endif
