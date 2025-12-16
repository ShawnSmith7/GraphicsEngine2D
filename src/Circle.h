#pragma once

#include "Drawable.h"

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

#include <memory>
#include <iosfwd>

#include "Geometry.h"

class ShaderProgram;

class Circle : public Drawable {
    public:
        Circle(const glm::vec2& pos = glm::vec2(0.0f),
            float radius = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f),
            unsigned int resolution = 64,
            float rotation = 0.0f,
            const glm::vec2& origin = glm::vec2(0.0f));

        glm::vec2 getPos() const;
        float getRadius() const;
        glm::vec4 getColor() const;
        unsigned int getResolution() const;
        float getRotation() const;
        glm::vec2 getOrigin() const;

        void setPos(const glm::vec2& pos);
        void setRadius(float radius);
        void setColor(const glm::vec4& color);
        void setResolution(unsigned int resolution);
        void setRotation(float rotation);
        void setOrigin(const glm::vec2& origin);

        void draw(const ShaderProgram& shaderProgram) override;
    protected:
        glm::vec4 color;
        unsigned int resolution;
    private:
        std::shared_ptr<IndexedGeometry> geometryPtr;
};