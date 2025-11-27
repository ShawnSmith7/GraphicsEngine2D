#include "Transform.h"

Transform::Transform(const glm::vec2& pos, const glm::vec2& size, float rotation) :
    pos(pos), size(size), rotation(rotation), dirty(true) {}

void Transform::setPos(const glm::vec2& pos) {
    this->pos = pos;
    dirty = true;
}

void Transform::setSize(const glm::vec2& size) {
    this->size = size;
    dirty = true;
}

void Transform::setRotation(float rotation) {
    this->rotation = rotation;
    dirty = true;
}

glm::mat4 Transform::getMatrix() {
    if (dirty)
        updateMatrix();
    return matrix;
}

void Transform::updateMatrix() {
    glm::mat4 m(1.0f);

    m = glm::translate(m, glm::vec3(pos, 0.0f));
    m = glm::rotate(m, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    m = glm::scale(m, glm::vec3(size, 1.0f));

    matrix = m;
    dirty = false;
}