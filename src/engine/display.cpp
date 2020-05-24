#include "gl/glew.h"

#include "GLFW/glfw3.h"
#include "engine/display.h"
#include "engine/render.h"
#include "engine/camera.h"
#include <iostream>

Display::Display(int width, int height, char *windowTitle) {
    window.width = width;
    window.height = height;
    window.title = windowTitle;
}

void Display::createDisplay(int width, int height, char* title){

    auto tmp = new Display(width, height, title);
    auto render = new Render(tmp);
    tmp->camera = new Camera();

    if(!glfwInit()){
        std::cout << "Failed to start GLFW" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    tmp->window.glwindow = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwSetWindowTitle(tmp->window.glwindow, tmp->window.title);

    if(!tmp->window.glwindow){
        std::cout << "Failed to create window" << std::endl;
        glfwDestroyWindow(tmp->window.glwindow);
        return;
    }

    glfwSetWindowUserPointer(tmp->window.glwindow, tmp);
    glfwMakeContextCurrent(tmp->window.glwindow);

    if (glewInit()){
        std::cout << "Failed to start GLEW" << std::endl;
        glfwDestroyWindow(tmp->window.glwindow);
        return;
    }

    glfwSwapInterval(0);

    float time = 0;
    float oldTime = 0;

    render->create();

    tmp->updateWindowSize(width, height);
    glfwSetFramebufferSizeCallback(tmp->window.glwindow, WindowResizeCallback);
    glfwSetCursorEnterCallback(tmp->window.glwindow, MouseEnterCallback);
    glfwSetScrollCallback(tmp->window.glwindow, ScrollCallback);
    tmp->camera->setupCamera(tmp->window.glwindow);

    while(!glfwWindowShouldClose(tmp->window.glwindow)){

        render->update();

        double xMPos, yMPos;
        glfwGetCursorPos(tmp->window.glwindow, &xMPos, &yMPos);

        time = glfwGetTime();
        tmp->graphics.deltaTime = ( time - oldTime );
        oldTime = time;

        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix();
        render->draw();
        glPopMatrix();

        glfwSwapBuffers(tmp->window.glwindow);
        glfwPollEvents();
    }

    render->dispose();
    glfwDestroyWindow(tmp->window.glwindow);
    delete tmp->camera;
    delete tmp;
}

void Display::updateWindowSize(int w, int h){
    window.width = w;
    window.height = h;
    camera->setupCamera(window.glwindow);
}
