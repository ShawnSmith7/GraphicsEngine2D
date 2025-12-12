#pragma once

#include "Drawable.h"
#include "GeometryManager.h"

class Rect : public Drawable {
    public:
        Rect(const glm::vec2& pos = glm::vec2(0.0f), 
            const glm::vec2& size = glm::vec2(1.0f), 
            const glm::vec4& color = glm::vec4(1.0f),
            float rotation = 0.0f,
            const glm::vec2& origin = glm::vec2(0.0f));

        Rect(const Transform& transform, const glm::vec4& color);

        glm::vec2 getPos() const;
        glm::vec2 getSize() const;
        glm::vec4 getColor() const;
        float getRotation() const;
        glm::vec2 getOrigin() const;

        void setPos(const glm::vec2& pos);
        void setSize(const glm::vec2& size);
        void setColor(const glm::vec4& color);
        void setRotation(float rotation);
        void setOrigin(const glm::vec2& origin);

        void draw(const ShaderProgram& shaderProgram) override;
    private:
        static IndexBuffer indexBuffer;
    
        glm::vec4 color;

        static const unsigned int indices[6];

        //void genGeometry() const;

        std::shared_ptr<Geometry> geometryPtr;
};