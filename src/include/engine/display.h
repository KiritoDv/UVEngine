#ifndef DISPLAY_H
#define DISPLAY_H

#include <engine/data/nwindow.h>
#include <engine/data/ninput.h>
#include <engine/data/ngraphics.h>

class Camera;
class Render;

class Display {
    private:
        Display(int width, int height, char* windowTitle);
    public:
        Camera * camera;
        NWindow window;
        NInput input;
        NGraphics graphics;
        static void createDisplay(int width, int height, char * title, Render* render);
        void updateWindowSize(int w, int h);
};


#endif
