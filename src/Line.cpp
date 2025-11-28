#include "Line.h"

Line::Line(const glm::vec2& pos1, const glm::vec2& pos2, float width, const glm::vec4& color) :
    pos2(pos2), width(width), color(color) {
    updateTransform(pos1, pos2);
    
    static bool initialized = false;
    if (!initialized) {
        initialized = true;
        vertexArray.gen();
        vertexArray.bind();

        vertexBuffer.gen();
        vertexBuffer.bind();
        vertexBuffer.setData(vertices, GL_STATIC_DRAW);

        vertexArray.enableAttribute(0);
        vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

        vertexArray.unbind();
    }
}

glm::vec2 Line::getPos1() const {
    return transform.getTranslation();
}

glm::vec2 Line::getPos2() const {
    return pos2;
}

float Line::getWidth() const {
    return width;
}

glm::vec4 Line::getColor() const {
    return color;
}

void Line::setPos1(const glm::vec2& pos1) {
    updateTransform(pos1, pos2);
}

void Line::setPos2(const glm::vec2& pos2) {
    this->pos2 = pos2;
    updateTransform(getPos1(), pos2);
}

void Line::setWidth(float width) {
    this->width = width;
}

void Line::setColor(const glm::vec4& color) {
    this->color = color;
}

void Line::draw(const ShaderProgram& shaderProgram) {
    vertexArray.bind();
    shaderProgram.setMat4("model", transform.getMatrix());
    shaderProgram.setVec4("color", color);
    glLineWidth(width);
    glDrawArrays(GL_LINES, 0, 2);
    glLineWidth(1.0f);
}

Line::Line(const glm::vec2& pos2, float width, const glm::vec4& color) :
    pos2(pos2), width(width), color(color) {
}

VertexArray Line::vertexArray;
VertexBuffer Line::vertexBuffer;

const float Line::vertices[] = { 0.0f, 0.0f, 1.0f, 0.0f };

void Line::updateTransform(const glm::vec2& pos1, const glm::vec2& pos2) {
    transform.setTranslation(pos1);
    transform.setScaling(glm::vec2(glm::length(pos2 - pos1), 1.0f));
    transform.setRotation(atan2(pos2.y - pos1.y, pos2.x - pos1.x));
}