#include "Line.h"

Line::Line(const glm::vec2& pos1, const glm::vec2& pos2, float width, const glm::vec4& color) :
    pos2(pos2), width(width), color(color) {
    transform.setTranslation(pos1);
    transform.setScaling(glm::vec2(glm::length(pos2 - pos1), 1.0f));
    transform.setRotation(atan2(pos2.y - pos1.y, pos2.x - pos1.x));
    
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