#include "GFXUtil.h"

void GFXUtil::drawRect(float x, float y, float w, float h, int c) {
    glBegin(GL_QUADS);
    glColor4d(1, 1, 1, 1);
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