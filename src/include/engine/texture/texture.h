#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>;

class Texture {
    public:
        Texture(){}
        Texture(std::string path);
        void bindTexture();
        int width;
        int height;
    private:
        unsigned int textureId;
};


#endif
