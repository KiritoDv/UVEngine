#include "engine/display.h"
#include "engine/camera.h"

#include <iostream>

void Camera::setupCamera(GLFWwindow* win) {
    Display *display = static_cast<Display*>(glfwGetWindowUserPointer(win));
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, display->window.width, display->window.height);
    glLoadIdentity();
    glOrtho(0, display->window.width, display->window.height, 0, 0.0, 9999);
}

void Camera::bindCamera(){
    glTranslatef(-pos.x, -pos.y, 0);
}
