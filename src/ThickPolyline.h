#pragma once

#include "Polyline.h"
#include "ThickLine.h"

class ThickPolyline : public Polyline {
    public:
        ThickPolyline(const std::vector<glm::vec2>& points,
            float width = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f));

        void draw(const ShaderProgram& shaderProgram);
    private:
        ThickLine segment;
};