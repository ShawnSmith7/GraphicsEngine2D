#pragma once

#include "Drawable.h"

class Line : public Drawable {
    public:
        Line(const glm::vec2& pos1 = glm::vec2(0.0f),
            const glm::vec2& pos2 = glm::vec2(0.0f, 1.0f),
            float width = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f));

        Line(const glm::vec2& pos1, float length, float width, float rotation, const glm::vec4& color);

        glm::vec2 getPos1() const;
        glm::vec2 getPos2() const;
        float getWidth() const;
        glm::vec4 getColor() const;
        float getLength() const;
        float getRotation() const;

        void setPos1(const glm::vec2& pos1);
        void setPos2(const glm::vec2& pos2);
        void setWidth(float width);
        void setColor(const glm::vec4& color);
        void setLength(float length);
        void setRotation(float rotation);

        void draw(const ShaderProgram& shaderProgram) override;
    protected:
        Line(const glm::vec2& pos1, const glm::vec2& pos2, float width, const glm::vec4& color, DontGenGeometry);

        glm::vec2 pos2;
        glm::vec4 color;

        static glm::vec2 findPos2(const glm::vec2& pos1, float length, float rotation);
    private:
        static VertexArray vertexArray;
        static VertexBuffer vertexBuffer;

        static const float vertices[4];

        void genGeometry() const;
};