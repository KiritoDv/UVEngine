#include "gl/glew.h"

#include "engine/display.h"
#include "engine/camera.h"

void Camera::setupCamera(GLFWwindow* win) {
    Display *display = static_cast<Display*>(glfwGetWindowUserPointer(win));
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, display->window.width, display->window.height);
    glLoadIdentity();
    gluOrtho2D(0, display->window.width, display->window.height, 0);
    engine = display;
}

void Camera::bindCamera(){
    glPushMatrix();
    glTranslatef((engine->window.width / 2) * zoom.x, (engine->window.height / 2) * zoom.y, 0);
    glTranslatef(-pos.x * zoom.x, -pos.y * zoom.y, 0);
    glScalef(zoom.x, zoom.y, 1);
    glRotatef(rotation, 0, 0, 1);
    glTranslatef(-(engine->window.width / 2), -(engine->window.height / 2) , 0);
}

void Camera::unbindCamera(){
    glPopMatrix();
}

int Camera::getWidth() {
    return engine->window.width;
}

int Camera::getHeight() {
    return engine->window.height;
}
