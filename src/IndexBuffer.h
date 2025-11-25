#pragma once

#include "Buffer.h"

class IndexBuffer : public Buffer {
    public:
        using Buffer::Buffer;

        void bind() const;
        static void unbind();

        size_t getCount() const;

        template<typename T, size_t N>
        void setData(const T (&data)[N], GLenum usage) {
            count = N;
            Buffer::setData(GL_ELEMENT_ARRAY_BUFFER, data, usage);
        }

        template<typename T>
        void setData(const std::vector<T>& data, GLenum usage) {
            count = data.size();
            Buffer::setData(GL_ELEMENT_ARRAY_BUFFER, data, usage);
        }
    private:
        size_t count;
};