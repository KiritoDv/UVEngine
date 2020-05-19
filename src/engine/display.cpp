#include "display.h"
#include "render.h"
#include <iostream>

Display::Display(int width, int height, char *windowTitle) {
    window.width = width;
    window.height = height;
    window.title = windowTitle;
}

Display * Display::createDisplay(int width, int height, char* title){

    Display* tmp = new Display(width, height, title);
    Render render = Render();
    tmp->camera = new Camera();

    if(!glfwInit()){
        std::cout << "Failed to start GLFW" << std::endl;
        return NULL;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    tmp->window.window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwSetWindowTitle(tmp->window.window, tmp->window.title);

    if(!tmp->window.window){
        std::cout << "Failed to create window" << std::endl;
        glfwDestroyWindow(tmp->window.window);
        return NULL;
    }

    glfwSetWindowUserPointer(tmp->window.window, tmp);
    glfwMakeContextCurrent(tmp->window.window);

    if (glewInit()){
        std::cout << "Failed to start GLEW" << std::endl;
        glfwDestroyWindow(tmp->window.window);
        return NULL;
    }

    glfwSwapInterval(0);

    float newTime = 0;
    float oldTime = 0;
    float deltaTime = 0;

    tmp->updateWindowSize(width, height);
    glfwSetFramebufferSizeCallback(tmp->window.window, WindowResizeCallback);

    render.create();

    while(!glfwWindowShouldClose(tmp->window.window)){

        oldTime = newTime;
        newTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

        glClearColor(0.7, 0.3, 0.3, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_TEXTURE_2D);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        double xMPos, yMPos;
        glfwGetCursorPos(tmp->window.window, &xMPos, &yMPos);

        tmp->camera->updateCamera();
        tmp->window.mouseInput.x = xMPos + tmp->camera->pos.x;
        tmp->window.mouseInput.y = yMPos + tmp->camera->pos.y;

        render.draw(tmp, deltaTime);
        deltaTime = newTime - oldTime;

        glDisable(GL_TEXTURE_2D);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glfwSwapBuffers(tmp->window.window);
        glfwPollEvents();
    }

    glfwDestroyWindow(tmp->window.window);

    return tmp;
}

void Display::updateWindowSize(int w, int h){
    window.width = w;
    window.height = h;
    camera->setupCamera(window.window);
}

/*
      * tmp->renderThread = std::thread([keepRunning, tmp, render](){
             while(keepRunning){
                 render.updateGame();
             }
         });
      *
      */

//tmp->renderThread.detach();
//