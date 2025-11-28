#include "ThickLine.h"

ThickLine::ThickLine(const glm::vec2& pos1, const glm::vec2& pos2, float width, const glm::vec4& color, Type type) :
    Line(pos1, pos2, width, color, DontGenerateGeometry{}),
    type(type),
    rect(pos1, glm::vec2(glm::length(pos2 - pos1), width), color, atan2(pos2.y - pos1.y, pos2.x - pos1.x), glm::vec2(-0.5f, 0.0f)) {
    
}

ThickLine::Type ThickLine::getType() const {
    return type;
}

void ThickLine::setType(Type type) {
    this->type = type;
    // not done yet
    // this should change the geometry
}

void ThickLine::draw(const ShaderProgram& shaderProgram) {
    rect.draw(shaderProgram);
}