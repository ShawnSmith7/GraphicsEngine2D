#pragma once

#include "Circle.h"

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