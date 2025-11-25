#include "Rect.h"

Rect::Rect(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color) :
    pos(pos), size(size), color(color) {
    vertexArray.bind();

    vertices[0] = pos.x;
    vertices[1] = pos.y;
    vertices[2] = pos.x;
    vertices[3] = pos.y + size.y;
    vertices[4] = pos.x + size.x;
    vertices[5] = pos.y + size.y;
    vertices[6] = pos.x + size.y;
    vertices[7] = pos.y;

    vertexBuffer.bind();
    vertexBuffer.setData(vertices, GL_STATIC_DRAW);

    indexBuffer.bind();
    indexBuffer.setData(indices, GL_STATIC_DRAW);

    vertexArray.enableAttribute(0);
    vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

    vertexPointers = vertices;
    indexPointers = indices;
}

void Rect::draw(const ShaderProgram& shaderProgram) const {
    shaderProgram.setVec4("color", color);
    glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}

unsigned int Rect::indices[] = { 0, 1, 2, 2, 3, 0 };