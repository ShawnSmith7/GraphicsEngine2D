#include "ThickPolyline.h"

ThickPolyline::ThickPolyline(const std::vector<glm::vec2>& points, float width, const glm::vec4& color) :
    Polyline(points, width, color), segment(points[0], points[1], 20, color) {
    segment.setWidth(width);
    segment.setColor(color);
}

void ThickPolyline::draw(const ShaderProgram& shaderProgram) {
    for (unsigned int i = 0; i < points.size() - 1; i++) {
        segment.setPos1(points[i]);
        segment.setPos2(points[i + 1]);
        segment.draw(shaderProgram);
    }
}