#include "pch.h"
#include "SemiCircle.h"

#include "GeometryManager.h"
#include "ShaderProgram.h"

SemiCircle::SemiCircle(const glm::vec2& pos, float radius, const glm::vec4& color, float arc, unsigned int resolution, float rotation, const glm::vec2& origin) :
    Circle(pos, radius, color, resolution, rotation, origin), arc(arc) {}

float SemiCircle::getArc() const {
    return arc;
}

void SemiCircle::setArc(float arc) {
    this->arc = arc;
    geometryPtr = GeometryManager::get().getSemiCircle(resolution, arc);
}

void SemiCircle::draw(const ShaderProgram& shaderProgram) {
    if (geometryPtr == nullptr)
        geometryPtr = GeometryManager::get().getSemiCircle(resolution, arc);
    geometryPtr->vertexArray.bind();
    shaderProgram.setMat4("model", transform.getMatrix());
    shaderProgram.setVec4("color", color);
    glDrawArrays(GL_TRIANGLE_FAN, 0, resolution + 2);
}

std::ostream& operator<<(std::ostream& os, const SemiCircle& semiCircle) {
    return os
        << "{ pos = " << glm::to_string(semiCircle.getPos())
        << ", radius = " << semiCircle.getRadius()
        << ", color = " << glm::to_string(semiCircle.getColor())
        << ", arc = " << semiCircle.getArc()
        << ", resolution = " << semiCircle.getResolution()
        << ", rotation = " << semiCircle.getRotation()
        << ", origin = " << glm::to_string(semiCircle.getOrigin()) << " }";
}