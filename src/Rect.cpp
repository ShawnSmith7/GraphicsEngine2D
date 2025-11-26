#include "Rect.h"

Rect::Rect(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color) :
    color(color) {
    transform.setPos(pos);
    transform.setSize(size);

    vertexArray.bind();

    vertexBuffer.bind();
    vertexBuffer.setData(vertices, GL_STATIC_DRAW);

    indexBuffer.bind();
    indexBuffer.setData(indices, GL_STATIC_DRAW);

    vertexArray.enableAttribute(0);
    vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

    vertexArray.unbind();
}

void Rect::draw(const ShaderProgram& shaderProgram) {
    vertexArray.bind();
    shaderProgram.setMat4("model", transform.getMatrix());
    shaderProgram.setVec4("color", color);
    glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}

const float Rect::vertices[] = {
    -0.5f, 0.5f,
    -0.5f, -0.5f,
    0.5f, -0.5f,
    0.5f, 0.5f
};

const unsigned int Rect::indices[] = { 0, 1, 2, 2, 3, 0 };