#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
    public:
        Texture(){}
        Texture(const char* path);
        void bindTexture();
        int width;
        int height;
    private:
        unsigned int textureId;
};


#endif
