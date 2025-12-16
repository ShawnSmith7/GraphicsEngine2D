#pragma once

#include "Polyline.h"
#include "ThickLine.h"

#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

class ShaderProgram;

class ThickPolyline : public Polyline {
    public:
        ThickPolyline(const std::vector<glm::vec2>& points,
            float width = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f));

        void draw(const ShaderProgram& shaderProgram);
    private:
        ThickLine segment;
};