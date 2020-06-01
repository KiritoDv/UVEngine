#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

class VertexBuffer {
    private:
        unsigned int dataId;
    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;

    virtual ~VertexBuffer();
};

#endif
