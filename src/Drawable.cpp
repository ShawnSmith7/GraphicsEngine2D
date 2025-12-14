#include "Drawable.h"

Transform Drawable::getTransform() const {
    return transform;
}

void Drawable::setTransform(const Transform& transform) {
    this->transform = transform;
}