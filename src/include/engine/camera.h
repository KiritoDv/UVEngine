#ifndef CAMERA_H
#define CAMERA_H

#include "glm/vec3.hpp";
#include "glm/gtc/quaternion.hpp"

using namespace glm;

class SDL_Window;
class Display;

class Camera {
    public:
        Camera(){}
        vec2 pos = vec2(0, 0);
        vec2 zoom = vec2(1, 1);
        float rotation = 0;
        void setupCamera(SDL_Window * d);
        void bindCamera();
        void unbindCamera();
        int getWidth();
        int getHeight();
    private:
        Display * engine;
};


#endif
