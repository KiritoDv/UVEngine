#ifndef RENDER_H
#define RENDER_H

#include "engine/display.h"

class Render {
    public:
        Render(){}
        virtual void create();
        virtual void update();
        virtual void draw();
        virtual void dispose();
        Display* game;
};

#endif
