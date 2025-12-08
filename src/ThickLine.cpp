#include "ThickLine.h"

ThickLine::ThickLine(const glm::vec2& pos1, const glm::vec2& pos2, float width, const glm::vec4& color, Type type) :
    Line(pos1, pos2, width, color, DontGenGeometry{}),
    type(type),
    rect(transform, color) {
    rect.setOrigin(rect.getOrigin() + glm::vec2(-0.5f, 0.0f));
    startCap = SemiCircle(pos1, width / 2.0f, color, std::numbers::pi, 32, getRotation() + 0.5f * std::numbers::pi);
    endCap = SemiCircle(pos2, width / 2.0f, color, std::numbers::pi, 32, getRotation() + 1.5f * std::numbers::pi);
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
    if (type == Type::Round) {
        startCap.draw(shaderProgram);
        endCap.draw(shaderProgram);
    }
}