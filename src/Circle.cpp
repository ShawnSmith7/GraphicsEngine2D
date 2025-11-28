#include "Circle.h"

Circle::Circle(const glm::vec2& pos, float radius, const glm::vec4& color, unsigned int resolution) :
    color(color), resolution(resolution) {
    setPos(pos);
    setRadius(radius);
    
    genGeometry();
}

glm::vec2 Circle::getPos() const {
    return transform.getTranslation();
}

float Circle::getRadius() const {
    return transform.getScaling().x;
}

glm::vec4 Circle::getColor() const {
    return color;
}

unsigned int Circle::getResolution() const {
    return resolution;
}

void Circle::setPos(const glm::vec2& pos) {
    transform.setTranslation(pos);
}

void Circle::setRadius(float radius) {
    transform.setScaling(glm::vec2(radius));
}

void Circle::setColor(const glm::vec4& color) {
    this->color = color;
}

void Circle::setResolution(unsigned int resolution) {
    this->resolution = resolution;
    genGeometry();
}

void Circle::draw(const ShaderProgram& shaderProgram) {
    vertexArray.bind();
    shaderProgram.setMat4("model", transform.getMatrix());
    shaderProgram.setVec4("color", color);
    glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}

void Circle::genGeometry() {
    vertexArray.gen();
    vertexArray.bind();

    vertices.resize(2 * (resolution + 1));

    vertices[0] = 0.0f;
    vertices[1] = 0.0f;
    float stride = 2.0f * std::numbers::pi / resolution;
    for (unsigned int i = 0; i < resolution; i++) {
        float angle = i * stride;
        vertices[2 + 2 * i] = cos(angle);
        vertices[3 + 2 * i] = sin(angle);
    }

    vertexBuffer.gen();
    vertexBuffer.bind();
    vertexBuffer.setData(vertices, GL_STATIC_DRAW);

    indices.resize(3 * resolution);

    for (unsigned int i = 0; i < resolution; i++) {
        indices[3 * i] = 0;
        indices[3 * i + 1] = i + 1;
        indices[3 * i + 2] = (i + 1) % resolution + 1;
    }

    indexBuffer.gen();
    indexBuffer.bind();
    indexBuffer.setData(indices, GL_STATIC_DRAW);
    
    vertexArray.enableAttribute(0);
    vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

    vertexArray.unbind();
}