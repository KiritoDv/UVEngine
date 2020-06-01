#ifndef ANIMATION_H
#define ANIMATION_H

#include "engine/util/EngineUtil.h"
#include <engine/util/umath.h>
#include <string>
#include <map>
#include <game/data/pos.h>

struct AnimationFrame {
    long delay = 0;
    Pos frame;
};

struct AnimationData {
    std::vector<AnimationFrame> frames;
    bool pingPong = false;
};

struct Animation {
    int animationIndex = 0;
    std::string currentAnimation = "";
    long time = EngineUtil::getTime();
    long initTime = time;

    std::map<std::string, AnimationData> animations;

    Pos tickTexture(Pos baseUv){
        if(!animations.empty() && !currentAnimation.empty()){
            AnimationData tmpData = animations[currentAnimation];

            AnimationFrame currentFrame = tmpData.frames[animationIndex];

            if((initTime + currentFrame.delay) - EngineUtil::getTime() <= 0){
                animationIndex = tmpData.pingPong ? MathUtil::PingPong((EngineUtil::getTime() - time) / 1000.0 * currentFrame.delay, tmpData.frames.size() - 1) : (animationIndex < tmpData.frames.size() - 1 ? animationIndex + 1 : 0);
                initTime = EngineUtil::getTime();
            }
            return currentFrame.frame;
        }
        return baseUv;
    }
};

#endif
