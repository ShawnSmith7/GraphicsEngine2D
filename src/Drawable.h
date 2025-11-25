#pragma once

#include <span>

#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Drawable {
    public:
        virtual void draw(const ShaderProgram& shaderProgram) const = 0;
    protected:
        VertexArray vertexArray;
        VertexBuffer vertexBuffer;
        IndexBuffer indexBuffer;

        std::span<float> vertexPointers;
        std::span<unsigned int> indexPointers;
};