#ifndef CAMERA_H
#define CAMERA_H

#include "glm/vec3.hpp";
#include "GLFW/glfw3.h"

class Camera {
    public:
        Camera(){}
        glm::vec3 pos = glm::vec3(0, 0,0);
        void setupCamera(GLFWwindow * d);
        void bindCamera();
};


#endif
