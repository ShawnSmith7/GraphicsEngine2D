#pragma once

#include "Drawable.h"

class Rect : public Drawable {
    public:
        Rect(const glm::vec2& pos = glm::vec2(0.0f), 
            const glm::vec2& size = glm::vec2(1.0f), 
            const glm::vec4& color = glm::vec4(1.0f));

        void draw(const ShaderProgram& shaderProgram) override;
    private:
        glm::vec4 color;

        static const float vertices[8];
        static const unsigned int indices[6];
};