#include "Circle.h"

Circle::Circle(const glm::vec2& pos, float radius, const glm::vec4& color, unsigned int resolution) :
    pos(pos), radius(radius), color(color), resolution(resolution) {
    vertexArray.bind();

    vertices.resize(2 * (resolution + 1));
    vertexPointers = vertices;

    vertices[0] = pos.x;
    vertices[1] = pos.y;
    float stride = 2.0f * std::numbers::pi / resolution;
    for (unsigned int i = 0; i < resolution; i++) {
        float angle = i * stride;
        vertices[2 + 2 * i] = radius * cos(i * stride) + pos.x;
        vertices[3 + 2 * i] = radius * sin(i * stride) + pos.y;
    }

    vertexBuffer.bind();
    vertexBuffer.setData(vertices, GL_STATIC_DRAW);

    indices.resize(3 * resolution);

    for (unsigned int i = 0; i < resolution; i++) {
        indices[3 * i] = 0;
        indices[3 * i + 1] = i + 1;
        indices[3 * i + 2] = (i + 1) % resolution + 1;
    }

    indexBuffer.bind();
    indexBuffer.setData(indices, GL_STATIC_DRAW);
    
    vertexArray.enableAttribute(0);
    vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

    vertexArray.unbind();
}

void Circle::draw(const ShaderProgram& shaderProgram) const {
    vertexArray.bind();
    shaderProgram.setVec4("color", color);
    glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}