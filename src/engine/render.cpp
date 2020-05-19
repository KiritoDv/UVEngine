#include "render.h"
#include "GFXUtil.h"

void Render::create() {

}

void Render::draw(Display* d, float deltaTime) {
    d->camera->pos = glm::vec3(50, 50, 0);
    d->camera->setupCamera(d->window.window);

     GFXUtil::drawRect(d->window.mouseInput.x - 10, d->window.mouseInput.y - 10, 20, 20, 0);
}