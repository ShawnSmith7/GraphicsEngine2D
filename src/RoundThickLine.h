#pragma once

#include "ThickLine.h"
#include "SemiCircle.h"

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

class ShaderProgram;

class RoundThickLine : public ThickLine {
    public:
        RoundThickLine(const glm::vec2& pos1 = glm::vec2(0.0f),
            const glm::vec2& pos2 = glm::vec2(0.0f, 1.0f),
            float width = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f),
            float resolution0 = 64,
            float resolution1 = 64);

        float getResolution0() const;
        float getResolution1() const;

        void setResolution0(float resolution0);
        void setResolution1(float resolution1);

        void draw(const ShaderProgram& shaderProgram) override;
    private:
        SemiCircle cap0, cap1;
};