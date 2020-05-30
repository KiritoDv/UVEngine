#include "engine/data/ncolor.h"
#include "SDL2/SDL.h"
#include "engine/util/GFXUtil.h"
#include "engine/render.h"
#include "engine/texture/texture.h"

void GFXUtil::drawRect(float x, float y, float w, float h, Color c) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_SetRenderDrawColor(renderer->sdlRenderer, c.red, c.green, c.blue, c.alpha);
    SDL_RenderFillRect(renderer->sdlRenderer, &rect);
}


void GFXUtil::drawTexture(Texture * texture, int x, int y, int width, int height) {
    GFXUtil::drawSDLTexture(texture->texture, x, y, width, height);
}

void GFXUtil::drawUVTexture(Texture * texture, int x, int y, float u, float v, int width, int height, float textureWidth, float textureHeight) {
    GFXUtil::drawSDLUVTexture(texture->texture, x, y, u, v, width, height, textureWidth, textureHeight);
}

void GFXUtil::drawSDLTexture(SDL_Texture * texture, int x, int y, int width, int height) {

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_RenderCopy(renderer->sdlRenderer, texture, nullptr, &rect);
}

void GFXUtil::drawSDLUVTexture(SDL_Texture * texture, int x, int y, float u, float v, int width, int height, float textureWidth, float textureHeight) {

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_Rect uv;
    uv.x = u;
    uv.y = v;
    uv.w = width;
    uv.h = height;

    SDL_RenderCopy(renderer->sdlRenderer, texture, &uv, &rect);
}