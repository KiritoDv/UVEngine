#include "engine/texture/texture.h"
#include "engine/render.h"
#include "util/umath.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include "glm/glm.hpp"
#include "util/GFXUtil.h"

#include <stdlib.h>
#include <time.h>

#include "data/ncolor.h"

Texture * texture;

std::vector<int> makeRandomNoise(){
    std::vector<int> pn(9);

    for(int i = 0; i < 4; i++){
        //std::cout << rand() % 9 << std::endl;
        pn[rand() % 9] = 1;
    }
    return pn;
}

void Render::create() {
    texture = new Texture("F:\\Pics\\79372456_2508036846106949_7921174829296779264_n.png");
}

void Render::update() {

}

void Render::draw() {
    GFXUtil::drawRect(0, 0, game->window.width, game->window.height, {112, 192, 160});

    glBegin(GL_QUADS);
    GFXUtil::drawRect(0, 0, game->window.width, game->window.height, {112, 192, 160});

    for(int b = 0; b < 500; b++){

        int pX = (rand() % (int)(game->window.width / 9)) * 9;
        int pY = (rand() % (int)(game->window.width / 9)) * 9;

        std::vector<int> pn = makeRandomNoise();
        std::vector<Color> color(2);
        color[0] = {160, 208, 192};
        color[1] = {64, 176, 128};

        int r = rand() % 2;

        for(int id = 0; id < pn.size(); id++){
            if(pn[id] > 0){
                int y = id / 3;
                int x = id <= 3 ? id : id - (3 * y);
                GFXUtil::drawRect(pX + 3 * x, pY + 3 * y, 3, 3, color[r]);
                //std::cout << "X: " << x << " Y: " << y << " VAL: " << pn[id] << std::endl;
            }
        }
    }
    glEnd();
}

void Render::dispose() {
    delete texture;
}