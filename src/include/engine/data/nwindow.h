#ifndef DATA_NWINDOW
#define DATA_NWINDOW

#include "engine/data/nmouse.h"
#include "SDL2/SDL.h"

struct NWindow {
    SDL_Window * sdlwindow;
    float width;
    float height;
    char* title;
    bool keepOpen = true;
};

#endif
