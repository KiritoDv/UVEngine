#ifndef DATA_NWINDOW
#define DATA_NWINDOW

#include <GLFW/glfw3.h>
#include "engine/data/nmouse.h"

struct NWindow {
    GLFWwindow * glwindow;
    float width;
    float height;
    char* title;
};

#endif
