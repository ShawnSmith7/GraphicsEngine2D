#include "Rect.h"

Rect::Rect(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color, float rotation, const glm::vec2& origin) :
    color(color) {
    setPos(pos);
    setSize(size);
    setRotation(rotation);
    setOrigin(origin);
}

Rect::Rect(const Transform& transform, const glm::vec4& color) :
    color(color) {
    this->transform = transform;
}

glm::vec2 Rect::getPos() const {
    return transform.getTranslation();
}

glm::vec2 Rect::getSize() const {
    return transform.getScaling();
}

glm::vec4 Rect::getColor() const {
    return color;
}

float Rect::getRotation() const {
    return transform.getRotation();
}

glm::vec2 Rect::getOrigin() const {
    return transform.getOrigin();
}

void Rect::setPos(const glm::vec2& pos) {
    transform.setTranslation(pos);
}

void Rect::setSize(const glm::vec2& size) {
    transform.setScaling(size);
}

void Rect::setColor(const glm::vec4& color) {
    this->color = color;
}

void Rect::setRotation(float rotation) {
    transform.setRotation(rotation);
}

void Rect::setOrigin(const glm::vec2& origin) {
    transform.setOrigin(origin);
}

void Rect::draw(const ShaderProgram& shaderProgram) {
    if (geometryPtr == nullptr)
        geometryPtr = GeometryManager::get().getRect();
    geometryPtr->vertexArray.bind();
    shaderProgram.setMat4("model", transform.getMatrix());
    shaderProgram.setVec4("color", color);
    glDrawElements(GL_TRIANGLES, geometryPtr->indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}

std::ostream& operator<<(std::ostream& os, const Rect& rect) {
    return os
        << "{ pos = " << glm::to_string(rect.getPos())
        << ", size = " << glm::to_string(rect.getSize())
        << ", color = " << glm::to_string(rect.getColor())
        << ", rotation = " << rect.getRotation()
        << ", origin = " << glm::to_string(rect.getOrigin()) << " }";
}