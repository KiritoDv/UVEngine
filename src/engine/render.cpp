#include "engine/texture/texture.h"
#include "engine/render.h"
#include "util/GFXUtil.h"
#include "util/umath.h"

#include <future>

Texture * testTexture;

/*
    unsigned int fbo;
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    //glViewport(0, 0, 800, 600);
    glViewport(0, 0, 800, 600);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, 0.0, 1.0);
    glEnable(GL_TEXTURE_2D);

    glClearColor(0.7, 0.3, 0.3, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    GFXUtil::drawRect(0, 0, 20, 20, {255, 100, 255, 255});
 */

std::vector<std::future<void>> textures;

void Render::create() {

    for(int a = 0; a < 600; a++){
        textures.push_back(std::async(std::launch::async, []{
            testTexture = new Texture("F:\\Pics\\79372456_2508036846106949_7921174829296779264_n.png");
        }));
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

float posX = 0;
float posY = 0;
bool firstFrameLoaded = false;

void Render::draw(Display* d, float deltaTime) {
    //glColor4f(1, 1, 1, 1);
    //d->camera->pos = glm::vec3(camX -= 0.1, 0, 0);
    //d->camera->setupCamera(d->window.window);
    //GFXUtil::drawRect(d->window.mouseInput.x - 10, d->window.mouseInput.y - 10, 20, 20, 0);
    // float a = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    //glTranslatef(d->window.mouseInput.x - (testTexture->width / 2), d->window.mouseInput.y - (testTexture->height / 2), 0);

    testTexture->bindTexture();

    posX = MathUtil::SmoothStep(posX, d->input.mouse.x - (testTexture->width / 2),  10 * deltaTime);
    posY = MathUtil::SmoothStep(posY, d->input.mouse.y - (testTexture->height / 2), 10 * deltaTime);

    glm::vec ab = glm::vec3(1, 1, 1);

    //GFXUtil::drawRect(d->input.mouse.x - 10, d->input.mouse.y - 10, 20, 20, {255, 100, 255, 255});

    GFXUtil::drawTexture(posX, posY, 0, 0, testTexture->width, testTexture->height, testTexture->width, testTexture->height);

}