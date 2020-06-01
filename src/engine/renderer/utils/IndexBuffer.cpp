#include "engine/renderer/utils/IndexBuffer.h"

#include "engine/renderer/BaseRenderer.h"

IndexBuffer::IndexBuffer(const int unsigned * data, unsigned int indexCount) : indexCount(indexCount) {
    glGenBuffers(1, &dataId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, dataId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &dataId);
}

void IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, dataId);
}

void IndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}