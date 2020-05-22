#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include "engine/camera.h"
#include <data/nwindow.h>
#include <data/ninput.h>
#include <data/ngraphics.h>

class Display {
    private:
        Display(int width, int height, char* windowTitle);
        inline static auto WindowResizeCallback(GLFWwindow *win, int w, int h) -> void {
            Display *display = static_cast<Display*>(glfwGetWindowUserPointer(win));
            display->updateWindowSize(w, h);
        }
        inline static auto MouseEnterCallback(GLFWwindow * win, int entered) -> void {
            Display *display = static_cast<Display*>(glfwGetWindowUserPointer(win));
            display->input.mouse.inWindow = (entered != 0);
        }
        inline static auto ScrollCallback(GLFWwindow* win, double xScroll, double yScroll) -> void {
            Display *display = static_cast<Display*>(glfwGetWindowUserPointer(win));
            display->input.scroll.x = xScroll;
            display->input.scroll.y = yScroll;
        }
    public:
        Camera * camera;
        NWindow window;
        NInput input;
        NGraphics graphics;
        static void createDisplay(int width, int height, char * title);
        void updateWindowSize(int w, int h);
};


#endif
