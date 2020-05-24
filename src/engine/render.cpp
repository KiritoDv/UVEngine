#include <iostream>
#include "engine/texture/texture.h"
#include "engine/render.h"
#include "util/umath.h"

#include "glm/glm.hpp"
#include "util/GFXUtil.h"
#include "engine/display.h"
#include "engine/camera.h"

Texture * texture;

void Render::create() {
    texture = new Texture("assets/tiles/Tree.png");
}

void Render::update() {

}

void Render::draw() {
    texture->bindTexture();
    GFXUtil::drawTexture(0, 0, 0, 0, texture->width, texture->height, texture->width, texture->height);
}

void Render::dispose() {
    delete texture;
}