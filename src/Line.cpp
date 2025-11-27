#include "Line.h"

Line::Line(const glm::vec2& pos1, const glm::vec2& pos2, float width, const glm::vec4& color, Type type) :
    pos1(pos1), pos2(pos2), width(width), color(color), type(type) {
    vertexArray.bind();

    vertices[0] = pos1.x;
    vertices[1] = pos1.y;
    vertices[2] = pos2.x;
    vertices[3] = pos2.y;
    
    vertexBuffer.bind();
    vertexBuffer.setData(vertices, GL_STATIC_DRAW);

    vertexArray.enableAttribute(0);
    vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

    vertexArray.unbind();
}

void Line::draw(const ShaderProgram& shaderProgram) {
    vertexArray.bind();
    shaderProgram.setVec4("color", color);
    glLineWidth(width);
    glDrawArrays(GL_LINES, 0, 4);
    glLineWidth(1.0f);
}