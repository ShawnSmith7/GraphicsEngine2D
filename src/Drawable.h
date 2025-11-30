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
        struct DontGenGeometry {};

        Transform transform;
};