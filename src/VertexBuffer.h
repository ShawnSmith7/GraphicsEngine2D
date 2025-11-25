#pragma once

#include "Buffer.h"

class VertexBuffer : public Buffer {
    public:
        using Buffer::Buffer;

        void bind() const;
        static void unbind();

        template<typename T, size_t N>
        static void setData(const T (&data)[N], GLenum usage) {
            Buffer::setData(GL_ARRAY_BUFFER, data, usage);
        }
};