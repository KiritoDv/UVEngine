#include <engine/texture/texture.h>
#include "engine/render.h"
#include "util/GFXUtil.h"
#include <chrono>

Texture * testTexture;

Render::Render() {

}

void Render::create() {
    testTexture = new Texture("F:\\Pics\\79372456_2508036846106949_7921174829296779264_n.png");
}

void Render::draw(Display* d, float deltaTime) {
    //d->camera->pos = glm::vec3(50, 50, 0);
    d->camera->setupCamera(d->window.window);
    //GFXUtil::drawRect(d->window.mouseInput.x - 10, d->window.mouseInput.y - 10, 20, 20, 0);
    // float a = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    testTexture->bindTexture();
    glTranslatef(d->window.mouseInput.x - (testTexture->width / 2), d->window.mouseInput.y - (testTexture->height / 2), 0);
    GFXUtil::drawTexture(0, 0, 0, 0, testTexture->width, testTexture->height, testTexture->width, testTexture->height);

}