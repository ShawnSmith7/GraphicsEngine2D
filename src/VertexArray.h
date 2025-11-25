#pragma once

#include <glad/glad.h>

class VertexArray {
    public:
        VertexArray();
        ~VertexArray();

        void bind() const;
        static void unbind();

        static void enableAttribute(unsigned int index);
        static void setAttributePointer(unsigned int index, int size, GLenum type, bool normalized, size_t stride, size_t offset);
    private:
        unsigned int ID;
};