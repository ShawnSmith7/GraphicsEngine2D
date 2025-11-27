#include "Buffer.h"

Buffer::Buffer() :
    ID(0) {}

Buffer::~Buffer() {
    glDeleteBuffers(1, &ID);
}

void Buffer::gen() {
    glGenBuffers(1, &ID);
}

void Buffer::bind(GLenum target) const {
    glBindBuffer(target, ID);
}

void Buffer::unbind(GLenum target) {
    glBindBuffer(target, 0);
}