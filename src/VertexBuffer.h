#pragma once

#include "Buffer.h"

#include <vector>
#include <cstddef>

#include <glad/glad.h>

class VertexBuffer : public Buffer {
    public:
        void bind() const;
        static void unbind();

        template<typename T, size_t N>
        static void setData(const T (&data)[N], GLenum usage) {
            Buffer::setData(GL_ARRAY_BUFFER, data, usage);
        }

        template<typename T>
        static void setData(const std::vector<T>& data, GLenum usage) {
            Buffer::setData(GL_ARRAY_BUFFER, data, usage);
        }
};