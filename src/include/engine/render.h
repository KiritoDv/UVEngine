#ifndef RENDER_H
#define RENDER_H

#include "engine/display.h"

class Render {
    public:
        Render(){}
        void create();
        void draw(Display* display, float deltaTime);
};

#endif
