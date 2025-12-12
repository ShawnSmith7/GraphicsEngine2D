#include "Line.h"

Line::Line(const glm::vec2& pos1, const glm::vec2& pos2, float width, const glm::vec4& color) :
    pos2(pos2), color(color) {
    setPos1(pos1);
    setWidth(width);
}

Line::Line(const glm::vec2& pos1, float length, float width, float rotation, const glm::vec4& color) :
    pos2(findPos2(pos1, length, rotation)), color(color) {
    setPos1(pos1);
    setWidth(width);
}

glm::vec2 Line::getPos1() const {
    return transform.getTranslation();
}

glm::vec2 Line::getPos2() const {
    return pos2;
}

float Line::getWidth() const {
    return transform.getScaling().y;
}

glm::vec4 Line::getColor() const {
    return color;
}

float Line::getLength() const {
    return transform.getScaling().x;
}

float Line::getRotation() const {
    return transform.getRotation();
}

void Line::setPos1(const glm::vec2& pos1) {
    transform.setTranslation(pos1);
    transform.setScaling(glm::vec2(glm::length(pos2 - pos1), 1.0f));
    glm::vec2 diff = pos2 - pos1;
    transform.setRotation(atan2(diff.y, diff.x));
}

void Line::setPos2(const glm::vec2& pos2) {
    this->pos2 = pos2;
    transform.setScaling(glm::vec2(glm::length(pos2 - getPos1()), 1.0f));
    glm::vec2 diff = pos2 - getPos1();
    transform.setRotation(atan2(diff.y, diff.x));
}

void Line::setWidth(float width) {
    transform.setScaling(glm::vec2(getLength(), width));
}

void Line::setColor(const glm::vec4& color) {
    this->color = color;
}

void Line::setLength(float length) {
    transform.setScaling(glm::vec2(length, getWidth()));
    this->pos2 = findPos2(getPos1(), length, getRotation());
}

void Line::setRotation(float rotation) {
    transform.setRotation(rotation);
    this->pos2 = findPos2(getPos1(), getLength(), rotation);
}

void Line::draw(const ShaderProgram& shaderProgram) {
    if (geometryPtr == nullptr)
        geometryPtr = GeometryManager::get().getLine();
    geometryPtr->vertexArray.bind();
    shaderProgram.setMat4("model", transform.getMatrix());
    shaderProgram.setVec4("color", color);
    glLineWidth(getWidth());
    glDrawArrays(GL_LINES, 0, 2);
    glLineWidth(1.0f);
}

glm::vec2 Line::findPos2(const glm::vec2& pos1, float length, float rotation) {
    return pos1 + length * glm::vec2(cos(rotation), sin(rotation));
}