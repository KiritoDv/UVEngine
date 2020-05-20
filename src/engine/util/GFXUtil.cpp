#include <data/ncolor.h>
#include "util/GFXUtil.h"
#include "gl/glew.h";

void GFXUtil::drawRect(float x, float y, float w, float h, Color c) {
    glBegin(GL_QUADS);
        glColor4d(c.red / 255.0f, c.green / 255.0f, c.blue / 255.0f, c.alpha / 255.0f);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
        glEnd();
    glFlush();
}



void GFXUtil::drawTexture(int x, int y, float u, float v, int width, int height, float textureWidth, float textureHeight) {
    float f = 1.0F / textureWidth;
    float f1 = 1.0F / textureHeight;
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);
    glVertex2f(x, y + height);
    glTexCoord2f(1, 1);
    glVertex2f(x + width, y + height);
    glTexCoord2f(1, 0);
    glVertex2f(x + width, y);
    glTexCoord2f(0, 0);
    glVertex2f(x, y);
    glEnd();
}