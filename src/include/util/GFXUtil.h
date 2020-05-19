#ifndef GFXUTIL_H
#define GFXUTIL_H

#include "GL/glew.h";

class GFXUtil {
    public:
        static void drawRect(float x, float y, float w, float h, int color);
        static void drawTexture(int x, int y, float u, float v, int width, int height, float textureWidth, float textureHeight);
        static void HSVtoRGB(float& fR, float& fG, float& fB, float& fH, float& fS, float& fV);
};

#endif
