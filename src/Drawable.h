#pragma once

#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Transform.h"

class Drawable {
    public:
        virtual void draw(const ShaderProgram& shaderProgram) = 0;
    protected:
        Transform transform;
};

class StaticDrawable : public Drawable {
    protected:
        static VertexArray vertexArray;
        static VertexBuffer vertexBuffer;
        static IndexBuffer indexBuffer;
};

class DynamicDrawable : public Drawable {
    protected:
        VertexArray vertexArray;
        VertexBuffer vertexBuffer;
        IndexBuffer indexBuffer;
};