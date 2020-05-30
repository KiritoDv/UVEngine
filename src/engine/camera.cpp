#include "engine/display.h"
#include "engine/camera.h"
#include "SDL2/SDL.h"

void Camera::setupCamera(SDL_Window* win) {

}

void Camera::bindCamera(){

}

void Camera::unbindCamera(){

}

int Camera::getWidth() {
    return engine->window.width;
}

int Camera::getHeight() {
    return engine->window.height;
}
