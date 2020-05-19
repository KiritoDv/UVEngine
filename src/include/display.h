#ifndef DISPLAY_H
#define DISPLAY_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <gl/freeglut.h>
#include "camera.h"
#include <data/nwindow.h>

class Display {
    private:
        Display(int width, int height, char* windowTitle);
        inline static auto WindowResizeCallback(GLFWwindow *win, int w, int h) -> void {
            Display *display = static_cast<Display*>(glfwGetWindowUserPointer(win));
            display->updateWindowSize(w, h);
        }
    public:
        Camera * camera;
        NWindow window;
        static Display * createDisplay(int width, int height, char * title);
        void updateWindowSize(int w, int h);
};


#endif
