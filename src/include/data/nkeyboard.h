#ifndef DATA_NKEYBOARD
#define DATA_NKEYBOARD

#include "GLFW/glfw3.h"

struct Keyboard {

    bool isKeyPressed(int key){
        return glfwGetKeyScancode(key) == GLFW_PRESS;
    }

};

#endif