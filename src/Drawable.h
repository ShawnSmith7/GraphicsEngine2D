#pragma once

#include "ShaderProgram.h"
#include "Transform.h"

class Drawable {
    public:
        virtual void draw(const ShaderProgram& shaderProgram) = 0;

        Transform getTransform() const;
        void setTransform(const Transform& transform);
    protected:
        Transform transform;

};