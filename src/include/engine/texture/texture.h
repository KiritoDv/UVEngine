#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class SDL_Texture;
class SDL_Renderer;

class Texture {
    public:
        Texture(){}
        Texture(SDL_Renderer * renderer, std::string path);
        Texture(SDL_Renderer * renderer, SDL_Texture * texture);
        Texture(SDL_Renderer * renderer);
        ~Texture();
        int width;
        int height;
        SDL_Texture * texture;
};


#endif
