#include "pch.h"
#include "Drawable.h"

#include "ShaderProgram.h"

Transform Drawable::getTransform() const {
    return transform;
}

void Drawable::setTransform(const Transform& transform) {
    this->transform = transform;
}

std::ostream& operator<<(std::ostream& os, const Drawable& drawable) {
    return os << "{ transform = " << drawable.getTransform() << " }";
}