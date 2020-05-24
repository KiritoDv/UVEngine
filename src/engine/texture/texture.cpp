#include "engine/texture/texture.h"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include <stb_image.h>
#include <iostream>
#include "gl/glew.h";

Texture::Texture(const char * path) {
    glGenTextures(1, &textureId);

    int nrChannels;
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, STBI_rgb_alpha);

    if (data) {
        glBindTexture(GL_TEXTURE_2D, reinterpret_cast<GLuint>(&textureId));

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
        glBindTexture(GL_TEXTURE_2D, 0);
        std::cout << "Loaded texture: " << path << std::endl;
    }else{
        std::cout << "Failed to load texture: " << path << std::endl;
    }
}

void Texture::bindTexture() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, reinterpret_cast<GLuint>(&textureId));
}