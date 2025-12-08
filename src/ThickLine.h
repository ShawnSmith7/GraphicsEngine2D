#pragma once

#include "Line.h"
#include "Rect.h"
#include "SemiCircle.h"

class ThickLine : public Line {
    public:
        enum class Type { Default, Round };
    
        ThickLine(const glm::vec2& pos1 = glm::vec2(0.0f),
            const glm::vec2& pos2 = glm::vec2(0.0f, 1.0f),
            float width = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f), Type type = Type::Default);

        Type getType() const;

        void setType(Type type);

        void draw(const ShaderProgram& shaderProgram) override;
    private:
        Type type;

        Rect rect;
        SemiCircle startCap, endCap;
};