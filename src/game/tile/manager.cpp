#include "game/tile/manager.h"
#include <engine/texture/texture.h>
#include <fstream>
#include <iostream>
#include "game/hook/GameEngine.h"
#include "engine/display.h"
#include "engine/camera.h"
#include <future>

using namespace nlohmann;

void TileManager::registerTile(string key, Tile *tile) {
    for(auto &tex : tile->data.textures){
        if(_texturePool.find(tex) == _texturePool.end()) {
            _texturePool[tex] = new Texture(tex);
        }
    }
    _tilePool[key] = tile;
}

void TileManager::loadMap(string path) {
    _tileMap = new Map();

    std::cout << "Trying to load: " << path << std::endl;

    std::ifstream rawMap(path);
    json map = json::parse(rawMap);

    if(rawMap.fail()){
        std::cout << "Failed to load map" << std::endl;
    }

    std::cout << "Map Loaded: " << map << std::endl;

    std::cout << map["textures"] << std::endl;

    _tileMap->_mapSize = {map["properties"]["size"]["map"][0], map["properties"]["size"]["map"][1]};
    _tileMap->_tileSize = {map["properties"]["size"]["tile"][0], map["properties"]["size"]["tile"][1]};

    for(auto &tex : map["textures"]){
        Tile * tmp = new Tile();
        tmp->data.size = {tex["properties"]["size"][0], tex["properties"]["size"][1]};
        tmp->data.uv = {tex["properties"]["uv"][0], tex["properties"]["uv"][1]};
        tmp->data.textures = {tex["path"]};
        if(tex["properties"].find("animation") != tex["properties"].end() && !tex["properties"]["animation"].is_null()){
            tmp->data.animation.currentAnimation = tex["properties"]["animation"]["current"];

            for(auto &animation : tex["properties"]["animation"]["list"]){
                vector<AnimationFrame> tmpList;

                for(auto &frame : animation["frames"]){
                    tmpList.push_back({frame["delay"], {frame["frame"][0], frame["frame"][1]}});
                }

                tmp->data.animation.animations[animation["id"]] = {tmpList, animation["pingPong"]};
            }
        }
        registerTile(tex["id"], tmp);
    }

    for(auto &tile : map["tiles"]){
        if(_tilePool.find(tile["id"]) != _tilePool.end()){
            Tile * tmp = _tilePool[tile["id"]]->clone();
            tmp->position = {tile["pos"][0], tile["pos"][1]};
            tmp->position.z = tile["pos"][2];
            _tileMap->_pool.push_back(tmp);
        }
    }

    if(map["properties"].find("defaultTile") != map["properties"].end() && !map["properties"]["defaultTile"].is_null()){

        for(int x = 0; x < _tileMap->_mapSize.width; x++){
            for(int y = 0; y < _tileMap->_mapSize.height; y++){

                auto it = find_if(_tileMap->_pool.begin(), _tileMap->_pool.end(), [x, y, this](Tile * a){
                    return a->position.x == x && a->position.y == y && a->position.z == 0;
                });

                if(it == _tileMap->_pool.end()){
                    Tile * tmp = _tilePool[map["properties"]["defaultTile"]["id"]]->clone();
                    tmp->position = {x, y};
                    _tileMap->_pool.push_back(tmp);
                }
            }
        }
    }

    sort(_tileMap->_pool.begin(), _tileMap->_pool.end(), [this](Tile * a, Tile * b){
        return a->position.z < b->position.z;
    });
}

void TileManager::updateMap() {

}

void TileManager::renderMap() {
    for(auto &tile : _tileMap->_pool){
        int tX = tile->position.x * _tileMap->_tileSize.width;
        int tY = tile->position.y * _tileMap->_tileSize.height;

        if(!(tile->position.x <= _tileMap->_mapSize.width && tile->position.y <= _tileMap->_mapSize.height && tX >= engine->game->camera->pos.x - tile->data.size.width && tX <= engine->game->camera->pos.x + engine->game->camera->getWidth() && tY >= engine->game->camera->pos.y - tile->data.size.height && tY <= engine->game->camera->pos.y + engine->game->camera->getHeight()))
            continue;

        tile->data.uv = tile->data.animation.tickTexture(tile->data.uv);
        _texturePool[tile->data.textures[0]]->bindTexture();

        //GFXUtil::drawTexture(tX, tY, tile->data.uv.x, tile->data.uv.y, tile->data.size.width, tile->data.size.height, _texturePool[tile->data.textures[0]]->width, _texturePool[tile->data.textures[0]]->height);
    }
}