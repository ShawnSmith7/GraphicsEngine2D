#pragma once

#include "Circle.h"

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <numbers>
#include <memory>
#include <iosfwd>

class ShaderProgram;

class SemiCircle : public Circle {
    public:
        SemiCircle(const glm::vec2& pos = glm::vec2(0.0f),
            float radius = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f),
            float arc = std::numbers::pi,
            unsigned int resolution = 64,
            float rotation = 0.0f,
            const glm::vec2& origin = glm::vec2(0.0f));

        float getArc() const;

        void setArc(float arc);

        void draw(const ShaderProgram& shaderProgram) override;
    private:
        float arc;

        std::shared_ptr<Geometry> geometryPtr;
};

std::ostream& operator<<(std::ostream& os, const SemiCircle& semiCircle);