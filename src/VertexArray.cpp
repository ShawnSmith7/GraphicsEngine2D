#include "VertexArray.h"

VertexArray::VertexArray() :
    ID(0) {}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &ID);
}

void VertexArray::gen() {
    glGenVertexArrays(1, &ID);
}

void VertexArray::bind() const {
    glBindVertexArray(ID);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}

void VertexArray::enableAttribute(unsigned int index) {
    glEnableVertexAttribArray(index);
}

void VertexArray::setAttributePointer(unsigned int index, int size, GLenum type, bool normalized, size_t stride, size_t offset) {
    glVertexAttribPointer(index, size, type, normalized, stride, (void*)offset);
}