#pragma once

#include "Drawable.h"

#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <iosfwd>

#include "VertexArray.h"
#include "VertexBuffer.h"

class ShaderProgram;

class Polyline : public Drawable {
    public:
        Polyline(const std::vector<glm::vec2>& points,
            float width = 1.0f,
            const glm::vec4& color = glm::vec4(1.0f));    
        
        std::vector<glm::vec2> getPoints() const;
        glm::vec2 getPoint(size_t i) const;
        float getWidth() const;
        glm::vec4 getColor() const;
        glm::vec2 getTranslation() const;
        glm::vec2 getScaling() const;
        float getRotation() const;

        void setPoints(const std::vector<glm::vec2>& points);
        void setPoint(const glm::vec2& point, size_t i);
        void setWidth(float width);
        void setColor(const glm::vec4& color);
        void setTranslation(const glm::vec2& translation);
        void setScaling(const glm::vec2& scaling);
        void setRotation(float rotation);

        void addPoint(const glm::vec2& point);
        void addPoint(const glm::vec2& point, size_t i);
        void removePoint(size_t i);

        void draw(const ShaderProgram& shaderProgram) override;
    protected:
        std::vector<glm::vec2> points;
        float width;
        glm::vec4 color;
    private:
        VertexArray vertexArray;
        VertexBuffer vertexBuffer;
        
        bool initialized, dirty;
        void updateGeometry();
        void initializeGeometry();

        friend std::ostream& operator<<(std::ostream& os, const Polyline& polyline);
};

std::ostream& operator<<(std::ostream& os, const Polyline& polyline);