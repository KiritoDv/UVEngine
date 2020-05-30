#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <engine/util/GFXUtil.h>

class SDL_Renderer;
class Display;

class Render {
    public:
        inline Render(){ this->gfx = new GFXUtil(this); }
        virtual void create();
        virtual void update();
        virtual void draw();
        virtual void dispose();
        Display * game;
        SDL_Renderer * sdlRenderer;
        GFXUtil * gfx;
};

#endif
