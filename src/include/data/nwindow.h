#ifndef DATA_NWINDOW
#define DATA_NWINDOW

#include <GLFW/glfw3.h>
#include "nmouse.h"

struct NWindow {
    GLFWwindow * window;
    float width;
    float height;
    char* title;
};

#endif
