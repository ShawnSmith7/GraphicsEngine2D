#pragma once

#include "Line.h"
#include "Rect.h"

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

class ShaderProgram;

class ThickLine : public Line {
    public:
        enum class Type { Butt, Square, Round };

        ThickLine(const glm::vec2& pos1 = glm::vec2(0.0f),
            const glm::vec2& pos2 = glm::vec2(0.0f, 1.0f),
            float width = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f),
            const Type& cap = Type::Butt);

        ThickLine(const glm::vec2& pos1, float length, float width, float rotation, const glm::vec4& color, const Type& cap);
        
        void draw(const ShaderProgram& shaderProgram) override;
    private:
        Type startCap, endCap;
        Rect rect;
};