#include "Rect.h"

Rect::Rect(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color) :
    pos(pos), size(size), color(color) {}

void Rect::draw(const ShaderProgram& shaderProgram) const {
    shaderProgram.setVec4("color", color);
    glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}