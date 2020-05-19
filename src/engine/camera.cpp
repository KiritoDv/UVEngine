#include <engine/display.h>
#include "engine/camera.h"

void Camera::setupCamera(GLFWwindow* win) {
    Display *display = static_cast<Display*>(glfwGetWindowUserPointer(win));
    int cW = pos.x + display->window.width;
    int cH = pos.y + display->window.height;
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, display->window.width, display->window.height);
    glLoadIdentity();
    glOrtho(pos.x, cW, cH, pos.y, 0.0, 1.0);
}

void Camera::updateCamera(){
}
