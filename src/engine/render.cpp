#include "engine/texture/texture.h"
#include "engine/render.h"
#include "util/umath.h"

#include "glm/glm.hpp"
#include "util/GFXUtil.h"
#include "engine/display.h"
#include "engine/camera.h"

Texture * texture;

void Render::create() {
    texture = new Texture("F:\\Pics\\79372456_2508036846106949_7921174829296779264_n.png");
}

float camSpeed = 1000;

void Render::update() {
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_W) == GLFW_PRESS){
        game->camera->pos += vec2(0, camSpeed * game->graphics.deltaTime);
    }
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_S) == GLFW_PRESS){
        game->camera->pos -= vec2(0, camSpeed * game->graphics.deltaTime);
    }
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_A) == GLFW_PRESS){
        game->camera->pos += vec2(camSpeed * game->graphics.deltaTime,0);
    }
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_D) == GLFW_PRESS){
        game->camera->pos -= vec2( camSpeed * game->graphics.deltaTime,0);
    }

    if(glfwGetKey(game->window.glwindow, GLFW_KEY_UP) == GLFW_PRESS){
        game->camera->zoom += vec2(0, 1 * game->graphics.deltaTime);
    }
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_DOWN) == GLFW_PRESS){
        game->camera->zoom -= vec2(0, 1 * game->graphics.deltaTime);
    }
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_LEFT) == GLFW_PRESS){
        game->camera->zoom += vec2(1 * game->graphics.deltaTime, 0);
    }
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_RIGHT) == GLFW_PRESS){
        game->camera->zoom -= vec2(1 * game->graphics.deltaTime, 0);
    }

    if(glfwGetKey(game->window.glwindow, GLFW_KEY_KP_ADD) == GLFW_PRESS){
        game->camera->rotation += 45 * game->graphics.deltaTime;
    }
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_MINUS) == GLFW_PRESS){
        game->camera->rotation -= 45 * game->graphics.deltaTime;
    }
}

void Render::draw() {
    game->camera->zoom = vec2(2, 2);
    game->camera->bindCamera();

    texture->bindTexture();
    glBegin(GL_QUADS);
    GFXUtil::drawRect(game->camera->getWidth() / 2 - 32, game->camera->getHeight() / 2 - 32, 64, 64, {120, 180, 180});
    glEnd();
    game->camera->unbindCamera();
}

void Render::dispose() {
    delete texture;
}