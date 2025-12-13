#include "Polyline.h"

Polyline::Polyline(const std::vector<glm::vec2>& points, float width, const glm::vec4& color) :
    points(points), width(width), color(color), dirty(true) {
    vertexArray.gen();
    vertexBuffer.gen();
}

std::vector<glm::vec2> Polyline::getPoints() const {
    return points;
}

glm::vec2 Polyline::getPoint(size_t i) const {
    return points[i];
}

float Polyline::getWidth() const {
    return width;
}

glm::vec4 Polyline::getColor() const {
    return color;
}

glm::vec2 Polyline::getTranslation() const {
    return transform.getTranslation();
}

glm::vec2 Polyline::getScaling() const {
    return transform.getScaling();
}

float Polyline::getRotation() const {
    return transform.getRotation();
}

void Polyline::setPoints(const std::vector<glm::vec2>& points) {
    this->points = points;
    dirty = true;
}

void Polyline::setPoint(const glm::vec2& point, size_t i) {
    points[i] = point;
    dirty = true;
}

void Polyline::setWidth(float width) {
    this->width = width;
}

void Polyline::setColor(const glm::vec4& color) {
    this->color = color;
}

void Polyline::setTranslation(const glm::vec2& translation) {
    transform.setTranslation(translation);
}

void Polyline::setScaling(const glm::vec2& scaling) {
    transform.setScaling(scaling);
}

void Polyline::setRotation(float rotation) {
    transform.setRotation(rotation);
}

void Polyline::addPoint(const glm::vec2& point) {
    points.push_back(point);
}

void Polyline::addPoint(const glm::vec2& point, size_t i) {
    points.insert(points.begin() + i, point);
}

void Polyline::removePoint(size_t i) {
    points.erase(points.begin() + i);
}

void Polyline::draw(const ShaderProgram& shaderProgram) {
    if (dirty)
        updateGeometry();
    vertexArray.bind();
    shaderProgram.setMat4("model", transform.getMatrix());
    shaderProgram.setVec4("color", color);
    glLineWidth(width);
    glDrawArrays(GL_LINE_STRIP, 0, points.size());
    glLineWidth(1.0f);
}

void Polyline::updateGeometry() {
    vertexArray.bind();

    std::vector<float> vertices(2 * points.size());
    for (unsigned int i = 0; i < points.size(); i++) {
        vertices[2 * i] = points[i].x;
        vertices[2 * i + 1] = points[i].y;
    }

    vertexBuffer.bind();
    vertexBuffer.setData(vertices, GL_STATIC_DRAW);
    
    vertexArray.enableAttribute(0);
    vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

    vertexArray.unbind();
    
    dirty = false;
}