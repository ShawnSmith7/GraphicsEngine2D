#include "pch.h"
#include "Circle.h"

#include "GeometryManager.h"
#include "ShaderProgram.h"

Circle::Circle(const glm::vec2& pos, float radius, const glm::vec4& color, unsigned int resolution, float rotation, const glm::vec2& origin) :
    color(color), resolution(resolution) {
    setPos(pos);
    setRadius(radius);
    setRotation(rotation);
    setOrigin(origin);
}

glm::vec2 Circle::getPos() const {
    return transform.getTranslation();
}

float Circle::getRadius() const {
    return transform.getScaling().x;
}

glm::vec4 Circle::getColor() const {
    return color;
}

unsigned int Circle::getResolution() const {
    return resolution;
}

float Circle::getRotation() const {
    return transform.getRotation();
}

glm::vec2 Circle::getOrigin() const {
    return transform.getOrigin();
}

void Circle::setPos(const glm::vec2& pos) {
    transform.setTranslation(pos);
}

void Circle::setRadius(float radius) {
    transform.setScaling(glm::vec2(radius));
}

void Circle::setColor(const glm::vec4& color) {
    this->color = color;
}

void Circle::setResolution(unsigned int resolution) {
    this->resolution = resolution;
    geometryPtr = GeometryManager::get().getCircle(resolution);
}

void Circle::setRotation(float rotation) {
    transform.setRotation(rotation);
}

void Circle::setOrigin(const glm::vec2& origin) {
    transform.setOrigin(origin);
}

void Circle::draw(const ShaderProgram& shaderProgram) {
    if (geometryPtr == nullptr)
        geometryPtr = GeometryManager::get().getCircle(resolution);
    geometryPtr->vertexArray.bind();
    shaderProgram.setMat4("model", transform.getMatrix());
    shaderProgram.setVec4("color", color);
    glDrawElements(GL_TRIANGLE_FAN, geometryPtr->indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}