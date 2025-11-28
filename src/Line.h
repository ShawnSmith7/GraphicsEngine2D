#pragma once

#include "Drawable.h"

class Line : public Drawable {
    public:
        Line(const glm::vec2& pos1 = glm::vec2(0.0f),
            const glm::vec2& pos2 = glm::vec2(0.0f, 1.0f),
            float width = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f));

        void draw(const ShaderProgram& shaderProgram) override;
    protected:
        Line(const glm::vec2& pos2 = glm::vec2(0.0f, 1.0f),
            float width = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f));
    
        glm::vec2 pos2;
        float width;
        glm::vec4 color;
    private:
        static VertexArray vertexArray;
        static VertexBuffer vertexBuffer;

        static const float vertices[4];
};