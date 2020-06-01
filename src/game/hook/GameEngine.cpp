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

}

void GameEngine::draw() {
    game->camera->zoom = {2, 2};
    game->camera->bindCamera();
    tileManager->renderMap();
    game->camera->unbindCamera();
}

void GameEngine::dispose() {

}