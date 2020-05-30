#include "game/hook/GameEngine.h"

#include <engine/display.h>
#include <engine/camera.h>
#include <game/tile/manager.h>

TileManager * tileManager;

void GameEngine::create() {
    tileManager = new TileManager();
    tileManager->engine = this;
    tileManager->loadMap("E:/GDev/C++/IsoRPG-DO/src/assets/maps/Test.json");
}

float camSpeed = 350;

void GameEngine::update() {

    int mapSizeX = tileManager->_tileMap->_mapSize.width * tileManager->_tileMap->_tileSize.width;
    int mapSizeY = tileManager->_tileMap->_mapSize.height * tileManager->_tileMap->_tileSize.height;


}

void GameEngine::draw() {
    tileManager->renderMap();
}

void GameEngine::dispose() {

}