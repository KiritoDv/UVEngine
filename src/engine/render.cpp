#include "engine/render.h"

#include "glm/glm.hpp"
#include "engine/display.h"
#include "engine/camera.h"
#include "engine/util/GFXUtil.h";

void Render::create() {

}

void Render::update() {

}

void Render::draw() {
    glBegin(GL_QUADS);
    GFXUtil::drawRect(0, 0, game->camera->getWidth(), game->camera->getHeight(), {255, 100, 100});
    glEnd();
}

void Render::dispose() {

}