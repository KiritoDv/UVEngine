#include "engine/texture/texture.h"
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

Texture::Texture(SDL_Renderer * renderer, std::string path) {

    this->texture = IMG_LoadTexture(renderer, path.c_str());

    if (this->texture != nullptr) {
        SDL_QueryTexture(this->texture, nullptr, nullptr, &this->width, &this->height);
        std::cout << "Loaded texture: " << path << std::endl;
        std::cout << "Data - W: " << this->width << " H: " << this->height << std::endl;
    }else{
        std::cout << "Failed to load texture: " << path << std::endl;
    }
}

Texture::Texture(SDL_Renderer * renderer, SDL_Texture * texture) {
    this->texture = texture;
    SDL_QueryTexture(this->texture, nullptr, nullptr, &this->width, &this->height);
}

Texture::Texture(SDL_Renderer * renderer) {

}

Texture::~Texture() {
    SDL_DestroyTexture(this->texture);
}