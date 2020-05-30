#include"engine/display.h"
#include "engine/render.h"
#include "engine/camera.h"
#include <iostream>
#include "SDL2/SDL_image.h"

Display::Display(int width, int height, char *windowTitle) {
    window.width = width;
    window.height = height;
    window.title = windowTitle;
}

void Display::createDisplay(int width, int height, char* title, Render* render){

    auto tmp = new Display(width, height, title);
    render->game = tmp;
    tmp->camera = new Camera();

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        IMG_Init(IMG_INIT_PNG);
        std::cout << "Failed to init SDL" << std::endl;
        SDL_DestroyWindow(tmp->window.sdlwindow);
    }

    tmp->window.sdlwindow = SDL_CreateWindow(tmp->window.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

    if(!tmp->window.sdlwindow){
        std::cout << "Failed to create window" << std::endl;
        SDL_DestroyWindow(tmp->window.sdlwindow);
        SDL_Quit();
        return;
    }

    render->sdlRenderer = SDL_CreateRenderer(tmp->window.sdlwindow, -1, SDL_RENDERER_ACCELERATED);

    float time = 0;
    float oldTime = 0;

    render->create();

    //tmp->updateWindowSize(width, height);

    //tmp->camera->setupCamera(tmp->window.sdlwindow);
    SDL_Event e;
    while(tmp->window.keepOpen){

        while(SDL_PollEvent(&e) != 0){
            switch (e.type) {
                case SDL_QUIT: {
                    tmp->window.keepOpen = false;
                    break;
                }
                case SDL_WINDOWEVENT_SIZE_CHANGED: {
                    tmp->updateWindowSize(e.window.data1, e.window.data2);
                    break;
                }
                case SDL_MOUSEWHEEL_NORMAL: {
                    tmp->input.scroll.x = e.window.data1;
                    break;
                }
            }
        }

        SDL_SetRenderDrawColor(render->sdlRenderer, 0, 0, 0, 1);
        SDL_RenderClear(render->sdlRenderer);

        double xMPos, yMPos;

        tmp->graphics.deltaTime = ( time - oldTime );
        oldTime = time;

        render->draw();
        SDL_RenderPresent(render->sdlRenderer);
        SDL_Delay(0);
    }

    render->dispose();
    SDL_DestroyWindow(tmp->window.sdlwindow);
    SDL_Quit();
    delete tmp->camera;
    delete tmp;
}

void Display::updateWindowSize(int w, int h){
    window.width = w;
    window.height = h;
    // camera->setupCamera(window.glwindow);
}
