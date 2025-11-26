#pragma once

#include "Drawable.h"

#include <numbers>

class Circle : public Drawable {
    public:
        Circle(const glm::vec2& pos = glm::vec2(0.0f),
            float radius = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f),
            unsigned int resolution = 64);

        void draw(const ShaderProgram& shaderProgram) override;
    private:
        glm::vec2 pos;
        float radius;
        glm::vec4 color;
        unsigned int resolution;

        std::vector<float> vertices;
        std::vector<unsigned int> indices;
};