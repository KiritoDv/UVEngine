#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

class IndexBuffer {
    private:
        unsigned int dataId;
        unsigned int indexCount;
    public:
        IndexBuffer(const unsigned int* data, unsigned int indexCount);
        ~IndexBuffer();

        void bind() const;
        void unbind() const;
        inline unsigned int getIndexCount(){ return indexCount; }
};

#endif
