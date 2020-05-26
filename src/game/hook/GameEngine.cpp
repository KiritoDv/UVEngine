#include "game/hook/GameEngine.h"

#include <engine/display.h>
#include <engine/util/GFXUtil.h>
#include <engine/camera.h>
#include <game/tile/manager.h>

TileManager * tileManager;

void GameEngine::create() {
    tileManager = new TileManager();
    tileManager->loadMap("E:/GDev/C++/IsoRPG-DO/src/assets/maps/Test.json");
    tileManager->engine = this;
}

float camSpeed = 350;

void GameEngine::update() {
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_W) == GLFW_PRESS){
        game->camera->pos -= vec2(0, camSpeed * game->graphics.deltaTime);
    }
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_S) == GLFW_PRESS){
        game->camera->pos += vec2(0, camSpeed * game->graphics.deltaTime);
    }
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_A) == GLFW_PRESS){
        game->camera->pos -= vec2(camSpeed * game->graphics.deltaTime,0);
    }
    if(glfwGetKey(game->window.glwindow, GLFW_KEY_D) == GLFW_PRESS){
        game->camera->pos += vec2( camSpeed * game->graphics.deltaTime,0);
    }

    int mapSizeX = tileManager->_tileMap->_mapSize.width * tileManager->_tileMap->_tileSize.width;
    int mapSizeY = tileManager->_tileMap->_mapSize.height * tileManager->_tileMap->_tileSize.height;

    if(game->camera->pos.x < 0)
        game->camera->pos = {0, game->camera->pos.y};
    if(game->camera->pos.y < 0)
        game->camera->pos = {game->camera->pos.x, 0};

}

void GameEngine::draw() {
    game->camera->zoom = {2, 2};
    game->camera->bindCamera();
    tileManager->renderMap();
    game->camera->unbindCamera();
}

void GameEngine::dispose() {

}