#include "ThickLine.h"

ThickLine::ThickLine(const glm::vec2& pos1, const glm::vec2& pos2, float width, const glm::vec4& color) :
    Line(pos1, pos2, width, color),
    rect(transform, color) {
    rect.setPos(0.5f * (pos1 + pos2));
}

void ThickLine::draw(const ShaderProgram& shaderProgram) {
    rect.draw(shaderProgram);
}