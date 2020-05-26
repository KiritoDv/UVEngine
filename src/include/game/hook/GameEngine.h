#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "engine/render.h"

class GameEngine : public Render {

    public:
        GameEngine(){}
        void create();
        void update();
        void draw();
        void dispose();
};


#endif
