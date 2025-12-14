#pragma once

#include <glad/glad.h>

#include <vector>
#include <ostream>

class Buffer {
    public:
        Buffer();
        ~Buffer();

        void gen();

        void bind(GLenum target) const;
        static void unbind(GLenum target);

        template<typename T, size_t N>
        static void setData(GLenum target, const T (&data)[N], GLenum usage) {
            glBufferData(target, N * sizeof(T), data, usage);
        }

        template<typename T>
        static void setData(GLenum target, const std::vector<T>& data, GLenum usage) {
            glBufferData(target, data.size() * sizeof(T), data.data(), usage);
        }
    protected:
        unsigned int ID;

        friend std::ostream& operator<<(std::ostream& os, const Buffer& buffer);
};

std::ostream& operator<<(std::ostream& os, const Buffer& buffer);