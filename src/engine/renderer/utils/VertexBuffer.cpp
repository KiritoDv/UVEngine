#include "engine/renderer/utils/VertexBuffer.h"

#include "engine/renderer/BaseRenderer.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
    glGenBuffers(1, &dataId);
    glBindBuffer(GL_ARRAY_BUFFER, dataId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &dataId);
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, dataId);
}

void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}