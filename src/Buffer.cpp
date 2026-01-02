#include "pch.h"
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

std::ostream& operator<<(std::ostream& os, const Buffer& buffer) {
    return os
        << "{ ID = " << buffer.ID << " }";
}