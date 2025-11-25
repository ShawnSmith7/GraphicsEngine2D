#pragma once

#include <glad/glad.h>

class Buffer {
    public:
        Buffer();
        ~Buffer();

        void bind(GLenum target) const;
        static void unbind(GLenum target);

        template<typename T, size_t N>
        static void setData(GLenum target, const T (&data)[N], GLenum usage) {
            glBufferData(target, N * sizeof(T), data, usage);
        }
    protected:
        unsigned int ID;
};