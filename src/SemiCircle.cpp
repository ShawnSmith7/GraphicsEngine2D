#include "SemiCircle.h"

SemiCircle::SemiCircle(const glm::vec2& pos, float radius, const glm::vec4& color, float arc, unsigned int resolution, float rotation, const glm::vec2& origin) :
    Circle(pos, radius, color, resolution, rotation, origin), arc(arc) {}

float SemiCircle::getArc() const {
    return arc;
}

void SemiCircle::setArc(float arc) {
    this->arc = arc;
}

void SemiCircle::draw(const ShaderProgram& shaderProgram) {
    geometryPtr->vertexArray.bind();
    shaderProgram.setMat4("model", transform.getMatrix());
    shaderProgram.setVec4("color", color);
    glDrawArrays(GL_TRIANGLE_FAN, 0, resolution + 2);
}

void SemiCircle::genGeometry() {
    // vertices.resize(2 * (resolution + 2));
    // vertices[0] = 0.0f;
    // vertices[1] = 0.0f;
    // float stride = arc / resolution;
    // for (unsigned int i = 0; i <= resolution; i++) {
    //     float angle = i * stride;
    //     vertices[2 + 2 * i] = cos(angle);
    //     vertices[3 + 2 * i] = sin(angle);
    // }

    geometryPtr->vertexArray.bind();

    geometryPtr->vertexBuffer.bind();
    //geometryPtr->vertexBuffer.setData(vertices, GL_STATIC_DRAW);
    
    geometryPtr->vertexArray.enableAttribute(0);
    geometryPtr->vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

    geometryPtr->vertexArray.unbind();
}