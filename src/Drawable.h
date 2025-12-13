#pragma once

#include "ShaderProgram.h"
#include "Transform.h"

class Drawable {
    public:
        virtual void draw(const ShaderProgram& shaderProgram) = 0;
    protected:
        Transform transform;
};