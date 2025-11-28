#include "Rect.h"

Rect::Rect(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color, float rotation, const glm::vec2& origin) :
    color(color) {
    setPos(pos);
    setSize(size);
    setRotation(rotation);
    setOrigin(origin);

    static bool initialized = false;
    if (!initialized) {
        initialized = true;

        vertexArray.gen();
        vertexArray.bind();

        vertexBuffer.gen();
        vertexBuffer.bind();
        vertexBuffer.setData(vertices, GL_STATIC_DRAW);

        indexBuffer.gen();
        indexBuffer.bind();
        indexBuffer.setData(indices, GL_STATIC_DRAW);

        vertexArray.enableAttribute(0);
        vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

        vertexArray.unbind();
    }
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
    vertexArray.bind();
    shaderProgram.setMat4("model", transform.getMatrix());
    shaderProgram.setVec4("color", color);
    glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}

VertexArray Rect::vertexArray;
VertexBuffer Rect::vertexBuffer;
IndexBuffer Rect::indexBuffer;

const float Rect::vertices[] = {
    -0.5f, 0.5f,
    -0.5f, -0.5f,
    0.5f, -0.5f,
    0.5f, 0.5f
};

const unsigned int Rect::indices[] = { 0, 1, 2, 2, 3, 0 };