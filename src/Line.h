#pragma once

#include "Drawable.h"

class Line : public Drawable {
    public:
        enum class Type { Default, Rect, Round };

        Line(const glm::vec2& pos1 = glm::vec2(0.0f),
            const glm::vec2& pos2 = glm::vec2(0.0f, 1.0f),
            float width = 1,
            const glm::vec4& color = glm::vec4(1.0f),
            Type type = Type::Default);

        void draw(const ShaderProgram& shaderProgram) override;
    private:
        VertexArray vertexArray;
        VertexBuffer vertexBuffer;
        IndexBuffer indexBuffer;

        glm::vec2 pos1, pos2;
        float width;
        glm::vec4 color;
        Type type;

        float vertices[4];
};