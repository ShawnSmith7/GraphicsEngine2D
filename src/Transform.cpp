#include "pch.h"
#include "Transform.h"

Transform::Transform(const glm::vec2& translation, const glm::vec2& scaling, float rotation, const glm::vec2& origin) :
    translation(translation), scaling(scaling), rotation(rotation), origin(origin), dirty(true) {}

glm::vec2 Transform::getTranslation() const {
    return translation;
}

glm::vec2 Transform::getScaling() const {
    return scaling;
}

float Transform::getRotation() const {
    return rotation;
}

glm::vec2 Transform::getOrigin() const {
    return origin;
}

glm::mat4 Transform::getMatrix() {
    if (dirty)
        updateMatrix();
    return matrix;
}

void Transform::setTranslation(const glm::vec2& translation) {
    this->translation = translation;
    dirty = true;
}

void Transform::setScaling(const glm::vec2& scaling) {
    this->scaling = scaling;
    dirty = true;
}

void Transform::setRotation(float rotation) {
    this->rotation = rotation;
    dirty = true;
}

void Transform::setOrigin(const glm::vec2& origin) {
    this->origin = origin;
    dirty = true;
}

void Transform::updateMatrix() {
    glm::mat4 m(1.0f);

    m = glm::translate(m, glm::vec3(translation, 0.0f));
    m = glm::translate(m, glm::vec3(origin, 0.0f));
    m = glm::rotate(m, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    m = glm::scale(m, glm::vec3(scaling, 1.0f));
    m = glm::translate(m, glm::vec3(-origin, 0.0f));

    matrix = m;
    dirty = false;
}

std::ostream& operator<<(std::ostream& os, const Transform& transform) {
    return os 
        << "{ translation = " << glm::to_string(transform.getTranslation()) 
        << ", scaling = " << glm::to_string(transform.getScaling())
        << ", rotation = " << transform.getRotation()
        << ", origin = " << glm::to_string(transform.getOrigin())
        << ", matrix = " << glm::to_string(transform.matrix)
        << ", dirty = " << transform.dirty << " }";
}