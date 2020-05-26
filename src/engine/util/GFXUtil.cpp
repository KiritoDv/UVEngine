#include <engine/data/ncolor.h>
#include "engine/util/GFXUtil.h"
#include "gl/glew.h";

void GFXUtil::drawRect(float x, float y, float w, float h, Color c) {
    glBegin(GL_QUADS);
        glColor4d(c.red / 255.0f, c.green / 255.0f, c.blue / 255.0f, c.alpha / 255.0f);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
    glEnd();
}



void GFXUtil::drawTexture(int x, int y, float u, float v, int width, int height, float textureWidth, float textureHeight) {

    float f = 1.0 / textureWidth;
    float f1 = 1.0 / textureHeight;

    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glTexCoord2f(u * f, (v + (float)height) * f1);
        glVertex2f(x, y + height);
        glTexCoord2f((u + (float)width) * f, (v + (float)height) * f1);
        glVertex2f(x + width, y + height);
        glTexCoord2f((u + (float)width) * f, v * f1);
        glVertex2f(x + width, y);
        glTexCoord2f(u * f, v * f1);
        glVertex2f(x, y);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
}