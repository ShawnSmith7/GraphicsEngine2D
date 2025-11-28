#include "ThickLine.h"

ThickLine::ThickLine(const glm::vec2& pos1, const glm::vec2& pos2, float width, const glm::vec4& color, Type type) :
    Line(pos2, width, color), type(type), rect(pos1, pos2, color) {
    
}

void ThickLine::draw(const ShaderProgram& shaderProgram) {
    rect.draw(shaderProgram);
}