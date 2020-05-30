#ifndef GFXUTIL_H
#define GFXUTIL_H

#include "engine/data/ncolor.h"

class Render;
class Texture;
class SDL_Texture;

class GFXUtil {
    private:
        Render * renderer;
    public:
        GFXUtil(Render * render){ this->renderer = render; }
        void GFXUtil::drawRect(float x, float y, float w, float h, Color c);
        void drawTexture(Texture * texture, int x, int y, int width, int height);
        void drawUVTexture(Texture * texture, int x, int y, float u, float v, int width, int height, float textureWidth, float textureHeight);

        void drawSDLTexture(SDL_Texture * texture, int x, int y, int width, int height);
        void drawSDLUVTexture(SDL_Texture * texture, int x, int y, float u, float v, int width, int height, float textureWidth, float textureHeight);
};

#endif
